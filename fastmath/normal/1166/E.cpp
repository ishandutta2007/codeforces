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

const int N = 1e4 + 7;
const int Q = 51;

bool a[Q][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int q, n;
    cin >> q >> n;
    for (int i = 0; i < q; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int p; cin >> p;
            a[i][p - 1] = 1;
        }   
    }   
    for (int i = 0; i < q; ++i) 
        for (int j = 0; j < q; ++j) {
            bool c = 1;
            for (int k = 0; k < n; ++k) 
                if (a[i][k] && a[j][k]) 
                    c = 0;
            if (c) {
                cout << "impossible\n";
                return 0;
            }   
        }   
    cout << "possible\n";
}