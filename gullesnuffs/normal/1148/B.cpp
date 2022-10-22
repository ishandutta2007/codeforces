#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	ios::sync_with_stdio(0);
    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n);
    rep(i,0,n)
        cin >> a[i];
    vector<ll> b(m);
    rep(i,0,m)
        cin >> b[i];
    if (k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    int bind = 0;
    queue<ll> cancelledB;
    rep(i,0,k)
        cancelledB.push(b[bind++]);
    ll ans = b[bind]+tb;
    rep(i,0,k+1) {
        while (sz(cancelledB) && a[i]+ta > cancelledB.front()) {
            cancelledB.pop();
            while ((i+sz(cancelledB) < k && bind < m) || (bind < m && a[i]+ta > b[bind])) {
                cancelledB.push(b[bind++]);
            }
        }
        if (bind == m)
            ans = -1;
        else
            ans = b[bind]+tb;
    }
    cout << ans << endl;
}