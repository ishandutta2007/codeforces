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
    //h_i / D_j > H_j / floor(C / c_i) * d_j
    //floor(C/c_i) * h_i * d_i > H_jD_j
    int n,c;
    cin>>n>>c;
    vector<ll> bst(c+1);
    for(int i=0;i<n;i++){
        ll c,d,h;
        cin>>c>>d>>h;
        bst[c] = max(bst[c], 1ll * d * h);
    }
    //cout+bst;
    for(int i=c;i>=1;--i){
        for(int j=2;j*i<=c;j++){
            bst[j*i] = max(bst[i] * j, bst[j*i]);
        }
    }
    //cout+bst;
    for(int i=1;i<=c;i++){
        bst[i] = max(bst[i], bst[i-1]);
    }
    //cout+bst;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll h,d;
        cin>>h>>d;
        ll ans = upper_bound(bst.begin(), bst.end(), h*d) - bst.begin();
        if(ans > c) ans = -1;
        cout<<ans<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}