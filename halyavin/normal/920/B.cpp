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
#include <queue>

void run(std::istream &in, std::ostream &out) {
    int tt;
    in >> tt;
    for (int test = 0; test < tt; test++) {
        int n;
        in >> n;
        std::vector<int> ls(n);
        std::vector<int> rs(n);
        for (int i = 0; i < n; i++) {
            in >> ls[i] >> rs[i];
        }
        std::queue<int> queue;
        std::vector<int> ans(n);
        int pos = 0;
        int t = 1;
        while (pos < n || !queue.empty()) {
            while (pos < n && ls[pos] == t) {
                queue.push(pos);
                pos++;
            }
            while (!queue.empty()) {
                int s = queue.front();
                queue.pop();
                if (t <= rs[s]) {
                    ans[s] = t;
                    break;
                }
            }
            t++;
        }
        for (int i = 0; i < n; i++) {
            out << ans[i] << " ";
        }
        out << std::endl;
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}