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
    int n, k;
    cin>>n>>k;
    vector<int> seq(n);
    cin>>seq;
    set<int> val;
    vector<int> seq2;
    for(const auto &x : seq){
        if(!val.count(x)){
            seq2.pb(x);
            val.insert(x);
        }
    }
    if(seq2.size() > k){
        cout<<"-1\n";
        return;
    }
    cout<<n*k<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            if(j < seq2.size()){
                cout<<seq2[j]<<" ";
            }
            else{
                cout<<"1 ";
            }
        }
    }
    cout<<"\n";
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