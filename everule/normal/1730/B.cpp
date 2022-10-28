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
    vector<array<int, 2>> xt(n);
    for(auto &[x, t] : xt) cin>>x;
    for(auto &[x, t] : xt) cin>>t;
    sort(xt.begin(), xt.end());
    if(n == 1){
        cout<<xt[0][0]<<"\n";
        return;
    }
    vector<int> pmin(n+1, 1e9), smax(n+1, -1e9);
    for(int i=1;i<=n;i++) pmin[i] = min(xt[i-1][0] - xt[i-1][1], pmin[i-1]);
    for(int i=n-1;i>=0;--i) smax[i] = max(xt[i][1] + xt[i][0], smax[i+1]);
    double ans_val = 1e9;
    double ans_pos = 1e9;
    for(int i=1;i<n;i++){
        int lft = pmin[i];
        int rht = smax[i];
        //max(x - lft, rht - x)
        //x = (lft + rht) / 2
        int upper = xt[i][0];
        int lower = xt[i-1][0];
        double pos = clamp<double>((lft + rht) / 2.0, xt[i-1][0], xt[i][0]);
        if(ans_val > max(pos - lft, rht - pos)){
            ans_val = max(pos - lft, rht - pos);
            ans_pos = pos;
        }
    }
    cout<<fixed<<setprecision(10)<<ans_pos<<"\n";
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