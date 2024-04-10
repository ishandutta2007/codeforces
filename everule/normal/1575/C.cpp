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
ll modpower(ll base, ll power, ll mod){
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
const int mod = 1e9 + 7;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    cin>>a;
    vector<ll> p(n+1);
    for(int i=1;i<=n;i++) p[i] = (p[i-1] + a[i-1]) % k;
    vector<ll> fcnt(k);
    if(p[n] == 0){
        for(int i=0;i<n;i++) fcnt[p[i]] += m;
    }
    else{
        ll inv = modpower(p[n], k-2, k);
        for(int i=0;i<=n;i++){
            p[i] *= inv;
            p[i] %= k;
        }
        ll all = 1ll * (m / k) * n;
        int len = m % k;
        vector<ll> cnt(k);
        for(int i=0;i<n;i++) cnt[p[i]]++;
        vector<ll> pcnt(k+1);
        for(int i=1;i<=k;i++) pcnt[i] = pcnt[i-1] + cnt[i-1];
        auto get_sum = [&](int l, int r){
            if(l < 0){
                return pcnt[k] - pcnt[l+k] + pcnt[r+1];
            }
            else{
                return pcnt[r+1] - pcnt[l];
            }
        };
        for(int i=0;i<k;i++) fcnt[i] = get_sum(i - len + 1, i) + all;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        fcnt[p[i]]--;
        fcnt[(p[i] + p[n] * m) % k]++;
        ans += fcnt[p[i]] * m;
        ans %= mod;
    }
    ans -= (p[n] * m % k == 0) * (1ll * n * m - 1);
    ans %= mod;
    if(ans < 0) ans += mod;
    ans %= mod;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}