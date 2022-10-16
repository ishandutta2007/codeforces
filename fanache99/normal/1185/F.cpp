// Example program
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int K = 9;
const int MAXN = 100000;
const int MAXM = 100000;

int friends[1 << K];
vector<pair<int, int> > pizzas[1 << K];
int answer = -1, smallest = 0, best1 = 1, best2 = 2;

void Try(int mask1, int mask2) {
    int cost, current1, current2;
    if (mask1 == mask2) {
        if (pizzas[mask1].size() < 2)
            return;
        cost = pizzas[mask1][0].first + pizzas[mask1][1].first;
        current1 = pizzas[mask1][0].second;
        current2 = pizzas[mask1][1].second;
    }
    else {
        if (pizzas[mask1].empty() || pizzas[mask2].empty())
            return;
        cost = pizzas[mask1][0].first + pizzas[mask2][0].first;
        current1 = pizzas[mask1][0].second;
        current2 = pizzas[mask2][0].second;
    }
    int people = 0;
    for (int mask = 0; mask < (1 << K); mask++)
        if ((mask & (mask1 | mask2)) == mask)
            people += friends[mask];
    if (people > answer || (people == answer && cost < smallest)) {
        answer = people;
        smallest = cost;
        best1 = current1;
        best2 = current2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, mask = 0;
        cin >> p;
        for (int j = 1; j <= p; j++) {
            int x;
            cin >> x;
            mask |= (1 << (x - 1));
        }
        friends[mask]++;
    }
    for (int i = 1; i <= m; i++) {
        int p, cost, mask = 0;
        cin >> cost >> p;
        for (int j = 1; j <= p; j++) {
            int x;
            cin >> x;
            mask |= (1 << (x - 1));
        }
        pizzas[mask].push_back(make_pair(cost, i));
    }
    for (int mask = 0; mask < (1 << K); mask++)
        sort(pizzas[mask].begin(), pizzas[mask].end());
    for (int mask1 = 0; mask1 < (1 << K); mask1++)
        for (int mask2 = 0; mask2 < (1 << K); mask2++)
            Try(mask1, mask2);
    cout << best1 << " " << best2 << "\n";
    return 0;
}