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
const int MAXA = 100007;
const int p = 998244353;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a;
    sort(a.begin(), a.end());
    //ah g <= MAXA / k * nk = O(n * MAXA) :floshed:
    vector<ll> ans(MAXA + 1);
    for(int g=0;g <= (MAXA/(k-1)) + 1;g++){
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = 0;
        dp[0][0] = 1;
        for(int i=0,j=0;i<n;i++){
            while(j < i && a[i] - a[j] >= g){
                ++j;
            }
            //cout<<i<<" "<<j<<"\n";
            for(int l=1;l<=k;l++){
                dp[i+1][l] += dp[j][l-1];
                if(dp[i+1][l] >= p) dp[i+1][l] -= p;
            }
            for(int l=0;l<=k;l++){
                dp[i+1][l] += dp[i][l];
                if(dp[i+1][l] >= p) dp[i+1][l] -= p;
            }
        }
        //cout*dp<<"\n";
        ans[g] = dp[n][k];
    }
    //cout+ans;
    for(int g=0;g<MAXA;g++){
        ans[g] -= ans[g+1];
        if(ans[g] < 0) ans[g] += p;
    }
    ll fin = 0;
    for(int g=0;g<=MAXA;g++){
        fin += g * ans[g];
        fin %= p;
    }
    cout<<fin<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}