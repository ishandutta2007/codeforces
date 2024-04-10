//https://codeforces.com/contest/1359/problem/B
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
pair<int,int> operator+(const pair<int,int> &x, const pair<int,int> &y){
    return mp(x.first + y.first,x.second + y.second);
}
void solve(){
    const vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    y=min(y, 2*x);
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char type;
            cin>>type;
            vis[i][j]=(type=='*');
        }
    }
    auto valid = [&](const pair<int,int> &x){
        return x.first>=0 && x.first<n && x.second<m && x.second>=0;
    };
    ll ans=0;
    for(int i=0;i<n;i++){
        int len=0;
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                ++len;
            }
            else{
                ans+=y*(len/2) + x*(len&1);
                len=0;
            }
        }
        ans+=y*(len/2) + x*(len&1);
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