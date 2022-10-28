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
    int n,m;
    cin>>n>>m;
    int maxr = 0, maxw = 0;
    for(int i=0;i<m;i++){
        int r,w;
        cin>>r>>w;
        maxr = max(maxr, r);
        maxw = max(maxw, w);
    }
    if(maxr + maxw > n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    string s = string(maxr, 'R') + string(n - maxr, 'W');
    cout<<s<<"\n"; 
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