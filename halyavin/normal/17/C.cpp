#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

#include <array>

template<class T, int Dim>
class darray {
public:
  using element_t = typename darray<T, Dim - 1>::array_t;
  using array_t = element_t*;

  template<class... Args>
  darray(Args... args) :
      dims{size_t(args)...},
      p(init(size_t(args)...)) {
  }

  darray(darray<T, Dim>&& other) {
    free(p, dims.data());
    p = other.p;
    dims = other.dims;
    other.p = nullptr;
  }

  ~darray() {
    if (p) {
      free(p, dims.data());
    }
  }

  const std::array<size_t, Dim>& size() { return dims; };

  template<class... Args>
  static array_t init(size_t dim, Args... args) {
    array_t p = new element_t[dim];
    for (size_t i = 0; i < dim; i++) {
      p[i] = darray<T, Dim - 1>::init(args...);
    }
    return p;
  }

  static array_t free(array_t p, const size_t* dims) {
    for (size_t i = 0; i < dims[0]; i++) {
      darray<T, Dim - 1>::free(p[i], dims + 1);
    }
    delete[] p;
  }

  element_t operator[](size_t idx) {
    return p[idx];
  }

  const element_t operator[](size_t idx) const {
    return p[idx];
  }

  void copy(const darray<T, Dim>& other) {
    copy(p, dims.data(), other.p);
  }

  static void copy(array_t p, const size_t* dims, const array_t other_p) {
    for (size_t i = 0; i < dims[0]; i++) {
      darray<T, Dim - 1>::copy(p[i], dims + 1, other_p[i]);
    }
  }

  void fill(T value) {
    fill(p, dims.data(), value);
  }

  static void fill(array_t p, const size_t* dims, T value) {
    for (size_t i = 0; i < dims[0]; i++) {
      darray<T, Dim - 1>::fill(p[i], dims + 1, value);
    }
  }

private:
  const std::array<size_t, Dim> dims;
  array_t p;
};

template<class T>
class darray<T, 1> {
public:
  using element_t = T;
  using array_t = T*;

  darray(size_t dim) :
      dims{dim},
      p(init(dim)) {
  }

  darray(darray<T, 1>&& other) {
    free(p, dims.data());
    p = other.p;
    dims = other.dims;
    other.p = nullptr;
  }

  ~darray() {
    if (p) {
      free(p, dims.data());
    }
  }

  const std::array<size_t, 1>& size() { return dims; };

  static array_t init(size_t dim) {
    return new T[dim]();
  }

  static array_t free(array_t p, const size_t* /* dims */) {
    delete[] p;
  }

  T& operator[](size_t idx) {
    return p[idx];
  }

  const T& operator[](size_t idx) const {
    return p[idx];
  }

  void copy(const darray<T, 1>& other) {
    copy(p, dims.data(), other.p);
  }

  static void copy(array_t p, const size_t* dims, const array_t other_p) {
    std::copy_n(other_p, dims[0], p);
  }

  void fill(T value) {
    fill(p, dims.data(), value);
  }

  static void fill(array_t p, const size_t* dims, T value) {
    std::fill(p, p + dims[0], value);
  }

private:
  const std::array<size_t, 1> dims;
  array_t p;
};

const int p = 51123987;

void update(int& value, int add) {
  int t = value + add;
  if (t >= p) t -= p;
  value = t;
}

#include <chrono>

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  int max = n / 3 + 2;
  using arr2 = std::array<std::array<int, 53>, 53>;
  darray<arr2, 1> dyn(n + 1);
  darray<std::array<int, 3>, 1> next(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int k;
      for (k = i; k < n; k++) {
        if (s[k] == 'a' + j) {
          break;
        }
      }
      next[i][j] = k;
    }
  }
  dyn[0][0][0] = 1;
  __m128i pp = _mm_set1_epi32(p);
  for (int i = 1; i <= n; i++) {
    for (int pos = n - 1; pos >= 0; pos--) {
      std::array<int, 3> t = next[pos];
      arr2& from = dyn[pos];
      arr2& to0 = dyn[t[0]];
      arr2& to1 = dyn[t[1]];
      arr2& to2 = dyn[t[2]];
      for (int j = std::min(i, max); j-- > 0;) {
        int k = std::min(i - j, max);
        while (k >= 4) {
          __m128i tmp = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&from[j][k - 4]));
          _mm_storeu_si128(reinterpret_cast<__m128i*>(&from[j][k - 4]), _mm_setzero_si128());
          __m128i sum = _mm_add_epi32(tmp, _mm_loadu_si128(reinterpret_cast<const __m128i*>(&to0[j + 1][k - 4])));
          __m128i mask = _mm_cmplt_epi32(sum, pp);
          __m128i res = _mm_blendv_epi8(_mm_sub_epi32(sum, pp), sum, mask);
          _mm_storeu_si128(reinterpret_cast<__m128i*>(&to0[j + 1][k - 4]), res);

          sum = _mm_add_epi32(tmp, _mm_loadu_si128(reinterpret_cast<const __m128i*>(&to1[j][k - 3])));
          mask = _mm_cmplt_epi32(sum, pp);
          res = _mm_blendv_epi8(_mm_sub_epi32(sum, pp), sum, mask);
          _mm_storeu_si128(reinterpret_cast<__m128i*>(&to1[j][k - 3]), res);

          sum = _mm_add_epi32(tmp, _mm_loadu_si128(reinterpret_cast<const __m128i*>(&to2[j][k - 4])));
          mask = _mm_cmplt_epi32(sum, pp);
          res = _mm_blendv_epi8(_mm_sub_epi32(sum, pp), sum, mask);
          _mm_storeu_si128(reinterpret_cast<__m128i*>(&to2[j][k - 4]), res);
          k -= 4;
        }
        for (; k-- > 0;) {
          int tmp = from[j][k];
          from[j][k] = 0;
          update(to0[j + 1][k], tmp);
          update(to1[j][k + 1], tmp);
          update(to2[j][k], tmp);
        }
      }
    }
  }
  int res = 0;
  for (int a = n / 3; a <= n / 3 + 1; a++) {
    for (int b = n / 3; b <= n / 3 + 1; b++) {
      int c = n - a - b;
      if (c < n / 3 || c > n / 3 + 1) continue;
      for (int pos = 0; pos < n; pos++) {
        res += dyn[pos][a][b];
        if (res >= p) {
          res -= p;
        }
      }
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}