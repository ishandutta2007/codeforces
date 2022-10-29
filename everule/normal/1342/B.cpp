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
    string t;
    cin>>t;
    int n=t.size();
    int count0=0, count1=0;
    for(int i=0;i<n;i++){
        if(t[i]=='0'){
            count0++;
        }
        else{
            count1++;
        }
    }
    if(count0==n){
        for(int i=0;i<n;i++){
            cout<<'0';
        }
        cout<<'\n';
        return;
    }
    if(count1==n){
        for(int i=0;i<n;i++){
            cout<<'1';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<2*n;i++){
        cout<< (i&1 ? '1' : '0');
    }
    cout<<'\n';
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