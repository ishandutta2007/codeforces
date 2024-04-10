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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
ii a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;
    a[n] = a[0];
    if (n & 1) {
        cout << "No\n";
        exit(0);
    }   
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        //cout << (a[i + 1].f - a[i].f) << ' ' << (a[m + i + 1].f - a[m + i].f) << ' ' << (a[i + 1].s - a[i].s) << ' ' << (a[m + i + 1].s - a[m + i].s) << '\n';
        if ((a[i + 1].f - a[i].f) == -(a[m + i + 1].f - a[m + i].f) && (a[i + 1].s - a[i].s) == -(a[m + i + 1].s - a[m + i].s)) 
            continue;
        cout << "No\n";
        exit(0);
    }   
    cout << "Yes\n";
}