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
const int INF = 1e9 + 7;
const int N = 15;
int dp[3][N+1][N+1][(1<<N)];
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> sum(1<<n);
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1) sum[i] += seq[j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<(1<<n);k++){
                dp[0][i][j][k] = INF;
            }
        }
    }
    for(int i=0;i<=n;i++) dp[0][0][i][0] = -1;
    for(int l=1;l<=n;l++){
        for(int m=0;m<(1<<n);m++){
            for(int i=0;i<n;i++){
                if(dp[0][l-1][i][m] == INF) continue;
                for(int s=((1<<n) - 1) ^ m;s>=(1<<i);--s, s &= ~m){
                    if(sum[s] > dp[0][l-1][i][m]){
                        int b = __builtin_ctz(s >> i) + i + 1;
                        if(sum[s] < dp[0][l][b][m|s]){
                            dp[0][l][b][m|s] = sum[s];
                            dp[1][l][b][m|s] = m;
                            dp[2][l][b][m|s] = i;
                        }   
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int m=0;m<(1<<n);m++){
                if(dp[0][l][i-1][m] < dp[0][l][i][m]){
                    dp[0][l][i][m] = dp[0][l][i-1][m];
                    dp[1][l][i][m] = dp[1][l][i-1][m];
                    dp[2][l][i][m] = dp[2][l][i-1][m];
                }
            }
        }
    }
    int l = n;
    while(l){
        if(dp[0][l][n][(1<<n) - 1] == INF) --l;
        else break;
    }
    vector<int> ans;
    int x = n, y = (1<<n) - 1;
    while(y){
        int ny = dp[1][l][x][y];
        int nx = dp[2][l][x][y];
        ans.push_back(y ^ ny);
        x = nx;
        y = ny;
        --l;
    }
    reverse(ans.begin(), ans.end());
    l = ans.size();
    int curr = 0;
    vector<int> sb(l);
    for(int i=0;i<l;i++){
        sb[i] = __builtin_ctz(ans[i] >> curr) + curr;
        curr = sb[i];
    }
    cout<<n - l<<"\n";
    vector<int> rl(n);
    iota(rl.begin(), rl.end(), 0);
    for(int i=0;i<l;i++){
        for(int j=0;j<n;j++){
            if(j == sb[i]) continue;
            if(~ans[i] & (1<<j)) continue;
            cout<<rl[j] + 1<<" "<<rl[sb[i]] + 1<<"\n";
            for(int k=j+1;k<n;k++) --rl[k];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}