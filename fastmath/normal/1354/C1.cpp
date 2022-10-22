#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define double long double
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cout.precision(20);
    const double PI = acos(-1);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n <<= 1;
        double d = 1.0/sin(PI/n);
        cout << sqrt(d * d - 1) << endl;
    }
}