#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
int n;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    vector <int> mid;
    int L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;
        vector <int> a(sz);
        for (int j = 0; j < sz; ++j) cin >> a[j];
        for (int j = 0; j < (sz >> 1); ++j) {
            L += a[j];
            R += a[sz - j - 1];
        }   
        if (sz & 1) {
            mid.push_back(a[sz >> 1]);
        }   
    }   
    sort(mid.begin(), mid.end());
    reverse(mid.begin(), mid.end());
    for (int i = 0; i < (int)mid.size(); ++i) {
        if (i & 1) R += mid[i];
        else L += mid[i];
    }   
    cout << L << ' ' << R << '\n';
}