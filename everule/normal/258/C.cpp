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
const int MAXA = 1e5 + 7;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> count(MAXA + 1);
    for(const auto &x : seq) count[x]++;
    for(int i=MAXA-1;i>=1;--i) count[i]+=count[i+1];
    vector<vector<int>> divisors(MAXA + 1);
    for(int i=1;i<=MAXA;i++){
        for(int j=i;j<=MAXA;j+=i){
            divisors[j].pb(i);
        }
    }
    vector<ll> ans(MAXA + 1);
    ans[1] = 1;
    for(int i=2;i<=MAXA;i++){
        const vector<int>& div = divisors[i];
        int d = div.size();
        vector<int> power(d+1);
        power[0] = n;
        for(int i=0;i<d;i++){
            power[i+1]+=count[div[i]];
            power[i]-=count[div[i]];
        }
        //cout+power;
        ans[i] = 1;
        for(int j=1;j<d;j++){
            ans[i]*=modpower(j, power[j]);
            ans[i]%=p;
        }
        ans[i]*=modpower(d, power[d]) - modpower(d-1, power[d]);
        ans[i]%=p;
        ans[i]<0 ? ans[i]+=p : 0;
    }
    //cout+ans;
    cout<<accumulate(ans.begin(), ans.end(), 0ll)%p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}