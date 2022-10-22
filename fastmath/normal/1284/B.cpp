#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> l, r;
    for (int i = 0; i < n; ++i) {
        int len; cin >> len;
        vector <int> t(len);
        for (int j = 0; j < len; ++j) 
            cin >> t[j];
        bool c = 1;
        for (int j = 0; j + 1 < len; ++j)
            c &= t[j] >= t[j + 1];
        if (c) {
            l.app(t[0]);
            r.app(t[len - 1]);
        }   
    }   
    sort(all(l));
    sort(all(r));
    int ptr = 0;
    int bad = 0;
    for (int e : l) {
        while (ptr < r.size() && r[ptr] < e) {
            ++ptr;
        }   
        bad += r.size() - ptr;
    }   
    cout << n * n - bad << '\n';
}