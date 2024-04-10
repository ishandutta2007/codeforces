//https://codeforces.com/contest/1353/problem/B
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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    cin>>a>>b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for(int i=0;i<k;i++){
        a.pb(b[i]);
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
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