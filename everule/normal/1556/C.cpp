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
const ll INFLL = 1e18;
void solve(){
    int n;
    cin>>n;
    vector<ll> c(n);
    cin>>c;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(i % 2 == 1) continue;
        ll bsum = 0;
        ll bmin = 0;
        for(int j=i+1;j<n;j++){
            if(j % 2 == 1){
                ll mnL = max(1ll, -bmin);
                ll mnR = max(1ll, mnL + bsum);
                ans += max(0ll, min(c[j] - mnR, c[i] - mnL) + 1);
                //cout<<i<<" "<<j<<" "<<ans<<"\n";
                bsum -= c[j];
                bmin = min(bmin, bsum);
            }
            else{
                bsum += c[j];
            }
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}