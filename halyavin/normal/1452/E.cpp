#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Solution {
    int n, m, k;
    std::vector<std::pair<int, int>> intervals;
    std::vector<int> diff;
    void run(std::istream &in, std::ostream &out) {
        in >> n >> m >> k;
        intervals.resize(m);
        for (int i = 0; i < m; i++) {
            in >> intervals[i].first >> intervals[i].second;
            intervals[i].second++;
        }
        int optValue = 0;
        for (int first = 1; first <= n - k + 1; first++) {
            diff.assign(n + 2, 0);
            int sum = 0;
            int second = first + k;
            for (const auto& interval : intervals) {
                int intersectLeft = std::max(interval.first, first);
                int intersectRight = std::min(interval.second, second);
                int length = std::max(0, intersectRight - intersectLeft);
                sum += length;
                if (length == std::min(k, interval.second - interval.first)) {
                    continue;
                }
                if (interval.second - interval.first > k) {
                    int pLeft = interval.first - (k - length);
                    int pRight = interval.second - k + (k - length);
                    if (pLeft > 0) {
                        diff[pLeft]++;
                    } else {
                        diff[0]++;
                        sum += -pLeft;
                    }
                    diff[interval.first]--;
                    diff[interval.second - k]--;
                    diff[pRight]++;
                } else if (interval.second >= k) {
                    int pLeft = interval.second - k - (interval.second - interval.first - length);
                    int pRight = interval.first + (interval.second - interval.first - length);
                    if (pLeft > 0) {
                        diff[pLeft]++;
                    } else {
                        diff[0]++;
                        sum += -pLeft;
                    }
                    diff[interval.second - k]--;
                    diff[interval.first]--;
                    diff[pRight]++;
                } else {
                    sum += interval.second - interval.first - length;
                    int pRight = interval.first + (interval.second - interval.first - length);
                    diff[interval.first]--;
                    diff[pRight]++;
                }
            }
            int deriv = 0;
            int value = sum;
            for (size_t i = 0; i < diff.size(); i++) {
                value += deriv;
                deriv += diff[i];
                optValue = std::max(optValue, value);
            }
        }
        out << optValue << "\n";
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}