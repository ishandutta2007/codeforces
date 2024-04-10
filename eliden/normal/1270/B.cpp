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
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n;
        cin>>n;
        vector<ll> a(n);
        rep(i,0,n) cin>>a[i];
        int lo = a[0], hi = a[0];
        int l = -1, r = -1;
        int ilo = 0, ihi = 0;
        rep(j,1,n) {
            if(a[j]-j>=lo+1) {
                l = ilo;
                r = j;
                break;
            }
            if(a[j]+j<=hi-1) {
                l = ihi;
                r = j;
                break;
            }
            if(a[j]-j<lo) {
                lo = a[j]-j;
                ilo = j;
            }
            if(a[j]+j>hi) {
                hi = a[j]+j;
                ihi = j;
            }
        }
        if(l==-1) cout<<"NO\n";
        else {
            cout<<"YES\n";
            cout<<l+1<<" "<<r+1<<"\n";
        }
    }
}