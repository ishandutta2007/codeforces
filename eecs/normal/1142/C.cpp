#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll x[maxn], y[maxn];
vector<pair<ll, ll>> V;
map<ll, ll> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        y[i] -= x[i] * x[i];
        if (!mp.count(x[i]) || mp[x[i]] < y[i]) mp[x[i]] = y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (mp[x[i]] == y[i]) V.emplace_back(x[i], y[i]);
    }
    sort(V.begin(), V.end());
    auto chk = [&](int i, int j, int k) {
        ll x1 = V[j].first - V[i].first, y1 = V[j].second - V[i].second;
        ll x2 = V[k].first - V[j].first, y2 = V[k].second - V[j].second;
        return x1 * y2 >= x2 * y1;
    };
    vector<int> st;
    for (int i = 0; i < V.size(); i++) {
        while (st.size() > 1 && chk(st[st.size() - 2], st[st.size() - 1], i)) st.pop_back();
        st.push_back(i);
    }
    printf("%d\n", st.size() - 1);
    return 0;
}