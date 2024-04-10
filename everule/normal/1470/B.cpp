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
vector<int> nor;
void sieve(const int n){
    nor.resize(n + 1);
    iota(nor.begin(), nor.end(), 0);
    for(ll i=2;i*i<=n;i++){
        for(ll j=i*i;j<=n;j+=i*i){
            nor[j] = nor[j/i/i];
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    map<int,int> ans;
    for(auto &x : seq){
        ans[nor[x]]++;
    }
    int mx=0;
    int ansl = 0;
    for(auto &[a,b] : ans){
        mx = max(mx, b);
        if(b%2 == 0 || a==1) ansl += b;
    }
    int q;
    cin>>q;
    while(q--){
        ll w;
        cin>>w;
        if(w == 0){
            cout<<mx<<"\n";
        }
        else{
            cout<<max(mx,ansl)<<"\n";
        }
    }
    //cout+nor;
}
const int MAXA = 1e6 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    sieve(MAXA);
    while(t--){
        solve();
    }
}