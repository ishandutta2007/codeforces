//https://codeforces.com/contest/1358/problem/D
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
    ll n,x;
    cin>>n>>x;
    vector<ll> seq(n);
    cin>>seq;
    for(int i=0;i<n;i++){
        seq.pb(seq[i]);
    }
    auto sumtill = [&](ll x){
        return x*(x+1)/2;
    };
    ll currdays=0;
    ll currans=0;
    ll finans=-1;
    for(int i=0,j=0;i<2*n;i++){
        currdays+=seq[i];
        currans+=sumtill(seq[i]);
        while(j<=i && currdays>x){
            currdays-=seq[j];
            currans-=sumtill(seq[j]);
            ++j;
        }
        if(j==0){
            if(currdays==x){
                finans=max(finans, currans);
            }
            continue;
        }
        ll thisans=currans + sumtill(seq[j-1]) - sumtill(seq[j-1] - (x-currdays));
        finans= max(finans, thisans);
    }
    cout<<finans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}