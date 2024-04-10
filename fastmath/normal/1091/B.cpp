#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <pair <int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }   

    vector <pair <int, int> > b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first >> b[i].second;
    }   

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    cout << a[0].first + b.back().first << ' ' << a[0].second + b.back().second << '\n';

    return 0;
}