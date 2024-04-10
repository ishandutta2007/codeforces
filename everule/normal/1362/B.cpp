//https://codeforces.com/contest/1362/problem/B
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
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    sort(seq.begin(), seq.end());
    for(int k=1;k<(1<<10);k++){
        vector<int> curr(n);
        for(int i=0;i<n;i++){
            curr[i]=seq[i]^k;
        }
        sort(curr.begin(), curr.end());
        if(curr==seq){
            cout<<k<<"\n";
            return;
        }
    }
    cout<<"-1\n";
    return;
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