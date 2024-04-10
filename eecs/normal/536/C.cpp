#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, x[maxn], y[maxn];
vector<pair<int, int>> V;
map<int, int> mp;
set<int> S;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]), V.emplace_back(x[i], y[i]);
        mp[x[i]] = max(mp[x[i]], y[i]);
    }
    sort(V.begin(), V.end());
    auto chk = [&](int i, int j, int k) {
        return 1LL * V[j].second * V[k].first * (V[i].first - V[j].first) *
            (V[i].second - V[k].second) > 1LL * V[j].first * V[k].second *
            (V[i].first - V[k].first) * (V[i].second - V[j].second);
    };
    vector<int> st;
    for (int i = 0; i < V.size(); i++) {
        while (!st.empty() && V[st.back()].second <= V[i].second) st.pop_back();
        while (st.size() > 1 && chk(st[st.size() - 2], st[st.size() - 1], i)) st.pop_back();
        st.push_back(i);
    }
    for (int i : st) {
        S.insert(V[i].first);
    }
    for (int i = 1; i <= n; i++) {
        if (mp[x[i]] == y[i] && S.count(x[i])) printf("%d ", i);
    }
    return 0;
}