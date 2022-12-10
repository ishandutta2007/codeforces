#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    sort(all(a));

    ll d=1;
    ll MAX=1LL<<33;
    int best=0, aa=-1, bb=-1, cc=-1;
    while(d<MAX) {
        int j=0, k=0;
        rep(i,0,n) {
            while(j<n && a[j]<a[i]+d) ++j;
            while(k<n && a[k]<a[i]+2*d) ++k;
            int c=1;
            if(j<n && a[j]==a[i]+d) {
                ++c;
                if(k<n && a[k]==a[i]+2*d) ++c;
            }
            if(c>best) {
                best = c;
                if(c==1) aa=i;
                else if(c==2) aa=i, bb=j;
                else aa=i, bb=j, cc=k;
            }
        }
        d*=2;
    }
    cout << best << "\n";
    vi x{aa,bb,cc};
    rep(i,0,best) cout<<a[x[i]]<<" ";
    cout<<endl;
}