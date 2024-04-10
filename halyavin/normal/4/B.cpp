#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void run(std::istream& in, std::ostream& out) {
    int d, sum;
    in >> d >> sum;
    std::vector<int> minTimes;
    std::vector<int> maxTimes;
    for (int i = 0; i < d; i++) {
        int minTime, maxTime;
        in >> minTime >> maxTime;
        minTimes.push_back(minTime);
        maxTimes.push_back(maxTime);
    }
    int minSum = accumulate(minTimes.begin(), minTimes.end(), 0);
    int maxSum = accumulate(maxTimes.begin(), maxTimes.end(), 0);
    if (sum < minSum || sum > maxSum) {
        out << "NO" << std::endl;
        return;
    }
    out << "YES" << std::endl;
    int diff = sum - minSum;
    for (int i = 0; i < d; i++) {
        int value = minTimes[i];
        int add = std::min(diff, maxTimes[i]- minTimes[i]);
        value += add;
        diff -= add;
        out << value << " ";
    }
    out << std::endl;
}
int main() {
    run(std::cin, std::cout);
    return 0;
}