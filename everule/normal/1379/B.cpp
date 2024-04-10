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
    ll l,r,m;
    cin>>l>>r>>m;
    for(int a=l;a<=r;a++){
        int rem = m%a;
        bool k = 0;
        if(m<a || rem > a-rem){
            rem = a-rem;
            k=1;
        }
        if(rem<=r-l){
            int b = l + rem;
            int c = l;
            if(k){
                swap(b,c);
            }
            cout<<a<<" "<<b<<" "<<c<<"\n";
            return;
        }
    }
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