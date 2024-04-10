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
    ll n;
    int m;
    cin >> n >> m;
    
    int rem = n%m;
    vector<ll> freq(m,n/m);
    rep(i,1,rem+1) ++freq[i];
    //rep(i,0,m) debug(freq[i]);
    vector<ll> f2(m,0);
    rep(i,0,m) {
        ll j = i;
        j = (j*j)%m;
        f2[j]+=freq[i];
    }
    ll ans = f2[0]*f2[0];
    rep(i,1,m) {
        ans +=f2[i]*f2[m-i];
    }
    cout << ans << "\n";
}