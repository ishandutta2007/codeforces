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
int cnt = 0;
ll inv(ll a, ll n){
    if(a == 0){
        return 0;
    }
    if(a == 1){
        return 1;
    }
    return ((1 - inv(n % a, a) * n) / a) % n;
}
void solve(){
    int t, n;
    cin>>t>>n;
    vector<ll> p(n);
    cin>>p;
    vector<ll> a(n);
    a[0] = 0;
    for(int i=1;i<n;i++) a[i] = a[i-1] + p[i];
    ll sum = a[n-1] + p[0];
    for(int i=0;i<n;i++) a[i] %= t;
    ll g = gcd(sum, t);
    map<int, vector<ll>> sp;
    sum /= g;
    for(int i=0;i<n;i++) sp[a[i] % g].push_back(i);
    t /= g;
    ll finv = inv(sum % t, t);
    if(finv < 0) finv += t;
    //assert(finv * sum % t == 1);
    //cout<<finv<<" "<<sum<<"\n";
    vector<ll> ans(n);
    auto spsolve = [&](vector<ll> v){
        if(v.size() == 0) return;
        if(v.size() == 1) return void(ans[v[0]] = t);
        for(auto &x : v) a[x] /= g;
        for(auto &x : v) a[x] *= finv;
        for(auto &x : v) a[x] %= t;
        vector<int> o(v.size());
        iota(o.begin(), o.end(), 0);
        stable_sort(o.begin(), o.end(), [&](int x, int y){
            return a[v[x]] < a[v[y]];
        });
        vector<int> o2;
        o2.push_back(o[0]);
        for(int i=1;i<o.size();i++){
            if(a[v[o2.back()]] == a[v[o[i]]]) assert(o2.back() < o[i]);
            else o2.push_back(o[i]);
        }
        if(o2.size() == 1) return void(ans[v[o2[0]]] = t);
        for(int i=0;i+1<int(o2.size());i++){
            ans[v[o2[i]]] = a[v[o2[i+1]]] - a[v[o2[i]]];
        }
        ans[v[o2.back()]] = a[v[o2[0]]] + t - a[v[o2.back()]];
    };
    for(auto &[g,v] : sp) spsolve(v);
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}