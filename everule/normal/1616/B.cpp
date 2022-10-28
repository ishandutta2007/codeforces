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
    ans.push_back(s[0]);
    for(int i=0;i<n-1;i++){
        if(s[i] >= s[i+1]) ans.push_back(s[i+1]);
        else break;
    }
    for(int i=ans.size() - 1;i>=0;--i){
        ans.push_back(ans[i]);
    }
    string ans2;
    ans2.push_back(s[0]);ans2.push_back(s[0]);
    cout<<min(ans, ans2)<<"\n";
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