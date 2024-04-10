#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000 + 1;
int dp[maxn][maxn][2][2];
int vis[maxn][maxn][2][2];
int DP(int a, int b, int c, int d){
    if(vis[a][b][c][d]) return dp[a][b][c][d];
    vis[a][b][c][d] = 1;
    int& tmp = dp[a][b][c][d] = maxn;
    if(a + b + c == 0) tmp = 0;
    if(b and d) tmp = min(tmp, -DP(a, b, c, 0));
    if(a) tmp = min(tmp, -DP(a - 1, b + 1, c, 1) + 1);
    if(b) tmp = min(tmp, -DP(a, b - 1, c, 1) + 1);
    if(c) tmp = min(tmp, -DP(a, b, c - 1, 1) + 1);
    //cout << a << " " << b << " " << c << " " << d << " " << tmp << endl;
    return tmp;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        string s;
        cin >> n >> s;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i * 2 + 1 < n; i += 1){
            if(s[i] == '0' and s[n - 1 - i] == '0') a += 1;
            if(s[i] != s[n - 1 - i]) b += 1;
        }
        if(n & 1 and s[n / 2] == '0') c = 1;
        int D = DP(a, b, c, 1);
        //cout << a << " " << b << " " << c << " " << 1 << " " << D << endl;
        if(D > 0) cout << "BOB\n";
        else if(D == 0) cout << "DRAW\n";
        else cout << "ALICE\n";
    }
	return 0;
}