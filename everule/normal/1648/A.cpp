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
    int n,m;
    cin>>n>>m;
    map<int, vector<int>> r;
    map<int, vector<int>> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            r[x].push_back(i);
            c[x].push_back(j);
        }
    }
    ll ans = 0;
    for(auto &[a,v] : r){
        sort(v.begin(), v.end());
        n = v.size();
        for(int i=0;i<n;i++){
            ans -= 1ll * (n - 1 - 2 * i) * v[i];
        }
    }
    for(auto &[a,v] : c){
        sort(v.begin(), v.end());
        n = v.size();
        for(int i=0;i<n;i++){
            ans -= 1ll * (n - 1 - 2 * i) * v[i];
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}