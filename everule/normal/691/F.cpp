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
const int MAXA = 3e6 + 7; 
void solve(){
    ll n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> count(MAXA + 1);
    for(const auto &x : seq){
        ++count[x];
    }
    vector<ll> ans(MAXA + 1);
    for(int i=1;i<=MAXA;i++){
        for(int j=1;j*i<=MAXA;j++){
            ans[i*j]+=count[i]*(count[j]-(i==j));
        }
    }
    for(int i=1;i<=MAXA;i++){
        ans[i]+=ans[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int j;
        cin>>j;
        cout<<n*(n-1)  - ans[j-1]<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}