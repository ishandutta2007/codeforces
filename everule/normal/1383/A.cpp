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
const int MAXA = 20;
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<vector<int>> transform(MAXA, vector<int>(MAXA));
    for(int i=0;i<n;i++){
        if(s[i]>t[i]){
            cout<<"-1\n";
            return;
        }
        transform[s[i]-'a'][t[i]-'a']++;
    }
    int ans = 0;
    for(int i=0;i<MAXA-1;i++){
        bool flag = 0;
        int x;
        for(int j=i+1;j<MAXA;j++){
            if(transform[i][j] && !flag){
                flag = 1;
                x = j;
            }
            if(flag){
                transform[x][j]+=transform[i][j];
            }
        }
        ans+=flag;
    }
    cout<<ans<<'\n';
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