#include <bits/stdc++.h>
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
    vector<int> p(n);
    cin>>p;
    vector<vector<int>> pr(n, vector<int>(n+1)), suf(n, vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pr[i][j+1] = pr[i][j] + (j < i && p[j] < p[i]);
        }
        for(int j=n-1;j>=0;--j){
            suf[i][j] = suf[i][j+1] + (j > i && p[j] < p[i]);
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans += pr[j][i] * suf[i][j+1];
        }
    }
    cout<<ans<<"\n";
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