//https://codeforces.com/contest/1355/problem/C
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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll box1=b-a;
    ll box2=c-b;
    if(box1>box2){
        swap(box1, box2);
    }
    ll ans=0;
    for(ll i=a+b;i<=b+c;i++){
        if(i<c){
            continue;
        }
        ll poss=i-c;
        poss=min(poss, d-c+1);
        ll objects=i-a-b;
        if(objects<=box1){
            ans+=(objects+1)*poss;
        }
        else if(objects<=box2){
            ans+=(box1+1)*poss;
        }
        else{
            ans+=(box1+box2-objects+1)*poss;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}