#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n;
        cin >> n;
        vector<ll> a(n);
        rep(i,0,n) cin >> a[i];
        ll x, y;
        int fx, fy;
        cin >> x >> fx >> y >> fy;
        ll req;
        cin >> req;
        int lo = 1, hi = n+1;
        rep(i,0,n) a[i]/=100;
        sort(all(a));
        reverse(all(a));
        while(lo<hi) {
            int mid = (lo+hi)/2;
            vector<ll> c(mid);
            rep(i,0,mid) {
                if(i%fx==fx-1) c[i] += x;
                if(i%fy==fy-1) c[i] += y;
            }
            sort(all(c));
            reverse(all(c));
            ll sum = 0;
            rep(i,0,mid) sum += a[i]*c[i];
            if(sum>=req) hi = mid;
            else lo = mid+1;
        }
        if(lo==n+1) lo = -1;
        cout<<lo<<"\n";
    }
}