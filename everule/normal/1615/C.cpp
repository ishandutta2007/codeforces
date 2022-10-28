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
const int INF = 1e9;
void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int c[2][2];
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) c[i][j] = 0;
    for(int i=0;i<n;i++){
        c[(a[i] == '1')][(b[i] == '1')]++;
    }
    if(c[0][1] + c[1][0] == 0){
        cout<<"0\n";
        return;
    }
    if(c[1][0] + c[1][1] == 0){
        cout<<"-1\n";
        return;
    }
    int ans = INF;
    if(c[1][0] % 2 == c[0][1] % 2){
        if(c[1][0] == c[0][1]) ans = min(ans, 2 * max(c[1][0], c[0][1]));
    }
    if(c[0][0] % 2 != c[1][1] % 2){
        if(c[1][1] == c[0][0] + 1) ans = min(ans, 2 * max(c[1][1], c[0][0] + 1) - 1);
    }
    if(ans == INF) ans = -1;
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