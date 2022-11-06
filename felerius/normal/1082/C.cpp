#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> topic_skills(m);

    for(int i = 0; i < n; ++i)  {
        size_t topic;
        int skill;
        cin >> topic >> skill;
        topic_skills[topic - 1].emplace_back(skill);
    }

    size_t max_delegation_size = 0;
    for (auto& topic : topic_skills) {
        sort(topic.begin(), topic.end(), std::greater<int>{});
        partial_sum(topic.begin(), topic.end(), topic.begin());
        max_delegation_size = max(max_delegation_size, topic.size());
    }

    vector<int> max_at_del_size(max_delegation_size);
    for (const auto& topic : topic_skills) {
        for (size_t i = 0; i < topic.size(); ++i) {
            if (topic[i] > 0) {
                max_at_del_size[i] += topic[i];
            }
        }
    }

    cout << *max_element(max_at_del_size.begin(), max_at_del_size.end()) << '\n';

    return 0;
}