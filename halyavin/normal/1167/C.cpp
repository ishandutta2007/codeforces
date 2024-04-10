#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

struct Solution {
    int n;
    std::vector<int> next;
    std::vector<int> count;

    int getRoot(int x) {
        int nx = next[x];
        if (nx == x) {
            return x;
        }
        int res = getRoot(nx);
        next[x] = res;
        return res;
    }

    void join(int x, int y) {
        int rx = getRoot(x);
        int ry = getRoot(y);
        if (rx == ry) {
            return;
        }
        if (count[rx] > count[ry]) {
            next[ry] = rx;
            count[rx] += count[ry];
        } else {
            next[rx] = ry;
            count[ry] += count[rx];
        }
    }

    void run(std::istream &in, std::ostream &out) {
        int m;
        in >> n >> m;
        next.resize(n);
        std::iota(next.begin(), next.end(), 0);
        count.assign(n, 1);
        for (int i = 0; i < m; i++) {
            int k;
            in >> k;
            std::vector<int> friends(k);
            for (int j = 0; j < k; j++) {
                in >> friends[j];
                friends[j]--;
            }
            for (int j = 0; j < k - 1; j++) {
                join(friends[j], friends[j + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            out << count[getRoot(i)] << " ";
        }
        out << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}