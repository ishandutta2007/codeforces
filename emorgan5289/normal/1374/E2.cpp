#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<pair<ll, int>> t[4];

array<ll, 3> eval(int x, int y) {
    // assert(x >= 0 && y >= 0);
    int l = max(-(int)(t[2].size()-1-x-y), 0), r = min((int)t[1].size()-1-x, y);
    // debug(l, r, x, y);
    // assert(l <= r);
    while (l < r-2) {
        int mid = (l+r)/2;
        if (t[1][x+mid].first+t[2][x+y-mid].first < t[1][x+mid+1].first+t[2][x+y-mid-1].first)
            r = mid+1;
        else
            l = mid;
    }
    array<ll, 3> v; v[0] = inf_ll;
    for (int j = l; j <= r; j++)
        v = min(v, {t[1][x+j].first+t[2][x+y-j].first, x+j, x+y-j});
    return v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x, a, b; cin >> x >> a >> b;
        t[2*a+b].pb({x, i});
    }
    for (int i = 0; i < 4; i++) {
        sort(all(t[i]));
        for (int j = 1; j < t[i].size(); j++)
            t[i][j].first += t[i][j-1].first;
    }
    for (int i = 0; i < 4; i++)
        t[i].insert(t[i].begin(), {0, -1});
    array<ll, 3> ans; ans[0] = inf_ll;
    for (int i = 0; i <= min(m, (int)t[3].size()-1); i++) {
        int x = max(0, k-i);
        if (x > min(t[1].size(), t[2].size())-1) continue;
        int l = max(0, m-i-(int)(t[1].size()+t[2].size())+2), r = min((int)t[0].size()-1, m-i-2*x);
        // debug(i, l, r);
        while (l < r-2) {
            int mid = (l+r)/2;
            if (eval(x, m-i-2*x-mid)[0]+(t[0][mid].first) < eval(x, m-i-2*x-mid-1)[0]+(t[0][mid+1].first))
                r = mid+1;
            else
                l = mid;
        }
        // m-i-min(t[1].size(), t[2].size())+1 <= mid
        array<ll, 2> v = {inf_ll, -1};
        for (int j = l; j <= r; j++) {
            v = min(v, {eval(x, m-i-2*x-j)[0]+(t[0][j].first), j});
        }
        // debug(i, v+t[3][i].first);
        ans = min(ans, array<ll, 3>{v[0]+t[3][i].first, i, v[1]});
    }
    if (ans[0] == inf_ll)
        return cout << "-1\n", 0;
    cout << ans[0] << "\n";
    for (int i = 1; i <= ans[1]; i++)
        cout << t[3][i].second+1 << " ";
    for (int i = 1; i <= ans[2]; i++)
        cout << t[0][i].second+1 << " ";
    int x = max(0ll, k-ans[1]);
    auto v = eval(x, m-ans[1]-2*x-ans[2]);
    for (int i = 1; i <= v[1]; i++)
        cout << t[1][i].second+1 << " ";
    for (int i = 1; i <= v[2]; i++)
        cout << t[2][i].second+1 << " ";
}