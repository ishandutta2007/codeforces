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
const int MOD1 = 1000 * 1000 * 1000 + 7, MOD2 = 1000 * 1000 * 1000 + 9;
const int N = 1e6 + 7, BASE = 5;
string a[N];
int pw1[N], pw2[N];
int mod(int n, int MOD) {
    n %= MOD;
    if (n < 0)
        return n + MOD;
    else
        return n;            
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = pw1[i - 1] * BASE % MOD1;
        pw2[i] = pw2[i - 1] * BASE % MOD2;
    }
    int n, m;
    cin >> n >> m;
    set <ii> ms;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        int h1 = 0, h2 = 0;
        for (char c : a[i]) {
            h1 = (h1 * BASE + (c - 'a' + 1)) % MOD1;
            h2 = (h2 * BASE + (c - 'a' + 1)) % MOD2;
        }
        ms.insert(mp(h1, h2));
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int h1 = 0, h2 = 0;
        for (char c : s) {
            h1 = (h1 * BASE + (c - 'a' + 1)) % MOD1;
            h2 = (h2 * BASE + (c - 'a' + 1)) % MOD2;
        }
        string ans = "NO";
        for (int j = 0; j < s.size(); ++j) {
            int cur = s[j] - 'a';
            int p = s.size() - j - 1;
            for (int c = 0; c < 3; ++c) {
                int d = c - cur;
                if (d) {
                    int w1 = mod(h1 + d * pw1[p], MOD1);
                    int w2 = mod(h2 + d * pw2[p], MOD2);
                    if (ms.find(mp(w1, w2)) != ms.end()) 
                        ans = "YES";
                }   
            }               
        }   
        cout << ans << '\n';
    }                       
}