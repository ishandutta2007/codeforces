#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

const int maxA = 500000;
struct Solution {
    int n, c;
    std::vector<int> as;
    std::vector<int> next;
    std::vector<int> last;
    std::vector<int> prevC;
    int countC;
    int opt;

    void check(int c1) {
        int res = 0;
        int minSum = 0;
        int curV = last[c1];
        if (curV == n) return;
        int curSum = 0;
        while (true) {
            int nextV = next[curV];
            if (nextV == n) break;
            curSum += 1 - (prevC[nextV] - prevC[curV]);
            minSum = std::min(minSum, curSum);
            res = std::max(res, curSum - minSum);
            curV = nextV;
        }
        opt = std::max(opt, res + 1);
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> c;
        as.resize(n);
        next.resize(n);
        last.assign(maxA + 1, n);
        countC = 0;
        for (int i = 0; i < n; i++) {
            in >> as[i];
            if (as[i] == c) {
                countC++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            next[i] = last[as[i]];
            last[as[i]] = i;
        }
        prevC.assign(n, 0);
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (as[i] == c) {
                prev++;
            }
            prevC[i] = prev;
        }
        opt = 0;
        for (int i = 0;i < last.size(); i++) {
            if (i != c) {
                check(i);
            }
        }
        out << (opt + countC) << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}