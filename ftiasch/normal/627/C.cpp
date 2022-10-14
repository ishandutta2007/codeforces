#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
    int d, volume, n;
    scanf("%d%d%d", &d, &volume, &n);
    std::vector<std::pair<int, int>> stations(n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", &stations[i].first, &stations[i].second);
    }
    std::sort(stations.begin(), stations.end());
    stations.emplace_back(d, 0);
    int tank = volume;
    int delta = 0;
    long long result = 0;
    std::deque<std::pair<int, int>> queue;
    for (int i = 0; i <= n; ++ i) {
        while (tank < stations[i].first && !queue.empty()) {
            int need = std::min(stations[i].first - tank, volume - (queue.front().second + delta));
            tank += need;
            delta += need;
            result += (long long)need * queue.front().first;
            if (queue.front().second + delta == volume) {
                queue.pop_front();
            }
        }
        if (tank < stations[i].first) {
            result = -1;
            break;
        }
        while (!queue.empty() && queue.back().first >= stations[i].second) {
            queue.pop_back();
        }
        queue.emplace_back(stations[i].second, tank - stations[i].first - delta);
    }
    std::cout << result << std::endl;
    return 0;
}