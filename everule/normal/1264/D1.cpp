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
ll ncr(int n,int r){
    if(n<0 || r>n || r<0) return 0;
    return fact[n] * invfact[n-r]%p * invfact[r]%p;
}
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int o = count(s.begin(), s.end(), '(');
    int c = count(s.begin(), s.end(), ')');
    int q = n - o - c;
    int l = 0;
    ll ans = 0;
    int ocurr = 0;
    for(int i=1;i<n;i++){
        if(s[i-1] == '?') ++l;
        if(s[i-1] == '(') ++ocurr;
        if(i < n-o-q || i > n-o) continue;
        int oc = n-o-i;
        ans += ncr(q, oc) * ocurr;
        ans += l * ncr(q - 1, oc - 1);
        ans%=p;
    }
    cout<<ans<<"\n";
}
const int MAXN = 1e6 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computefactorial(MAXN);
    solve();
}