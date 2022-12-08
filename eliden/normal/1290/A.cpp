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
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<ll> a(n);
        rep(i,0,n) cin>>a[i];
        vector<ll> b(m);
        rep(i,0,m) {
            b[i] = max(a[i], a[n-m+i]);
        }
        k = min(k,m-1);
        ll lo = 0, hi = 3e9;
        while(lo<hi) {
            ll mid = hi-(hi-lo)/2;
            int count_below = 0;
            int w = m-k;
            rep(i,0,w) if(b[i]<mid) ++count_below;
            bool any = false;
            rep(i,0,m-w+1) {
                if(count_below==0) {
                    any = true;
                    break;
                }
                if(i+w==m) break;
                if(b[i]<mid) --count_below;
                if(b[i+w]<mid) ++count_below;
            }
            if(any) lo = mid;
            else hi = mid-1;
        }
        cout<<lo<<"\n";
    }
}