//https://codeforces.com/contest/1363/problem/0
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
    int n,x;
    cin>>n>>x;
    int o=0, e=0;
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        if(y&1){
            ++o;
        }
        else{
            ++e;
        }
    }
    if(x==n){
        cout<< (o&1 ? "Yes\n" : "No\n");
        return;
    }
    if(o==0){
        cout<<"NO\n";
        return;
    }
    if(e==0){
        if(x&1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
        return;
    }
    cout<<"Yes\n";
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