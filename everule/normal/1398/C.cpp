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
    map<int,int> cntmap;
    int n;
    cin>>n;
    ll ans = 0;
    string s;
    cin>>s;
    cntmap[0] = 1;
    for(int i=0,pref=0;i<n;i++){
        pref+=s[i] - '0';
        cntmap[pref - i - 1]++;
    }
    for(const auto &[val, cnt] : cntmap){
        ans+=(ll)cnt*(cnt-1)/2;
    }
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