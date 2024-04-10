#include <bits/stdc++.h>

using namespace std;
#define int long long

bool comp(pair <int, int> a, pair <int, int> b) {
    return a.second > b.second;
}

signed main()
{
    //freopen("1.txt", "r", stdin);

    int n;
    cin >> n;
    vector <pair <int, int> > a;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(a.begin(), a.end(), comp);

    int ans = 0;
    set <int> ms;
    for (pair <int, int> elem : a) {
        if (ms.find(elem.first) == ms.end()) {
            ms.insert(elem.first);
            ans += elem.second;
        }
    }

    cout << ans << '\n';
    return 0;
}