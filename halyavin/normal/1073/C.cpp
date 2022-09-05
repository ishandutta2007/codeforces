#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Solution {
    int n;
    std::vector<int> dx;
    std::vector<int> sumx;
    std::vector<int> dy;
    std::vector<int> sumy;
    int x, y;
    int realX, realY;
    int changeX, changeY;

    bool check(int len) {
        for (int i = 0; i + len <= n; i++) {
            int curx = sumx[i + len] - sumx[i];
            int cury = sumy[i + len] - sumy[i];
            int cx = changeX + curx;
            int cy = changeY + cury;
            if ((uint32_t)std::abs(cx) + (uint32_t)std::abs(cy) <= (uint32_t)len) {
                return true;
            }
        }
        return false;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        dx.assign(n, 0);
        dy.assign(n, 0);
        std::string s;
        in >> s;
        for (size_t i = 0; i < n; i++) {
            switch (s[i]) {
                case 'U':
                    dy[i] = 1;
                    break;
                case 'D':
                    dy[i] = -1;
                    break;
                case 'R':
                    dx[i] = 1;
                    break;
                case 'L':
                    dx[i] = -1;
                    break;
            }
        }
        in >> x >> y;
        if (std::abs(x) + std::abs(y) > n || ((std::abs(x) + std::abs(y)) & 1) != (n & 1)) {
            out << "-1\n";
            return;
        }
        sumx.resize(n + 1);
        sumy.resize(n + 1);
        sumx[0] = 0;
        sumy[0] = 0;
        for (int i = 1; i <= n; i++) {
            sumx[i] = sumx[i - 1] + dx[i - 1];
            sumy[i] = sumy[i - 1] + dy[i - 1];
        }
        realX = sumx.back();
        realY = sumy.back();
        changeX = x - realX;
        changeY = y - realY;
        int left = -1;
        int right = n;
        while (right - left > 1) {
            int middle = (left + right) / 2;
            if (check(middle)) {
                right = middle;
            } else {
                left = middle;
            }
        }
        out << right << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}