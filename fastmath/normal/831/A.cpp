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
    vector <int> d;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] < a[i + 1])
            d.app(0);
        else if (a[i] == a[i + 1])
            d.app(1);
        else
            d.app(2);
    }   
    for (int i = 0; i + 1 < d.size(); ++i) {
        if (d[i] > d[i + 1]) {
            cout << "NO\n";
            exit(0);
        }   
    }   
    cout << "YES\n";
}