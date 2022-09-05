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

using Sofa = std::array<std::pair<int, int>, 2>;

void run(std::istream& in, std::ostream& out) {
    int d, n, m;
    in >> d >> n >> m;
    std::vector<Sofa> sofas(d);
    for (int i = 0; i < d; i++) {
        in >> sofas[i][0].first >> sofas[i][0].second;
        in >> sofas[i][1].first >> sofas[i][1].second;
        sofas[i][0].first--;
        sofas[i][0].second--;
        sofas[i][1].first--;
        sofas[i][1].second--;
    }
    std::vector<int> hor1(n), hor2(n - 1);
    std::vector<int> vert1(m), vert2(m - 1);
    for (int i = 0; i < d; i++) {
        int x1 = sofas[i][0].first;
        int x2 = sofas[i][1].first;
        if (x1 == x2) {
            hor1[x1]++;
        } else {
            hor2[std::min(x1, x2)]++;
        }
        int y1 = sofas[i][0].second;
        int y2 = sofas[i][1].second;
        if (y1 == y2) {
            vert1[y1]++;
        } else {
            vert2[std::min(y1, y2)]++;
        }
    }
    int cntl, cntr, cntt, cntb;
    in >> cntl >> cntr >> cntt >> cntb;
    int sumHor1 = std::accumulate(hor1.begin(), hor1.end(), 0);
    int sumHor2 = std::accumulate(hor2.begin(), hor2.end(), 0);
    int sumVert1 = std::accumulate(vert1.begin(), vert1.end(), 0);
    int sumVert2 = std::accumulate(vert2.begin(), vert2.end(), 0);
    {
        int sumLeft1 = 0;
        int sumLeft2 = 0;
        int goodX = -1;
        for (int x = 0; x < n; x++) {
            if (x > 0) {
                sumLeft1 += hor1[x - 1];
                sumLeft2 += hor2[x - 1];
            }
            int left = sumLeft1 + sumLeft2;
            int right = sumHor1 + sumHor2 - hor1[x] - left;
            if (hor1[x] > 0 && left == cntl && right == cntr) {
                goodX = x;
                break;
            }
        }
        int sumTop1 = 0;
        int sumTop2 = 0;
        int goodY = -1;
        for (int y = 0; y + 1 < m; y++) {
            sumTop1 += vert1[y];
            if (y > 0) {
                sumTop2 += vert2[y - 1];
            }
            int top = sumTop1 + sumTop2 + vert2[y] - 1;
            int bottom = (sumVert1 - sumTop1) + (sumVert2 - sumTop2) - 1;
            if (vert2[y] > 0 && top == cntt && bottom == cntb) {
                goodY = y;
                break;
            }
        }
        if (goodX >= 0 && goodY >= 0) {
            for (size_t i = 0; i < sofas.size(); i++) {
                Sofa& sofa = sofas[i];
                if (sofa[0].first == goodX && sofa[1].first == goodX &&
                    std::min(sofa[0].second, sofa[1].second) == goodY &&
                    std::max(sofa[0].second, sofa[1].second) == goodY + 1) {
                    out << (i + 1) << std::endl;
                    return;
                }
            }
        }
    }
    {
        int sumLeft1 = 0;
        int sumLeft2 = 0;
        int goodX = -1;
        for (int x = 0; x + 1 < n; x++) {
            sumLeft1 += hor1[x];
            if (x > 0) {
                sumLeft2 += hor2[x - 1];
            }
            int left = sumLeft1 + sumLeft2 + hor2[x] - 1;
            int right = (sumHor1 - sumLeft1) + (sumHor2 - sumLeft2) - 1;
            if (hor2[x] > 0 && left == cntl && right == cntr) {
                goodX = x;
                break;
            }
        }
        int sumTop1 = 0;
        int sumTop2 = 0;
        int goodY = -1;
        for (int y = 0; y < m; y++) {
            if (y > 0) {
                sumTop1 += vert1[y - 1];
                sumTop2 += vert2[y - 1];
            }
            int top = sumTop1 + sumTop2;
            int bottom = sumVert1 + sumVert2 - vert1[y] - top;
            if (vert1[y] > 0 && top == cntt && bottom == cntb) {
                goodY = y;
                break;
            }
        }
        if (goodX >= 0 && goodY >= 0) {
            for (size_t i = 0; i < sofas.size(); i++) {
                Sofa& sofa = sofas[i];
                if (std::min(sofa[0].first, sofa[1].first) == goodX &&
                    std::max(sofa[0].first, sofa[1].first) == goodX + 1 &&
                    sofa[0].second == goodY &&
                    sofa[1].second == goodY) {
                    out << (i + 1) << std::endl;
                    return;
                }
            }
        }
    }
    out << -1 << std::endl;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}