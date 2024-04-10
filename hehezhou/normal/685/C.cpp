#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point {
	ll x, y, z;
	friend inline istream& operator >> (istream &in, point &data) {
		return in >> data.x >> data.y >> data.z;
	}
	friend inline ostream& operator << (ostream &out, point &data) {
		return out << data.x << ' ' << data.y << ' ' << data.z;
	}
} a[100010];
point ans;
int t, n;
ll check(ll val) {
    ll ai = -3e18, bi = -3e18, ci = -3e18, abci = -3e18;
    ll aa = 3e18, ba = 3e18, ca = 3e18, abca = 3e18;
    for(int i = 1; i <= n; i++) {
        ai = max(ai, - a[i].x + a[i].y + a[i].z - val);
        bi = max(bi, + a[i].x - a[i].y + a[i].z - val);
        ci = max(ci, + a[i].x + a[i].y - a[i].z - val);
        abci = max(abci, + a[i].x + a[i].y + a[i].z - val);
        aa = min(aa, - a[i].x + a[i].y + a[i].z + val);
        ba = min(ba, + a[i].x - a[i].y + a[i].z + val);
        ca = min(ca, + a[i].x + a[i].y - a[i].z + val);
        abca = min(abca, + a[i].x + a[i].y + a[i].z + val);
    }
    ai = min(ai, (long long)3e18), bi = min(bi, (long long)3e18), ci = min(ci, (long long)3e18);
    aa = max(aa, (long long)-3e18), ba = max(ba, (long long)-3e18), ca = max(ca, (long long)-3e18);
    abca = max(abca, (long long)-3e18);
    abci = min(abci, (long long)3e18);
    // cerr << ai << ' ' << aa << endl;
    // cerr << bi << ' ' << ba << endl;
    // cerr << ci << ' ' << ca << endl;
    // cerr << abci << ' ' << abca << endl;
    ll ansa = aa, ansb = ba, ansc = ca;
    if(ansa % 2) ansa--;
    if(ansb % 2) ansb--;
    if(ansc % 2) ansc--;
    // cerr << ansa << ' ' << ansb << ' ' << ansc << endl;
    if(ansa + ansb + ansc > abca) ansa -= min(ansa - ai, ansa + ansb + ansc - abca + 1) / 2 * 2;
    if(ansa + ansb + ansc > abca) ansb -= min(ansb - bi, ansa + ansb + ansc - abca + 1) / 2 * 2;
    if(ansa + ansb + ansc > abca) ansc -= min(ansc - ci, ansa + ansb + ansc - abca + 1) / 2 * 2;
    // cerr << ansa << ' ' << ansb << ' ' << ansc << endl;
    if(ansa >= ai && ansa <= aa && ansb >= bi && ansb <= ba && ansc >= ci && ansc <= ca && ansa + ansb + ansc >= abci && ansa + ansb + ansc <= abca) {
        ans = point{(long long)(ansb + ansc) / 2, (long long)(ansc + ansa) / 2, (long long)(ansa + ansb) / 2};
        return 1;
    }
    ansa = aa, ansb = ba, ansc = ca;
    if(ansa % 2 == 0) ansa--;
    if(ansb % 2 == 0) ansb--;
    if(ansc % 2 == 0) ansc--;
    if(ansa + ansb + ansc > abca) ansa -= min(ansa - ai, ansa + ansb + ansc - abca + 1) / 2 * 2;
    if(ansa + ansb + ansc > abca) ansb -= min(ansb - bi, ansa + ansb + ansc - abca + 1) / 2 * 2;
    if(ansa + ansb + ansc > abca) ansc -= min(ansc - ci, ansa + ansb + ansc - abca + 1) / 2 * 2;
    if(ansa >= ai && ansa <= aa && ansb >= bi && ansb <= ba && ansc >= ci && ansc <= ca && ansa + ansb + ansc >= abci && ansa + ansb + ansc <= abca) {
        ans = point{(long long)(ansb + ansc) / 2, (long long)(ansc + ansa) / 2, (long long)(ansa + ansb) / 2};
        return 1;
    }
    return 0;
}
int main() {
    ios :: sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll l = 0, r = 3e18, dis;
        while(l <= r) {
            ll mid = l + r >> 1;
            if(check(mid)) dis = mid, r = mid - 1;
            else l = mid + 1;
        }
        // cout << dis << endl;
        cout << ans << endl;
        // cerr << check(1574121054453344319) << endl;
    }
    return 0;
}