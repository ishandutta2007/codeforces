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
    string s,t;
    cin>>s>>t;
    vector<int> op;
    for(int l=0,r=n-1,idx=n-1;l<=r;){
        if(s[l] ==t[idx]){
            op.pb(1);
        }
        op.pb(r-l+1);
        l++;
        --idx;
        if(idx<0){
            break;
        }
        if(s[r] != t[idx]){
            op.pb(1);
        }
        op.pb(r-l+1);
        --idx;
        --r;
    }
    cout<<op.size()<<" ";
    for(const auto &o : op){
        cout<<o<<" ";
    }
    cout<<"\n";
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