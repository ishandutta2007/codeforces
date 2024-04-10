#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Solution {
    std::vector<std::string> input;
    int n;
    int sum;
    std::vector<std::vector<int>> prefixes;
    std::vector<int> balance;
    std::vector<int> minBalance;

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        input.resize(n);
        for (int i = 0; i < n; i++) {
            in >> input[i];
        }
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += input[i].length();
        }
        prefixes.assign(n, std::vector<int>(sum + 1));
        balance.resize(n);
        minBalance.resize(n);
        for (int i = 0; i < n; i++) {
            int cur = 0;
            int curMin = 0;
            const std::string& curInput = input[i];
            for (int j = 0; j < curInput.length(); j++) {
                if (curInput[j] == '(') {
                    cur++;
                } else {
                    cur--;
                }
                curMin = std::min(curMin, cur);
                if (cur == curMin) {
                    prefixes[i][-curMin]++;
                }
            }
            balance[i] = cur;
            minBalance[i] = curMin;
        }
        std::vector<std::pair<int, int>> dyn(1 << n);
        int answer = 0;
        for (int i = 1; i < 1 << n; i++) {
            dyn[i].second = -1;
            for (int j = 0; j < n; j++) {
                if (((1 << j) & i) != 0) {
                    int prev = i - (1 << j);
                    if (dyn[prev].second < 0) {
                        continue;
                    }
                    int next = dyn[prev].first + prefixes[j][dyn[prev].second];
                    answer = std::max(answer, next);
                    if (dyn[prev].second + minBalance[j] < 0) {
                        continue;
                    }
                    dyn[i].second = dyn[prev].second + balance[j];
                    dyn[i].first = std::max(dyn[i].first, next);
                }
            }
        }
        out << answer << "\n";
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}