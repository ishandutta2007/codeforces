#include <iostream>
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
const int p = 998244353;
ll modpower(ll base, ll power){
    ll ans =1;
    base%=p;
    while(power){
        if(power&1){
            ans*=base;
            ans%=p;
        }
        base*=base;
        base%=p;
        power>>=1;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> diff(n);
    cin>>diff;
    if(n==1){
        cout<<diff[0]<<"\n";
        return;
    }
    vector<ll> prefsum(n+1);
    for(int i=1;i<=n;i++){
        prefsum[i] = prefsum[i-1] + diff[i-1];
        prefsum[i]>=p ? prefsum[i]-=p :0;
    }
    const int inv2 = (p+1)/2;
    ll currinv2 = (p+1)/2;
    vector<ll> dp(n+1);
    ll currdpsum = 0;
    ll currdiffsum = 0;
    for(int i=1;i<=n;i++){
        currdiffsum+=prefsum[i]*currinv2;
        currdiffsum%=p;
        dp[i] = currdpsum + currdiffsum;
        dp[i]>=p ? dp[i]-=p : 0;
        dp[i] += (prefsum[i]*currinv2);
        dp[i]%=p;
        currinv2*=inv2;
        currinv2%=p;
        currdpsum+=dp[i];
        currdpsum>=p ? currdpsum-=p : 0;
        currdpsum*=inv2;
        currdpsum%=p;
    }
    cout<<(dp[n]*modpower(2,n-1))%p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}