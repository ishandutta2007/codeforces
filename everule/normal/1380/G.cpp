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
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=p;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    sort(seq.begin(), seq.end(), greater<int>());
    vector<ll> prefixsum(n+1);
    for(int i=1;i<=n;i++){
        prefixsum[i] = prefixsum[i-1] + seq[i-1];
    }
    ll invn = modpower(n, p-2);
    for(int k=1;k<=n;k++){
        ll ans = 0;
        int j=0;
        while(j+k<=n){
            ans += j/k * (prefixsum[j+k] - prefixsum[j]);
            j+=k;
        }
        ans+= j/k * (prefixsum[n] - prefixsum[j]);
        ans%=p;
        ans*=invn;
        ans%=p;
        cout<<ans<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}