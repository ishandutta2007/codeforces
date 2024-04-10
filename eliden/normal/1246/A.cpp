#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, p;
    cin >> n >> p;
    int ans = -1;
    rep(j,0,40) {
        ll x = n-p*j;
        if(x>=j && __builtin_popcount(x)<=j) {
            ans = j;
            break;
        }
    }
    cout<<ans<<endl;
}