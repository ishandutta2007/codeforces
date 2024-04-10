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
    int K = 100;
    ll ans = 0;
    vector<ll> seen(n*K+5);
    rep(k,1,K) {
        ll x = 0;
        ++seen[n];
        vector<ll> toclear{n};
        rep(i,0,n) {
            if(s[i]=='1') x += k-1;
            else x -= 1;
            ans += seen[x+n];
            ++seen[x+n];
            toclear.push_back(x+n);
        }
        for(int i:toclear) seen[i] = 0;
    }
    vector<ll> before, after, pos;
    int zeros = 0;
    rep(i,0,n+1) {
        if(i==n || s[i]=='1') {
            if(!before.empty()) after.push_back(zeros);
            if(i!=n) {
                before.push_back(zeros);
                pos.push_back(i);
            }
            zeros = 0;
        }
        else ++zeros;
    }
    int m = before.size();
    rep(i,0,m) {
        rep(j,i,m) {
            ll b = pos[j]-pos[i]+1, ones = j-i+1;
            ll startlen = ones*K;
            while(startlen<b) startlen += ones;
            if(startlen>n) break;
            ll a = before[i], c = after[j];
            if(a>c) swap(a,c);
            for(ll len = startlen; len<=a+b+c; len+=ones) {
                if(len<b+a) ans += 1+(len-b);
                else if(len<b+c) ans += a+1;
                else ans += a+b+c-len+1;
            }
        }
    }
    cout<<ans<<endl;
}