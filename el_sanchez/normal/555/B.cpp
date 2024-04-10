#include <bits/stdc++.h>
#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second                    
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 200500;
const ll LINF = 2E18;

struct query {
	ll x, lx;
	int t, id;
	query() {x = t = id = 0;}
	query(ll _x, ll _lx, int _t, int _id) {
		x = _x;
		lx = _lx;
		t = _t;
		id = _id;
	}		
};

bool operator<(query a, query b) {
	if (a.x != b.x)
		return a.x < b.x;
	if (a.t != b.t)
		return a.t < b.t;
	if (a.t == 1)
		return a.x < b.x;
	return a.lx < b.lx;		
}

int n, m;
ll l[MAXN], r[MAXN], lx, rx;
ll b[MAXN];
int ans[MAXN], id[MAXN];
bool bad;
vector<query> q;
set<pair<ll, int> > pos;

int main() {

	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%I64d%I64d", &l[i], &r[i]);	
	forn(i, m)
		scanf("%I64d", &b[i]);	
		
	forn(i, n - 1) {
		rx = r[i + 1] - l[i];
		lx = l[i + 1] - r[i];
		q.pb(query(rx, lx, 2, i));  			
	}		
	forn(i, m)
		q.pb(query(b[i], 0, 1, i));
	sort(all(q));

	pos.insert({LINF, 0});
	forn(i, q.size()) {
		//cout << q[i].id << ' ' << q[i].lx << ' ' << q[i].x << '\n';
		if (q[i].t == 1) {
			pos.insert({q[i].x, q[i].id});			
		} else {
			pair<ll, int> f = {q[i].lx, -INF};
			auto pp = pos.lower_bound(f);
			pair<ll, int> p = *pp;
			if (p.X == LINF) {
				bad = 1;
				break;
			}
			pos.erase(p);
			ans[q[i].id] = p.Y;
		}
	}
	
	if (bad)
		cout << "No";
	else {
		cout << "Yes\n";
		forn(i, n - 1) {
		 	printf("%d ", ans[i] + 1);
		}
	}
	return 0;
}