#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 2100;
int dp[N][N], par[N][N];
char add[N][N];
ii t[N];
string a[N];

int val[1 << 10];
vector <ii> g[1 << 10];

vector <string> p = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    //calc val and g
    for (int i = 0; i < (1 << 10); ++i)
        val[i] = -1;
    for (int c = 0; c < 10; ++c) {
        int m = 0;
        for (char t : p[c]) {
            m <<= 1;
            m += t == '1';
        }
        val[m] = c;
    }   
    for (int m = 0; m < (1 << 7); ++m) {
        if (val[m] != -1) {
            for (int s=m; ; s=(s-1)&m) {
                g[s].app(mp(m, bp(m) - bp(s)));
                if (s==0)  break;
            }    
        }
    }   


    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }   
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int i = 0; i < N; ++i)
            t[i] = mp(-1, -1);        
        int v = 0;
        for (char c : a[i]) {
            v <<= 1;
            v += c == '1';
        }   
        for (int j = 0; j <= k; ++j) {
            if (dp[i - 1][j] == -1)
                continue;
            for (auto e : g[v]) {
                if (mp(dp[i - 1][j], val[e.f]) > t[j + e.s]) {
                    t[j + e.s] = mp(dp[i - 1][j], val[e.f]);
                    par[i][j + e.s] = j;
                    add[i][j + e.s] = val[e.f] + '0';
                }   
            }   
        }   
        vector <ii> c;
        for (int j = 0; j <= k; ++j) {
            if (t[j].f != -1) {
                c.app(t[j]);
            }   
        }   
        sort(all(c));
        c.resize(unique(all(c)) - c.begin());
        for (int j = 0; j <= k; ++j) {
            if (t[j].f == -1)
                dp[i][j] = -1;
            else
                dp[i][j] = lower_bound(all(c), t[j]) - c.begin();
        }   
    }   
    
    if (dp[n][k] == -1) {
        cout << -1 << endl;
    }   
    else {
        string ans;
        while (n) {
            ans += add[n][k];
            k = par[n][k];
            --n;
        }   
        reverse(all(ans));
        cout << ans << endl;
    }   

}