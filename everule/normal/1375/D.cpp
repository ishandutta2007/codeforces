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
int MEX(const vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
bool check(const vector<int> &seq){
    for(int i=0;i<seq.size();i++){
        if(seq[i]!=i){
            return 0;
        }
    }
    return 1;
}
int find(vector<int> &seq){
    for(int i=0;i<seq.size();i++){
        if(seq[i]!=i){
            seq[i] = seq.size();
            return i;
        }
    }
    return -1;
}
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    vector<int> ans;
    cin>>seq;
    int count = 2*n;
    int cnt = 0;
    while(!check(seq)){
        int m = MEX(seq);
        if(m!=n){
            seq[m] = m;
            ans.pb(m + 1);
        }
        else{
            ans.pb(find(seq) + 1);
        }
        ++cnt;
    }
    cout<<ans.size()<<"\n";
    cout+ans;
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