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
void solve(){
    int n;
    cin>>n;
    ll k;
    cin>>k;
    vector<ll> x(n);
    cin>>x;
    sort(x.begin(), x.end());
    for(int i=1;i<n;i++) x[i] -= x[0];
    ll g = x[1];
    for(int i=2;i<n;i++) g = gcd(g, x[i]);
    if((k  - x[0]) % g){
        cout<<"No\n";
    }
    else{
        cout<<"YES\n";
    }
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