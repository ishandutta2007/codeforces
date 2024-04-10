#include <bits/stdc++.h>
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
int dp[21][(1<<20)];
int ndp[21][(1<<20)];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    cin>>s;
    for(int i=0;i<m;i++){
        int mask = 0;
        for(int j=0;j<n;j++){
            mask += (1<<j) * (s[j][i] == '1');
        }
        dp[0][mask]++;
    }
    for(int len=0;len<n;len++){
        for(int sum=0;sum<n;sum++){
            for(int msk=0;msk<(1<<n);msk++){
                int msk_0 = msk & ~(1<<len);
                int msk_1 = msk | (1<<len);
                int bit = (msk >> len) & 1;
                ndp[sum + bit][msk_0] += dp[sum][msk];
                ndp[sum + !bit][msk_1] += dp[sum][msk];
            }
        }
        swap(dp, ndp);
        memset(ndp, 0, sizeof(ndp));
    }
    //0110
    //101000
    //
    int ans = int(1e9);
    for(int msk=0;msk<(1<<n);msk++){
        int curr = 0;
        for(int sum=0;sum<=n;sum++){
            curr += dp[sum][msk] * min(sum, n - sum);
        }
        ans = min(ans, curr);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}