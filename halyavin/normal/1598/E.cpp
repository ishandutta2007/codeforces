#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Solution {
    std::vector<std::vector<uint8_t>> matrix;
    int n, m;

    uint32_t calcPaths(int x, int y) {
        uint32_t answer = 0;
        int a = 1;
        int cx = x;
        int cy = y;
        while (true) {
            cx--;
            if (cx < 0 || matrix[cx][cy] > 0) {
                break;
            }
            a++;
            cy--;
            if (cy < 0 || matrix[cx][cy] > 0) {
                break;
            }
            a++;
        }
        int b = 1;
        cx = x;
        cy = y;
        while (true) {
            cy++;
            if (cy >= m || matrix[cx][cy] > 0) {
                break;
            }
            b++;
            cx++;
            if (cx >= n || matrix[cx][cy] > 0) {
                break;
            }
            b++;
        }
        answer += a * b;

        a = 1;
        cx = x;
        cy = y;
        while (true) {
            cy--;
            if (cy < 0 || matrix[cx][cy] > 0) {
                break;
            }
            a++;
            cx--;
            if (cx < 0 || matrix[cx][cy] > 0) {
                break;
            }
            a++;
        }
        b = 1;
        cx = x;
        cy = y;
        while (true) {
            cx++;
            if (cx >= n || matrix[cx][cy] > 0) {
                break;
            }
            b++;
            cy++;
            if (cy >= m || matrix[cx][cy] > 0) {
                break;
            }
            b++;
        }
        answer += a * b;
        answer--;
        return answer;
    }
    void run(std::istream& in, std::ostream& out) {
        in >> n >> m;
        matrix.assign(n, std::vector<uint8_t>(m));
        uint32_t answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    answer += 1 + 4 * i;
                } else {
                    answer += 2 + 4 * std::min(i, j);
                }
            }
        }
        int q;
        in >> q;
        for (int query = 0; query < q; query++) {
            int x, y;
            in >> x >> y;
            x--;y--;
            if (matrix[x][y] > 0) {
                matrix[x][y] = 0;
                answer += calcPaths(x, y);
            } else {
                answer -= calcPaths(x, y);
                matrix[x][y] = 1;
            }
            out << answer << "\n";
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}