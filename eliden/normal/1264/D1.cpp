#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    const ll MOD = 998244353;
    int m = n+5;
    vector<ll> dp1(m), dp2(m);
    dp1[0] = 1;
    dp2[0] = 0;
    rep(i,0,n) {
        vector<ll> next1(m), next2(m);
        if(s[i]=='(' || s[i]=='?') {
            rep(j,0,m-1) {
                next1[j+1] += dp1[j];
                next2[j+1] += dp1[j];
            }
            rep(j,0,m) next2[j] += dp2[j];
        }
        if(s[i]==')' || s[i]=='?') {
            next2[0] += dp2[0];
            rep(j,0,m-1) next2[j] += dp2[j+1];
            rep(j,0,m) next1[j] += dp1[j];
        }
        rep(j,0,m) {
            next1[j]%=MOD;
            next2[j]%=MOD;
        }
        dp1 = move(next1);
        dp2 = move(next2);
        // rep(i,0,5) cerr<<dp1[i]<<" ";
        // cerr<<endl;
        // rep(i,0,5) cerr<<dp2[i]<<" ";
        // cerr<<endl;
    }
    cout<<dp2[0]<<endl;
}