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
const int MAXA = (1<<20) - 1;
const int bits = 20;
void solve(){
    int n;
    cin>>n;
    vector<int> bitcount(bits);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int j=0;j<bits;j++){
            if(x & (1<<j)){
                ++bitcount[j];
            }
        }
    }
    vector<ll> ans(n);
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<bits;j++){
            if(bitcount[j] >= n - i){
                ans[i]|=(1<<j);
            }
        }
    }
    ll fin = 0;
    for(int i=0;i<n;i++){
        fin+=ans[i]*ans[i];
    }
    cout<<fin;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}