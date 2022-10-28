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
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> dp(n);
    for(int i=0,z=-1,o=-1;i<n;i++){
        if(s[i]=='0'){
            z=i;
        }
        else if(s[i]=='1'){
            o=i;
        }
        dp[i] = i - min(z,o);
    }
    //cout+dp;
    for(int x=1;x<=n;x++){
        int idx = 0;
        int ans = 0;
        while(idx<n){
            if(dp[idx]>=x){
                ++ans;
                idx+=x;
            }
            else{
                idx+=x-dp[idx];
            }
        }
        cout<<ans<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}