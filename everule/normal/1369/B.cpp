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
    string s;
    cin>>s;
    string ans;
    int i;
    reverse(s.begin(), s.end());
    for(i=n-1;i>=0;--i){
        if(s[i]=='0'){
            ans+=s[i];
            s.pop_back();
        }
        else{
            break;
        }
    }
    reverse(s.begin(), s.end());
    string ans2;
    n = s.size();
    for(int i=n-1;i>=0;--i){
        if(s[i]=='1'){
            ans2+=s[i];
            s.pop_back();
        }
        else{
            break;
        }
    }
    if(s.empty()){
        cout<<ans<<ans2<<'\n';
        return;
    }
    cout<<ans<<"0"<<ans2<<"\n";
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