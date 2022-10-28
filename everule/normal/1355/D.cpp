//https://codeforces.com/contest/1355/problem/D
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
    int n,s;
    cin>>n>>s;
    if(s<2*n){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    if(n==1){
        cout<<s<<"\n";
        cout<<"1"<<'\n';
        return;
    }
    vector<int> seq(n);
    for(int i=0;i<n-1;i++){
        seq[i]=2;
        s-=2;
    }
    seq[n-1]=s;
    cout+seq;
    cout<<1<<"\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}