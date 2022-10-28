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
    ll n,k;
    cin>>n>>k;
    ll l1, r1, l2, r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1>l2){
        swap(l1,l2);
        swap(r1,r2);
    }
    ll base, single, def;
    if(r2<r1){
        base = 0;
        def = r2 - l2;
        single = (r1-l1) - (r2 - l2);
    }
    else if(l2<r1){
        base = 0;
        def = r1 - l2;
        single = (l2 - l1) + (r2 - r1);
    }
    else{
        def=0;
        base = l2 - r1;
        single = r2 - l1;
    }
    ll fin = 1e18;
    for(int i=1;i<=n;i++){
        k-=def;
        ll ans = base*i;
        if(k<=single*i){
            ans+=k;
        }
        else{
            ans+=single*i;
            ans+=(k-single*i)*2;
        }
        fin = min(fin, ans);
    }
    cout<<max(fin,0ll)<<"\n";
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