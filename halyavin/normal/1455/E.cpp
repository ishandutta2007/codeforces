#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        std::array<std::pair<int, int>, 4> points;
        for (int j = 0; j < 4; j++) {
            in >> points[j].first >> points[j].second;
        }
        int64_t opt = int64_t(1) << 60;
        for (int i0 = 0; i0 < 4; i0++) {
            for (int i1 = 0; i1 < 4; i1++) {
                if (i1 == i0) {
                    continue;
                }
                for (int i2 = 0; i2 < 4; i2++) {
                    if (i2 == i1 || i2 == i0) {
                        continue;
                    }
                    int i3 = 6 - i0 - i1 - i2;
                    std::vector<int> ss;
                    ss.push_back(0);
                    ss.push_back(points[i1].first - points[i0].first);
                    ss.push_back(points[i1].first - points[i2].first);
                    ss.push_back(points[i3].first - points[i0].first);
                    ss.push_back(points[i3].first - points[i2].first);
                    ss.push_back(points[i2].second - points[i0].second);
                    ss.push_back(points[i2].second - points[i1].second);
                    ss.push_back(points[i3].second - points[i0].second);
                    ss.push_back(points[i3].second - points[i1].second);
                    for (int s : ss) {
                        int64_t res = 0;
                        std::array<int, 4> xs{points[i0].first, points[i2].first, points[i1].first - s,
                                              points[i3].first - s};
                        std::sort(xs.begin(), xs.end());
                        int64_t a = xs[1];
                        for (int x : xs) {
                            res += std::abs(a - x);
                        }
                        std::array<int, 4> ys{points[i0].second, points[i1].second, points[i2].second - s,
                                              points[i3].second - s};
                        std::sort(ys.begin(), ys.end());
                        int64_t b = ys[1];
                        for (int y : ys) {
                            res += std::abs(b - y);
                        }
                        opt = std::min(opt, res);
                    }
                }
            }
        }
        out << opt << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}