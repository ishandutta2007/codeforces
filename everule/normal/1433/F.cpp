#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
const int INF = 1e8;
const int MAXV = 70;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> seq(n, vector<int>(m));
    cin>>seq;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(MAXV * m + 1, INF)));
    vector<vector<int>> c(n, vector<int>(k, -INF));
    for(int i=0;i<n;i++){
        dp[i][0][0] = 0;
        for(int j=1;j<=m;j++){
            for(int l=0;l<=MAXV*m;l++){
                dp[i][j][l] = dp[i][j-1][l];
                if(l >= seq[i][j-1]) dp[i][j][l] = min(dp[i][j][l], dp[i][j-1][l-seq[i][j-1]] + 1);
            }
        }
        for(int l=0;l<=MAXV*m;l++){
            if(dp[i][m][l] <= m/2) c[i][l%k] = max(c[i][l%k], l);
        }
    }
    vector<vector<int>> go(n+1 , vector<int>(k, -INF));
    go[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int k1 = 0;k1 < k;k1++){
            for(int k2 = 0;k2 < k;k2++){
                go[i][(k1 + k2)%k] = max(go[i][(k1 + k2)%k], c[i-1][k1] + go[i-1][k2]);
            }
        }
    }
    cout<<go[n][0]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}