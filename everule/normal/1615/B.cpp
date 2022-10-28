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
const int MAXR = 2e5 + 7;
const int LG = 20;
int bc[MAXR][LG];
void precompute(){
    for(int i=1;i<MAXR;i++){
        for(int j=0;j<LG;j++){
            bc[i][j] = bc[i-1][j] + ((i >> j) & 1);
        }
    }
}
void solve(){
    int l,r;
    cin>>l>>r;
    int len = r - l + 1;
    int ans = len;
    for(int i=0;i<LG;i++){
        ans = min(ans, len - bc[r][i] + bc[l-1][i]);
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    precompute();
    while(t--){
        solve();
    }
}