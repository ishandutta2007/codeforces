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
const int MAXA = (1<<20);
const int lg = 20;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    int ans = 0;
    for(int b=0;b<20;b++){
        vector<array<int, 2>> lst((MAXA>>b), {-2, -2});
        int pxr = 0;
        lst[0][0] = 0;
        for(int i=0,j=0;i<n;i++){
            pxr ^= (a[i] >> b);
            int bit = (a[i] >> b) & 1;
            if(bit == 1 && lst[pxr][(i+1)%2] >= j){
                ans = max(ans, i - lst[pxr][(i+1)%2] + 1);
            }
            if(bit == 0){
                j = i + 1;
            }
            if(lst[pxr][(i+1)%2] < j) lst[pxr][(i+1)%2] = i + 1;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}