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
    string s;
    cin>>s;
    int n = s.size();
    vector<int> prefixsum(n+1);
    int mn = 0;
    for(int i=1;i<=n;i++){
        prefixsum[i] = prefixsum[i-1] + (s[i-1]=='+' ? 1 : -1);
        mn = min(mn, prefixsum[i]);
    }
    vector<int> seq(-mn + 1, 1e9);
    seq[0] = n;
    for(int i=1;i<=n;i++){
        if(prefixsum[i]<0){
            int idx = -prefixsum[i];
            seq[idx] = min(seq[idx], i);
        }
    }
    ll ans = 0;
    for(const auto &val : seq){
        ans+=val;
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