#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;


struct q{
	ll l, r, id, len;
};


bool cmp(q a, q b){
	if (a.l == b.l) {
		if (a.r == b.r) return a.id < b.id;
		return a.r < b.r; 
	}
	return (a.l < b.l);
}

ll n, m, M, c[200005], l[200005], r[200005], ans = 0, la, ra, li;
q aa[200005], a[200005];

vector <pll> tree;

pll get(ll v, ll l, ll r, ll a, ll b){
	if (b < a) return mp(0, -1);
	if (l >= a && r <= b) return tree[v];
	if (l > b || r < a) return mp(0, -1);
	return max(get(2 * v, l, (l + r) / 2, a, b), get(2 * v + 1, (l + r) / 2 + 1, r, a, b));
}


int main(){
//    ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n >> M;
	for (int i = 0; i < n; i++){
		cin >> aa[i].l >> aa[i].r;
		aa[i].len = aa[i].r - aa[i].l;
		aa[i].id = i + 1;
	}
	sort (aa, aa + n, &cmp);
	for (int i = 0; i < M; i++){
		cin >> l[i] >> r[i] >> c[i];
	}
	ll mx = -1;
	ll n2 = 0;
	for (int i = 0; i < n; i++){
		if (aa[i].r > mx){
			mx = aa[i].r;
			a[n2++] = aa[i];
		}
	}
	n = n2;
	ll nn = n;
	m = 1;
	while (nn){
		nn >>= 1;
		m <<= 1;
	}
	tree.resize(2 * m, mp(0, -1));
	for (int i = m; i < m + n; i++){
		tree[i] = mp(a[i - m].len, a[i - m].id);
	}
	for (int i = m - 1; i > 0; i--){
		tree[i] = max(tree[2 * i], tree[2 * i + 1]);
	}

	for (int i = 0; i < M; i++){
		ll p2, p1, lf = l[i], rg = r[i];
		if (a[0].l >= rg || a[n - 1].r <= lf) continue;
		if (a[0].l >= lf) p1 = -1;
		else {
			ll l = 0, r = n;
			while (r - l > 1){
				ll m = (l + r) / 2;
				if (a[m].l >= lf) r = m;
				else l = m;
			}
			p1 = l;
		}
		if (a[n - 1].r <= rg) p2 = n;
		else {
			ll l = -1, r = n - 1;
			while (r - l > 1){
				ll m = (l + r) / 2;
				if (a[m].r <= rg) l = m;
				else r = m;
			}
			p2 = r;
		}
		if (p1 >= 0){
			if (ans < (min(a[p1].r, rg) - max(lf, a[p1].l)) * c[i]){
				ans =  (min(a[p1].r, rg) - max(lf, a[p1].l)) * c[i];
				la = a[p1].id;
				ra = i + 1;
			}
		}
		if (p2 < n){
			if (ans < (min(rg, a[p2].r) - max(a[p2].l, lf)) * c[i]){
				ans = (min(rg, a[p2].r) - max(a[p2].l, lf)) * c[i];
				la = a[p2].id;
				ra = i + 1;
			}
		}
		p1++;
		p2--;
		pll tt = get(1, 0, m - 1, p1, p2);
		if (ans < tt.first * c[i]){
			ans = tt.first * c[i];
			la = tt.second;
			ra = i + 1;
		}
	}

	if (ans){
		cout << ans << '\n' << la << " " << ra;
	} else {
		cout << 0 << '\n';
	}

}