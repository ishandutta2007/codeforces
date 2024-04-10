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
const int p = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> f(n + m + 1);
    f[0] = f[1] = 1;
    for(int i=2;i<f.size();i++){
        f[i] = f[i-1] + f[i-2];
        f[i] %= p;
    }
    ll ans = (2 * (f[n] + f[m] - 2) + 2) % p;
    if(ans < 0) ans += p;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}