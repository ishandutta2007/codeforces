//https://codeforces.com/contest/1354/problem/B
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
    int ans=1e9;
    vector<vector<int>> prefixsum(n+1, vector<int>(3));
    for(int i=0, j=0;i<n;i++){
        for(int k=0;k<3;k++){
            prefixsum[i+1][k]=prefixsum[i][k] + (s[i]-'1'==k);
        }
        while(j<n){
            bool flag=1;
            for(int k=0;k<3;k++){
                if(prefixsum[i+1][k]-prefixsum[j+1][k]==0){
                    flag=0;
                }
            }
            if(!flag){
                break;
            }
            ++j;
        }
        bool flag=1;
        for(int k=0;k<3;k++){
            if(prefixsum[i+1][k]-prefixsum[j][k]==0){
                flag=0;
            }
        }
        if(flag){
            ans=min(ans, i-j+1);
        }
    }
    if(ans>n){
        cout<<"0\n";
    }
    else{
        cout<<ans<<"\n";
    }
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