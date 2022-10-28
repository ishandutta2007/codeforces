#include <iostream>
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
    ll n,m,x,y;
    string s,t;
    cin>>n>>m>>s>>t;
    x = s.size();
    y = t.size();
    assert(n*x == m*y);
    ll repeat = __gcd(n,m);
    ll sets = __gcd(x,y);
    vector<array<int, 26>> count(sets);
    ll total = x/__gcd(x,y);
    for(int i=0;i<x;i++){
        count[i%sets][s[i] - 'a']++;
    }
    ll ans = 0;
    for(int i=0;i<y;i++){
        ans+=total - count[i%sets][t[i] - 'a'];
    }
    ans*=repeat;
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}