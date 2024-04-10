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
vector<ll> fact;
vector<ll> invfact;
void computefactorial(int n){
    ++n;
    fact.resize(n);
    invfact.resize(n);
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=p;
    }
    invfact[n-1]=modpower(fact[n-1],p-2);
    for(int i=n-2;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1];
        invfact[i]%=p;
    }
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<bool> next(n);
    vector<int> next2;
    vector<int> gaps;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(v-u !=1 && v-u != k+1){
            cout<<"0\n";
            return;
        }
        if(v-u==1){
            next[u]=1;
        }
        else{
            next2.pb(--u);
        }
    }
    sort(next2.begin(), next2.end());
    if(next2.size()!=0){
        if(next2.back() - next2[0] > k){
            cout<<"0\n";
            return;
        }
        int l = next2[0], r = next2.back();
        ll ans = 0;
        n-=k+1;
        for(int i=0;i<n;i++){
            if(i>l || i+k<r) continue;
            int pos = min(n-i-1, k);
            ans+=modpower(2, pos - next2.size() + binary_search(next2.begin(), next2.end(), i));
        }
        cout<<ans%p<<"\n";
        return;
    }
    ll ans = 1;
    n-=k+1;
    for(int i=0;i<n;i++){
        int pos = min(n-i-1, k);
        ans+=modpower(2, pos);
    }
    cout<<ans%p<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}