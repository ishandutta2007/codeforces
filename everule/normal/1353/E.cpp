#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb emplace_back
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
    string s;
    cin>>s;
    int countone=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ++countone;
        }
    }
    int ans=1e9;
    for(int i=0;i<k;i++){
        int currzero=0;
        int currone=0;
        vector<int> curr;
        for(int j=i;j<n;j+=k){
            curr.pb(s[j]=='0' ? -1 : 1);
            if(s[j]=='0'){
                ++currzero;
            }
            else{
                ++currone;
            }
        }
        int mn=0;
        int prefix=0;
        for(int j=0;j<curr.size();j++){
            prefix+=curr[j];
            mn=min(mn, prefix);
            ans=min(ans,(int)curr.size() - prefix + mn + countone - currone - currzero);
        }
    }
    std::cout<<ans<<"\n";
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