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
const int MAXA = 1e6 + 7;
const int p = 1e9 + 7;
ll modpower(ll base, ll power, ll mod=p){
    ll ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
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
    vector<int> cnt(MAXA + 1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    vector<ll> ans(MAXA + 1);
    for(int i=2;i<=MAXA;i++){
        int sum = 0;
        for(int j=i;j<=MAXA;j+=i){
            sum += cnt[j];
        }
        if(sum > 0) ans[i] =sum * modpower(2, sum-1) %p;
    }
    for(int i=MAXA;i>1;--i){
        for(int j=2*i;j<=MAXA;j+=i){
            ans[i] -= ans[j];
            if(ans[i] < 0) ans[i] += p;
        }
    }
    ll fin = 0;
    for(int i=2;i<=MAXA;i++){
        fin += ans[i]  * i;
        fin %= p;
    }
    cout<<fin<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}