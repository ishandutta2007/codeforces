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
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    sort(a.begin(), a.end());
    int g = 0;
    vector<int> cnt(n);
    for(auto &x : a) cnt[--x]++;
    //cout+cnt;
    for(int i=0;i<n;i++) g = __gcd(g, cnt[i]);
    //cout<<g<<'\n';
    vector<ll> c(g+1), s(g+1);
    vector<int> cntcnt(n+1);
    for(int i=0;i<n;i++) cntcnt[cnt[i]]++;
    vector<int> o;
    for(int i=1;i<=n;i++) if(cntcnt[i] > 0) o.push_back(i);
    for(int i=1;i<=g;i++){
        if(g % i == 0){
            if(g == n){
                c[i] = 1;
                s[i] = n;
                continue;
            }
            c[i] = fact[n/i];
            for(int j : o){
                for(int v=0;v<cntcnt[j];v++) {
                    c[i] *= invfact[j / i];
                    c[i] %= p;
                }
                s[i] += 1ll * cntcnt[j] * j * ((j / i) - 1);
                s[i] %= p;
            }
            s[i] *= modpower((n/i) - 1, p - 2);
            s[i] %= p;
            s[i] *= c[i];
            s[i] %= p;
        }
    }
    //cout+s+c;
    for(int i=g;i>=1;--i){
        for(int j=2*i;j<=g;j+=i){
            s[i] -= s[j];
            c[i] -= c[j];
            if(s[i] < 0) s[i] += p;
            if(c[i] < 0) c[i] += p;
        }
    }
    //cout+s+c;
    for(int i=1;i<=g;i++){
        if(g % i != 0) continue;
        s[i] *= modpower(c[i], p - 2);
        s[i] %= p;
        c[i] *= modpower(n/i, p - 2);
        c[i] %= p;
        s[i] *= c[i];
        s[i] %= p;
    }
    ll tot = accumulate(s.begin(), s.end(), 0ll);
    ll cntp = accumulate(c.begin(), c.end(), 0ll);
    ll ans = tot % p * modpower(cntp, p - 2) % p;
    cout<<(n + p - ans + (g == n)) % p<< "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    computefactorial(1e6 + 7);
    while(t--){
        solve();
    }
}