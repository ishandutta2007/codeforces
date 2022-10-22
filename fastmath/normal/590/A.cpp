#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 7;
int n;
char a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int> > v;
    int l = 0;
    while (l < n) {
        if (l == 0 || l == n - 1 || (l + 1 < n && a[l] == a[l + 1])) {
            int r = l;
            while (r + 1 < n && a[r + 1] == a[l]) ++r;
            v.push_back({l, r});
            l = r + 1;
        }   
        else {
            ++l;
        }   
    }   
    int ans = 0;
    for (int i = 0; i + 1 < (int)v.size(); ++i) {
        int len = v[i + 1].first - v[i].second - 1;
        char l = a[v[i].first];
        char r = a[v[i + 1].second];
        if (len & 1) {
            for (int j = v[i].second + 1; j < v[i + 1].first; ++j) a[j] = l;
        }
        else {
            for (int j = 0; j < (len >> 1); ++j) {
                a[v[i].second + 1 + j] = l;
                a[v[i + 1].first - 1 - j] = r;
            }   
        }   
        ans = max(ans, (len + 1) >> 1);
    }   
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
}