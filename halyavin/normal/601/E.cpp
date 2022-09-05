#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#define __SSE4_1__
//#define __SSSE3__
//#define __SSE3__
#endif
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <cstring>

#include <xmmintrin.h>
#include <smmintrin.h>

const int64_t p = 10000000 + 19;
const int64_t q = 1000000000 + 7;

int calcAnswer(const std::vector<int>& dyn) {
  int64_t res = 0;
  int64_t mult = 1;
  for (size_t i = 1; i < dyn.size(); i++) {
    res = (res + dyn[i] * mult) % q;
    mult = (mult * p) % q;
  }
  return res;
}

struct request {
  int type;
  int v;
  int w;
  int x;
};

struct Dyn {
  std::vector<int> dyn[2];
  int cur;
  Dyn(int size) : cur(0) {
    dyn[0].resize(size);
    dyn[1].resize(size);
  }
  Dyn(const Dyn& other) : cur(0){
    dyn[0] = other.get();
    dyn[1].resize(dyn[0].size());
  }

  void addVec(int w, int v) {
    std::vector<int>& from = dyn[cur];
    std::vector<int>& to = dyn[cur ^ 1];
    memcpy(to.data(), from.data(), sizeof(int)*std::min(size_t(w), from.size()));
    size_t i = size_t(w);
    __m128i vv = _mm_set1_epi32(v);
    for(;i + 4 <= from.size(); i += 4) {
      __m128i cur = _mm_loadu_si128(reinterpret_cast<__m128i*>(from.data() + i));
      __m128i before = _mm_loadu_si128(reinterpret_cast<__m128i*>(from.data() + i - w));
      __m128i next = _mm_max_epi32(cur, _mm_add_epi32(vv, before));
      _mm_storeu_si128(reinterpret_cast<__m128i*>(to.data() + i), next);
    }
    for (; i < from.size(); i++) {
      to[i] = std::max(from[i], from[i - w] + v);
    }
    cur = cur ^ 1;
  }
  const std::vector<int>& get() const {
    return dyn[cur];
  }
};

void addVec(std::vector<int>& dyn, int w, int v) {
  for (size_t i = w; i < dyn.size(); i++) {
    dyn[i] = std::max(dyn[i], dyn[i - w] + v);
  }
}

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<int> ws(n);
  std::vector<int> vs(n);
  for (int i = 0; i < n; i++) {
    in >> vs[i] >> ws[i];
  }
  int q;
  in >> q;
  ws.resize(n + q);
  vs.resize(n + q);
  std::vector<request> requests(q);
  int addCount = n;
  for (int i = 0; i < q; i++) {
    in >> requests[i].type;
    switch (requests[i].type) {
    case 1:
      in >> requests[i].v >> requests[i].w;
      requests[i].x = addCount;
      vs[addCount] = requests[i].v;
      ws[addCount] = requests[i].w;
      addCount++;
      break;
    case 2:
      in >> requests[i].x;
      requests[i].x--;
      break;
    default:
      break;
    }
  }
  ws.resize(addCount);
  vs.resize(addCount);
  std::vector<bool> flags(addCount);
  std::fill(flags.begin(), flags.begin() + n, true);
  int pos = 0;
  while (pos < q) {
    int added = std::count(flags.begin(), flags.end(), true);
    int deleted = 0;
    int end_pos;
    std::vector<int> dels;
    for (end_pos = pos; end_pos < q && 2 * deleted * deleted <= q; end_pos++) {
      if (requests[end_pos].type == 1) {
        added++;
      } else if (requests[end_pos].type == 2) {
        dels.push_back(requests[end_pos].x);
        deleted++;
      }
    }
//    std::cerr << pos << " " << end_pos << std::endl;
    //std::vector<int> dyn(k + 1);
    Dyn dyn(k + 1);
    for (size_t i = 0; i < flags.size(); i++) {
      if (flags[i] && std::find(dels.begin(), dels.end(), i) == dels.end()) {
        dyn.addVec(ws[i], vs[i]);
      }
    }
    for (int cur = pos; cur < end_pos; cur++) {
      if (requests[cur].type == 1) {
        int x = requests[cur].x;
        flags[x] = true;
        if (std::find(dels.begin(), dels.end(), x) == dels.end()) {
          dyn.addVec(ws[x], vs[x]);
        }
      } else if (requests[cur].type == 2) {
        flags[requests[cur].x] = false;
      } else {
        Dyn dyn2 = dyn;
        for (int d : dels) {
          if (flags[d]) {
            dyn2.addVec(ws[d], vs[d]);
          }
        }
//        for (size_t i = 0; i < dyn2.get().size(); i++) {
//          std::cerr << dyn2.get()[i] << " ";
//        }
//        std::cerr << std::endl << "---" << std::endl;
        out << calcAnswer(dyn2.get()) << std::endl;
      }
    }
    pos = end_pos;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}