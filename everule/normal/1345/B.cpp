#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
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
ll solve(ll h){
    return (3*h*h + h)/2;
}
void makepyramid(ll &n){
    ll mx=1e5;
    ll mn=0;
    while(mn<mx){
        int mid=mn+mx+1;
        mid>>=1;
        if(solve(mid)<=n){
            mn=mid;
        }
        else{
            mx=mid-1;
        }
    }
    n-=solve(mn);
}
void solve(){
    ll n;
    cin>>n;
    int ans=0;
    while(n>1){
        makepyramid(n);
        ++ans;
    }
    cout<<ans<<'\n';
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