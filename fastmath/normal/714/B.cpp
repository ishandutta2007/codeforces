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

void check(vector <int> &a, int w) {
    vector <int> d;
    for (int e : a)
        if (w - e)
            d.app(w - e);
    sort(all(d));
    d.resize(unique(all(d)) - d.begin());
    if (d.size() == 1) {
        cout << "YES\n";
        exit(0);
    }   
    if (d.size() == 2 && d[0] == -d[1]) {
        cout << "YES\n";
        exit(0);
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;       
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    if (a.size() == 1) {
        cout << "YES\n";
    }                   
    else {
        check(a, a[0]);
        check(a, a[1]);
        if ((a[0] + a[1]) % 2 == 0) {
            check(a, (a[0] + a[1]) / 2);
        }   
        cout << "NO\n";
    }
}