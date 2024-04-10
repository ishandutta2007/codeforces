#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5.1e5;
int N, M, C, C0;
pair<int, pair<int, int>> V[MAXN];

ll go() {
    cin >> N >> M >> C >> C0;
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second.second >> V[i].second.first;
    }
    V[N++] = {0, {0, C0}};
    sort(V, V + N);
    V[N].first = M;
    int totSize = 0;
    multiset<pair<int, int>> friends;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        friends.emplace(V[i].second);
        totSize += V[i].second.second;
        while (totSize > C) {
            assert(!friends.empty());
            auto it = friends.end();
            --it;
            auto cur = *it;
            friends.erase(it);
            int v = min(cur.second, totSize - C);
            totSize -= v;
            cur.second -= v;
            if (cur.second) {
                friends.insert(cur);
            }
        }
        int d = V[i+1].first - V[i].first;
        while (d > 0) {
            if (friends.empty()) return -1;
            auto it = friends.begin();
            auto cur = *it;
            friends.erase(it);
            int v = min(cur.second, d);
            d -= v;
            totSize -= v;
            cur.second -= v;
            ans += ll(v) * ll(cur.first);
            if (cur.second) {
                friends.insert(cur);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Q; cin >> Q;
    while (Q--) {
        cout << go() << '\n';
    }
    return 0;
}