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
    int n; ll k;
    cin>>n>>k;
    vector<int> seq(n);
    cin>>seq;
    for(const auto &val : seq){
        k+=val;
    }
    auto calc = [&](ll val){
        if(val==0){
            return false;
        }
        ll x = k/val;
        ll curr=0;
        for(const auto &bamboo : seq){
            curr+=(bamboo-1)/val;
        }
        if(curr+n<=x){
            return true;
        }
        return false;
    };
    ll ans = 0;
    for(ll i=1;(i-1)*(i-1)<=k;i++){
        if(calc(i)){
            ans = max(ans, i);
        }
        if(calc(k/i)){
            ans =  max(ans, k/i);
        }
        if(calc(k/i + 1)){
            ans = max(k/i + 1, ans);
        }
        if(calc(k/i - 1)){
            ans = max(ans, k/i - 1);
        }
        ll x = k/(k/i);
        if(calc(x)){
            ans = max(ans, x);
        }
        if(calc(x-1)){
            ans = max(ans, x-1);
        }
        if(calc(x + 1)){
            ans = max(ans, x+1);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}