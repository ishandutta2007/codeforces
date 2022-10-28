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
ll kadane(const vector<int> &seq){
    ll currans = 0;
    ll ans = 0;
    for(const auto &val : seq){
        currans+=val;
        if(currans<0){
            currans=0;
        }
        ans = max(currans, ans);
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    ll ans = 0;
    for(int i=0;i<n;i+=2){
        ans+=seq[i];
    }
    vector<int> kadane1;
    vector<int> kadane2;
    for(int i=0;i+1<n;i+=2){
        kadane1.pb(seq[i+1] - seq[i]);
    }
    for(int i=1;i+1<n;i+=2){
        kadane2.pb(seq[i] - seq[i+1]);
    }
    ans = max({ans, ans + kadane(kadane1), ans + kadane(kadane2)});
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