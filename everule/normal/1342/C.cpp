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
    int a,b,q;
    cin>>a>>b>>q;
    vector<int> seq(a*b + 1);
    for(int i=0;i<a*b;i++){
        seq[i+1]=seq[i];
        int x=i, y=i;
        x%=a;x%=b;
        y%=b;y%=a;
        if(x!=y){
            ++seq[i+1];
        }
    }
    while(q--){
        ll l,r;
        ll ans=0;
        cin>>l>>r;
        --l;
        ans+= r/(a*b) * seq[a*b] + seq[r%(a*b) + 1];
        ans-= l/(a*b) * seq[a*b] + seq[l%(a*b) + 1];
        cout<<ans<<' ';
    }
    cout<<'\n';
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}