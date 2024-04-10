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
#include <stack>

const int inf = 1000;

void run(std::istream &in, std::ostream &out) {
    std::stack<int> speed;
    std::stack<bool> overtake;
    speed.push(inf);
    overtake.push(true);
    int n;
    in >> n;
    int res = 0;
    int curSpeed = 0;
    for (int i = 0; i < n; i++) {
        int t, s;
        in >> t;
        switch (t) {
            case 1:
                in >> s;
                while (speed.top() < s) {
                    speed.pop();
                    res++;
                }
                curSpeed = s;
                break;
            case 2:
                while (!overtake.top()) {
                    overtake.pop();
                    res++;
                }
                break;
            case 3:
                in >> s;
                if (s < curSpeed) {
                    res++;
                } else {
                    speed.push(s);
                }
                break;
            case 4:
                overtake.push(true);
                break;
            case 5:
                speed.push(inf);
                break;
            case 6:
                overtake.push(false);
                break;
            default:
                break;
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