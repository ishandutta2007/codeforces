#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

ll ceildiv(ll a, ll b) {
    return a == 0 ? 0 : ((a-1)/b+1);
}

const int N = 1e5+5;
ll n, m;
ll p[N], a[N];
ll ord[N], nxt[N], prv[N];
ll start_time[N], hit_time[N];
multiset<array<ll, 3>> s;

void set_time(int i, ll t) {
    p[ord[i]] += a[ord[i]]*(t-start_time[i]);
    p[ord[i]] %= m;
    start_time[i] = t;
}

void refresh(int i) {
    int j = nxt[i];
    debug(i, j, ord[i]+1, ord[j]+1);

    // update start_time
    ll t = max(start_time[i], start_time[j]);
    set_time(i, t), set_time(j, t);

    debug(p[ord[i]]);

    ll d = (p[ord[j]]-p[ord[i]]+m)%m;
    ll v1 = a[ord[i]], v2 = a[ord[j]];

    debug(d, v1, v2, t);

    // update hit_time
    if (ord[i] < ord[j]) {
        if (d <= v1)
            hit_time[i] = t;
        else if (v2 >= v1)
            hit_time[i] = inf_ll;
        else
            hit_time[i] = t+ceildiv(d-v1, v1-v2);
    } else {
        if (v2 >= v1)
            hit_time[i] = inf_ll;
        else
            hit_time[i] = t+ceildiv(d, v1-v2)-1;
    }
    s.insert({hit_time[i], ord[i], i});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> a[i];
        p[i]--;
        nxt[i] = (i+1)%n;
        prv[nxt[i]] = i;
    }
    iota(ord, ord+n, 0);
    sort(ord, ord+n, [&](int i, int j){
        return p[i] < p[j];
    });
    for (int i = 0; i < n; i++)
        refresh(i);
    while (1) {
        auto [t, o, i] = *s.begin();
        debug(t, o+1, ord[nxt[i]]+1);
        if (t == inf_ll) break;
        s.erase(s.begin());
        s.erase(s.find({hit_time[nxt[i]], ord[nxt[i]], nxt[i]}));
        nxt[i] = nxt[nxt[i]];
        prv[nxt[i]] = i;
        set_time(i, t);
        a[ord[i]]--;
        p[ord[i]]++;
        p[ord[i]] %= m;
        debug(a[ord[i]], p[ord[i]]);
        refresh(i);
        s.erase(s.find({hit_time[prv[i]], ord[prv[i]], prv[i]}));
        refresh(prv[i]);
    }
    cout << s.size() << "\n";
    for (auto& [t, o, i] : s)
        cout << o+1 << " ";
    cout << "\n";
}