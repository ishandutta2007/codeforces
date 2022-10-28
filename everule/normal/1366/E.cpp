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
const int p =998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    cin>>a>>b;
    vector<int> suffixmin(n+1);
    suffixmin[n]=1e9+7;
    for(int i=n-1;i>=0;--i){
        suffixmin[i]=min(suffixmin[i+1], a[i]);
    }
    vector<int> ans(m);
    ans[0]=(suffixmin[0]==b[0]);
    for(int i=0,j=1;i<n;i++){
        if(j<m && suffixmin[i]>b[j]){
            ++j;
        }
        if(suffixmin[i]==b[j]){
            ans[j]++;
        }
    }
    ll fin=1;
    for(const auto x : ans){
        fin*=x;
        fin%=p;
    }
    cout<<fin<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}