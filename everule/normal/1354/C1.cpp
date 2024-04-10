//https://codeforces.com/contest/1354/problem/C1
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
const long double pi = 3.141592653589793238;
void solve(){
    int n;
    cin>>n;
    n*=2;
    long double theta=(n-2)*pi;
    theta/=n;
    theta=pi-theta;
    long double ans=0;
    n/=2;
    long double currangle=0;
    for(int i=1;i<n;i++){
        currangle+=theta;
        ans+=sin(currangle);
    }
    cout<<fixed<<setprecision(9)<<ans<<"\n";
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