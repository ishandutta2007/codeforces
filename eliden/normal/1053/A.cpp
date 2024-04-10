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
    ll n, m, k;
    cin >> n >> m >> k;
    if((2*n*m)%k==0) {
        ll z = (2*n*m)/k;
        ll a = (z-1)/n, b=(z-1)%n;
        ll x1=n, y1=1;
        ll y2=a+1, x2=n-(b+1);
        assert(x2>=0 && x2<=n);
        assert(y2>=0 && y2<=m);
        assert(x1*y2-x2*y1==z);
        cout << "YES\n";
        cout << "0 0\n";
        cout << x1 << " " << y1 << "\n";
        cout << x2 << " " << y2 << "\n";
    }
    else cout << "NO\n";
}