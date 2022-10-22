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
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        string s; cin >> s;

        int len = s.size();
        for (int i = 1; i <= x; ++i) {
            int w = s[i - 1] - '0' - 1;
            if (s.size() < x) {
                int len_add = s.size() - i;
                string r = s.substr(i, len_add);
                for (int j = 0; j < w; ++j) 
                    s += r;
                len = s.size();
            }
            else {
                len = mod(len + w * mod(len - i));
            }   
        }   

        cout << len << '\n';
    }   
}