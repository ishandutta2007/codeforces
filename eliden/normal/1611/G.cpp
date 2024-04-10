#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
using ll = long long;
template<typename T, typename ...Args>
void print(T arg, Args&&... args) {
    cout << arg;
    ((cout << " " << args ), ...);
    cout << "\n";
}
template<typename ...Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tests;
    read(tests);
    rep(test,0,tests) {
        int n,m; read(n,m);
        vector<string> data(n);
        rep(i,0,n) read(data[i]);
        if(n%2==1) {
            ++n;
            data.push_back("");
            rep(j,0,m) data[n-1]+='0';
        }
        vector<vector<int>> dp(n, vector<int>(m));
        vector<int> ans(2);
        for(int j=m-1; j>=0;--j) {
            rep(i,0,n) {
                int a = 0;
                if(j+1 < m && i-1>=0) a = max(a,dp[i-1][j+1]);
                if(j+1 < m && i+1 < n) a = max(a,dp[i+1][j+1]);
                int b = data[i][j]-'0';
                if(j+2 < m) b+=dp[i][j+2];
                dp[i][j]=max(a,b);
                if(j==0) ans[i%2]=max(ans[i%2],dp[i][j]);
            }
        }
        print(ans[0]+ans[1]);
    }
}