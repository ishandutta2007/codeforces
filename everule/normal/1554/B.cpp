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
    int n,k;
    cin>>n>>k;
    auto merge = [&](array<int, 2> x, array<int, 2> y){
        array<int, 2> ans = {-1, -1};
        ans[0] = max(x[0], y[0]);
        ans[1] = max(x[1], y[1]);
        if(x[0] != y[0]) ans[1] = max(ans[1], min(x[0], y[0]));
        return ans;
    };
    int mxp2 = 1;
    while(mxp2 <= n) mxp2 *= 2;
    vector<array<int, 2>> bst(mxp2, {-1, -1});
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        bst[x] = merge(bst[x], {i+1, -1});
    }
    for(int i=1;i<mxp2;i++){
        for(int j=0;(1<<j)<=i;j++){
            if((i & (1<<j)) == 0) continue;
            bst[i] = merge(bst[i], bst[i^(1<<j)]);
        }
    }
    ll ans = -1e18;
    for(int i=0;i<mxp2;i++){
        if(bst[i][1] == -1 || bst[i][0] == -1) continue;
        ans = max(ans, 1ll * bst[i][0] * bst[i][1] - 1ll * k * i);
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