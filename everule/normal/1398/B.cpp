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
    string s;
    cin>>s;
    s.pb('0');
    vector<int> ans;
    int cnt = 0;
    for(const auto &c : s){
        if(c=='1'){
            ++cnt;
        }
        else{
            ans.pb(cnt);
            cnt = 0;
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    int fin = 0;
    for(int i=0;i<(int)ans.size();i+=2){
        fin+=ans[i];
    }
    cout<<fin<<"\n";
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