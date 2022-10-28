//https://codeforces.com/contest/1362/problem/0
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
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
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"0\n";
        return;
    }
    int count1=0;
    int count2=0;
    while((a&1)==0){
        a>>=1;
        count1++;
    }
    while((b&1)==0){
        b>>=1;
        count2++;
    }
    if(a!=b){
        cout<<"-1\n";
        return;
    }
    cout<<(abs(count1-count2)-1)/3 + 1<<"\n";
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