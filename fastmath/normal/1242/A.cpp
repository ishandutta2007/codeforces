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

    if (n == 1) {
        cout << "1\n";
        exit(0);
    }   

    vector <int> p;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            p.app(d);
            while (n % d == 0) n /= d;
        }   
    }   
    if (n > 1) p.app(n);
    if (p.size() > 1) {
        cout << "1\n";
    }   
    else cout << p[0] << '\n';
}