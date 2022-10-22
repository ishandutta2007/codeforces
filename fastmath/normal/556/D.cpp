#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, m;
pair <int, int> a[MAXN], b[MAXN];

bool comp(int i, int j) {
    return b[i].second < b[j].second;
}   

int len[MAXN];
int per[MAXN];
int ans[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }   
    
    for (int i = 0; i < n - 1; ++i) {
        b[i].first = a[i + 1].first - a[i].second;
        b[i].second = a[i + 1].second - a[i].first;
    }
    for (int i = 0; i < n - 1; ++i) {
        per[i] = i;
    }   
    sort(per, per + n - 1, comp);

    set <pair <int, int> > ms;
    for (int i = 0; i < m; ++i) {
        cin >> len[i];
        ms.insert({len[i], i});
    }   

    for (int i = 0; i < n - 1; ++i) {
        int num = per[i];
        auto u = ms.lower_bound({b[num].first, -1});
        if (u == ms.end() || u->first > b[num].second) {
            cout << "No\n";
            exit(0);
        }   
        else {
            ans[num] = u->second;
            ms.erase(u);
        }   
    }   

    cout << "Yes\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] + 1 << ' ';
        if (ans[i] < 0 || ans[i] >= m || len[ans[i]] < b[i].first || len[ans[i]] > b[i].second) {
            exit(1);
        }   
    }
    cout << '\n';

    return 0;
}