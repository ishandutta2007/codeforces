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
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> sum(2);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum[i&1] += a[i];
        }   

        int t = 0;
        if (sum[1] < sum[0])
            t = 1;

        for (int i = 0; i < n; ++i) {
            if ((i & 1) == t) {
                cout << 1 << ' ';
            }   
            else {
                cout << a[i] << ' ';
            }   
        }           
        cout << endl;
    }   
}