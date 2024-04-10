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

const int N = 2007, BASE = 129, MOD1 = 1000 * 1000 * 1000 + 7, MOD2 = 1000 * 1000 * 1000 + 9;
int h[2][N], pw[2][N], mod[2];
int get(int l, int r, int h[N], int pw[N], int MOD) {
    return ((h[r + 1] - h[l] * pw[r - l + 1]) % MOD + MOD) % MOD;
}   
int hl[2], hr[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    mod[0] = MOD1;
    mod[1] = MOD2;
    for (int t = 0; t < 2; ++t) {
        pw[t][0] = 1;
        for (int i = 1; i < N; ++i)
            pw[t][i] = (pw[t][i - 1] * BASE) % mod[t];
    }   
    string s, l, r;
    cin >> s >> l >> r;
    int n = s.size();
    for (int t = 0; t < 2; ++t) 
        for (int i = 0; i < n; ++i)
            h[t][i + 1] = (h[t][i] * BASE + s[i]) % mod[t];

    for (int t = 0; t < 2; ++t) {
        for (char c : l)
            hl[t] = (hl[t] * BASE + c) % mod[t];
        for (char c : r) 
            hr[t] = (hr[t] * BASE + c) % mod[t];
    }
    vector <ii> ms;
    for (int i = 0; i + l.size() - 1 < n; ++i) {
        for (int j = max(i + r.size() - 1, i + l.size() - 1); j < n; ++j) {

            if (get(i, i + l.size() - 1, h[0], pw[0], mod[0]) == hl[0] && get((int)j - r.size() + 1, j, h[0], pw[0], mod[0]) == hr[0]) {
                ms.app(mp(get(i, j, h[0], pw[0], mod[0]), get(i, j, h[1], pw[1], mod[1])));
            }   
            
        }   
    }   
    sort(all(ms));
    cout << unique(all(ms)) - ms.begin() << endl;
}