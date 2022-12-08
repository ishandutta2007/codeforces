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
    int n = 3;
    vector<int> x(n), y(n);
    rep(i,0,n) cin >> x[i] >> y[i];
    auto xsort = x, ysort = y;
    sort(all(xsort));
    sort(all(ysort));
    vector<pair<int,int>> pts;
    rep(xx,xsort[0],xsort[2]+1) {
        pts.emplace_back(xx,ysort[1]);
    }
    rep(i,0,3) {
        ll ylo = min(y[i],ysort[1]+1), yhi = max(ysort[1]-1,y[i]);
        rep(yy,ylo,yhi+1) {
            if(yy!=ysort[1]) {
                pts.emplace_back(x[i],yy);
            }
        }
    }
    cout<<pts.size()<<"\n";
    for(auto pt:pts) {
        cout << pt.first << " " << pt.second << "\n";
    }
}