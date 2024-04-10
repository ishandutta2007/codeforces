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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1007;
const int M = 51;
const int INF = 1e9 + 7;
const int C = 26;

int dp[N][M][M];

string a, b, c;
void upd(int &a, int b) { a = max(a, b); }

void calc(string &s, int *pi, int mem[M][C]) {
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        int j = pi[i];
        while (j && s[i] != s[j]) 
            j = pi[j];
        if (s[i] == s[j])
            ++j;
        pi[i + 1] = j;
        //cout << "pi " << i + 1 << ' ' << j << endl;
    }   
    for (int i = 0; i <= n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            int j = i;
            while (j && c != s[j]) 
                j = pi[j];
            if (c == s[j])
                ++j;
            mem[i][c - 'a'] = j;
        }   
    }   
    /*
    int n = s.size();
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  
            ++j;
        pi[i] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
             int j = pi[i - 1];
             while (j > 0 && c != s[j])
                 j = pi[j-1];
             if (c == s[j])  
                ++j;
             mem[i][c - 'a'] = j;
        }   
    }
    */  
}   
int pb[M], pc[M];
int memb[M][C], memc[M][C];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> a >> b >> c;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < M; ++k)
                dp[i][j][k] = -INF;
    calc(b, pb, memb); 
    calc(c, pc, memc);
    dp[0][0][0] = 0;
    for (int i = 0; i < a.size(); ++i) 
        for (int j = 0; j <= b.size(); ++j) 
            for (int k = 0; k <= c.size(); ++k) 
                for (char add = 0; add < C; ++add) 
                    if (a[i] == '*' || a[i] == 'a' + add) 
                        upd(dp[i + 1][memb[j][add]][memc[k][add]], dp[i][j][k] + (memb[j][add] == b.size()) - (memc[k][add] == c.size()));
    int ans = -INF;
    for (int i = 0; i < M; ++i) 
        for (int j = 0; j < M; ++j)
            upd(ans, dp[a.size()][i][j]);
    cout << ans << '\n';            
}