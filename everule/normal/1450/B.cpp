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
const int INF = 1e7 + 7;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<array<int,2>> p(n);
    for(auto &[x,y] : p){
        cin>>x>>y;
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        bool flag = 0;
        for(int j=0;j<n;j++){
            flag |= (abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]) > k);
        }
        if(!flag) ans = 1;
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