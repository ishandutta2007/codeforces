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
    vector<ll> seq(n);
    int del = 1e9 + 7;
    while(del%n){
        ++del;
    }
    for(auto &x : seq) cin>>x;
    for(auto &x : seq) x+=del;
    if(n==1){
        cout<<"1 1"<<"\n";
        cout<<"0\n";
        cout<<"1 1"<<"\n";
        cout<<"0\n";
        cout<<"1 1"<<"\n";
        cout<<del-seq[0];
        return;
    }
    cout<<"1 "<<n-1<<"\n";
    for(int i=0;i+1<n;i++){
        ll x = (seq[i]%n)*(n-1);
        cout<<x<<" ";
        seq[i]+=x;
    }
    cout<<"\n";
    cout<<n<<" "<<n<<"\n";
    cout<<(seq[n-1]%n)*(n-1)<<"\n";
    seq[n-1]+=(seq[n-1]%n)*(n-1);
    cout<<"1 "<<n<<'\n';
    for(int i=0;i<n;i++){
        cout<<del-seq[i]<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}