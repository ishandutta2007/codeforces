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
const int INF = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    int g = 0;
    vector<int> a(n), b(m);
    cin>>a>>b;
    for(auto x : b) g = __gcd(g, x);
    vector<ll> sum(g);
    vector<int> parity(g, 1);
    vector<int> mn(g, INF);
    for(int i=0;i<g;i++){
        for(int j=i;j<n;j+=g){
            sum[i] += abs(a[j]);
            mn[i] = min(mn[i], abs(a[j]));
            if(a[j] < 0) parity[i] *= -1;
            if(a[j] == 0) parity[i] *= 0;
        }
    }
    ll ans = 0;
    ll p1loss = 0, p2loss = 0;
    for(int i=0;i<g;i++){
        if(parity[i] == 1) p1loss += 2 * mn[i];
        if(parity[i] == -1) p2loss += 2 * mn[i];
    }
    ans = accumulate(sum.begin(), sum.end(), 0ll) - min(p1loss, p2loss);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}