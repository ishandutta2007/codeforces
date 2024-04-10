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
    int n;
    cin>>n;
    vector<int> x(n), y(n);
    rep(i,0,n) cin>>x[i]>>y[i];
    rep(it,0,30) {
        bool ok = false;
        rep(i,0,n-1) if((((x[i]+y[i])%2==0))!=((x[i+1]+y[i+1])%2)==0) {
            ok = true;
        }
        if(ok) break;
        rep(i,1,n) {
            x[i]-=x[0];
            y[i]-=y[0];
        }
        x[0] = 0;
        y[0] = 0;
        vector<int> xx(n), yy(n);
        rep(i,0,n) {
            xx[i] = (x[i]-y[i])/2;
            yy[i] = (x[i]+y[i])/2;
        }
        x = xx;
        y = yy;
    }
    vector<int> ans;
    rep(i,0,n) if((x[i]+y[i])%2==0) ans.push_back(i);
    int m = ans.size();
    assert(m!=0 && m!=n);
    cout<<m<<"\n";
    for(int i:ans)cout<<i+1<<" ";
    cout<<"\n";
}