//https://codeforces.com/contest/1363/problem/B
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
    string s;
    cin>>s;
    int n=s.size();
    int count1=0, count0=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            count0++;
        }
        else{
            count1++;
        }
    }
    int ans=min(count0, count1);
    for(int i=0, j=count1;i<n;i++){
        if(s[i]=='1'){
            --j;
        }
        else{
            ++j;
        }
        ans=min(ans, j);
    }
    for(int i=0, j=count0;i<n;i++){
        if(s[i]=='0'){
            --j;
        }
        else{
            ++j;
        }
        ans=min(ans, j);
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