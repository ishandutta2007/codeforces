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

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    int found = 0;
    std::vector<int> stack;
    std::vector<int> ans;
    for (int i = 0; i < k; i++) {
        int p;
        in >> p;
        p--;
        ans.push_back(p);
        if (p == found) {
            found++;
        } else {
            if (!stack.empty() && stack.back() < p) {
                out << "-1" << std::endl;
                return;
            }
            stack.push_back(p);
        }
        while (!stack.empty() && stack.back() == found) {
            found++;
            stack.resize(stack.size() - 1);
        }
    }
    for (int i = 0; i < n - k && !stack.empty(); i++) {
        int p = stack.back() - 1;
        ans.push_back(p);
        if (p == found) {
            found++;
            while (!stack.empty() && stack.back() == found) {
                found++;
                stack.resize(stack.size() - 1);
            }
        } else {
            stack.push_back(p);
        }
    }
    int last = n;
    while (ans.size() < n) {
        last--;
        ans.push_back(last);
    }
    for (int i = 0; i < n; i++) {
        out << (ans[i] + 1) << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}