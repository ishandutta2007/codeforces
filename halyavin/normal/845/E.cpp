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

bool check(std::vector<std::array<int, 2>>& centers, int coord, int n1, int n2, int time) {
    int otherCoord = 1 - coord;
    std::vector<int> points;
    points.push_back(0);
    points.push_back(n1 - 1);
    for (auto& center : centers) {
        if (center[coord] - time > 0) {
            points.push_back(center[coord] - time);
            points.push_back(center[coord] - time - 1);
        }
        if (center[coord] + time < n1 - 1) {
            points.push_back(center[coord] + time);
            points.push_back(center[coord] + time + 1);
        }
    }
    std::sort(points.begin(), points.end());
    auto it = std::unique(points.begin(), points.end());
    points.erase(it, points.end());
    std::vector<std::pair<int, int>> intervals;
    int minPoint = n1 - 1;
    int maxPoint = 0;
    for (int point : points) {
        intervals.clear();
        for (auto& center : centers) {
            if (std::abs(center[coord] - point) <= time) {
                intervals.emplace_back(center[otherCoord] - time, center[otherCoord] + time + 1);
            }
        }
        std::sort(intervals.begin(), intervals.end());
        int start = 0;
        for (auto& interval : intervals) {
            if (interval.first > start) {
                break;
            }
            start = interval.second;
        }
        if (start < n2) {
            minPoint = std::min(minPoint, point);
            maxPoint = std::max(maxPoint, point);
        }
    }
    return maxPoint - minPoint <= 2 * time;
}

void run(std::istream& in, std::ostream& out) {
    int n, m;
    int k;
    in >> n >> m >> k;
    std::vector<std::array<int, 2>> centers(k);
    for (int i = 0; i < k; i++) {
        in >> centers[i][0] >> centers[i][1];
        centers[i][0]--;
        centers[i][1]--;
    }
    int left = -1;
    int right = std::max(n, m);
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (check(centers, 0, n, m, middle) && check(centers, 1, m, n, middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }
    out << right << std::endl;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}