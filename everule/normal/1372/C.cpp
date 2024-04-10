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
    vector<int> seq(n);
    cin>>seq;
    int ans = 0;
    for(int i=0, chk = 1;i<n;i++){
        if(seq[i]!=i+1){
            chk=0;
        }
        if(chk && i==n-1){
            cout<<"0\n";
            return;
        }
    }
    vector<int> idx;
    for(int i=0, chk = 1;i<n;i++){
        if(seq[i]!=i+1){
            idx.pb(i);
        }
    }
    sort(idx.begin(), idx.end());
    bool chk = 1;
    for(int i=1;i<idx.size();i++){
        if(idx[i] != idx[i-1] + 1){
            chk = 0;
        }
    }
    if(chk){
        cout<<"1\n";
        return;
    }
    cout<<"2\n";
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