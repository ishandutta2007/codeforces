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
    set<int> values = {6,10,14};
    int n;
    cin>>n;
    if(n<=30){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<int> ans1 = {6,10,14,n-30};
    vector<int> ans2 = {6,10,15,n-31};
    auto check = [&](vector<int> val){
        for(int i=0;i<4;i++){
            if(val[i]<=0) return false;
            for(int j=0;j<i;j++){
                if(val[i]==val[j]){
                    return false;
                }
            }
        }
        return true;
    };
    if(check(ans1)){
        cout+ans1;
    }
    else{
        cout+ans2;
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