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
    string s,t;
    cin>>s>>t;
    int counts=0,countt=0;
    for(const auto &c : s){
        counts+=c-'0';
    }
    for(const auto &c : t){
        countt+=c-'0';
    }
    if(counts!=countt){
        cout<<"-1\n";
        return;
    }
    string seq;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            seq.pb(s[i]);
        }
    }
    n = seq.size();
    int count0=0, count1=0;
    for(int i=0;i<n;i++){
        if(seq[i]=='0'){
            if(count1==0){
                ++count0;
            }
            else{
                --count1;
                ++count0;
            }
        }
        else{
            if(count0==0){
                ++count1;
            }
            else{
                --count0;
                ++count1;
            }
        }
    }
    cout<<count0 + count1<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}