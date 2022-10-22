#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define mt make_tuple
#define endl '\n'
#define up front()
#define tp top()
#define em empty()
#define all(v) v.begin(),v.end()
#define fr(p) get<0>(p)
#define sc(p) get<1>(p)
#define th(p) get<2>(p)
#define fo(p) get<3>(p)
#define fi(p) get<4>(p)
#define dec(x) cout.setf(ios::fixed); cout.precision(x);
#define t1(x) cout << #x << ' ' << x << endl ;
#define t2(x,y) cout << #x << ' ' << x << " / " << #y << ' ' << y << endl ;
#define t3(x,y,z) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << endl ;
#define t4(x,y,z,w) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << endl ;
#define t5(x,y,z,w,v) cout << #x << ' ' << x << " / " << #y << ' ' << y << " / " << #z << ' ' << z << " / " << #w << ' ' << w << " / " << #v << ' ' << v << endl ;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;
typedef tuple<string, int> psi;
typedef tuple<string, ll> psl;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n, a, b, da, db;
vector<int> v[100020];
bool chk[100020], ck[100020];
int d[2][100020];

bool dfs(int now, int dep){
	if (dep > da) return false;
	chk[now] = true;
	if (now == b) return true;
	for (int nxt : v[now]){
		if (chk[nxt]) continue;
		if (dfs(nxt, dep+1)) return true;
	}
	return false;
}

int dis(int st, int typ){
	for (int i = 1; i <= n; i++) d[typ][i] = -1;
	queue<pii> q;
    q.push(mt(st, 0));
	d[typ][st] = 0;
	while (!q.em){
		int now = fr(q.up), tim = sc(q.up);
		q.pop();
		for (int nxt : v[now]){
			if (d[typ][nxt] != -1) continue;
            d[typ][nxt] = tim+1;
            q.push(mt(nxt, tim+1));
		}
	}
	int mx=0, mxp=st;
	for (int i = 1; i <= n; i++){
		if (mx < d[typ][i]){
			mx = d[typ][i];
			mxp = i;
		}
	}
	return (typ==0 ? mxp : mx);
}

int main(){
	Fast;
    int t = 1;
    cin >> t;
    while (t--){
		cin >> n >> a >> b >> da >> db;
		for (int i = 1; i < n; i++){
            int x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
		}
		bool ans = true;
		if (dfs(a, 0)) ans = false;
		int dep = min(dis(dis(1, 0), 1), db);
		//t2(dep, db);
		if (dep <= da*2) ans = false;
		cout << (ans ? "Bob" : "Alice");
        done: ;
		cout << endl;
		for (int i = 1; i <= n; i++){
			chk[i] = false;
			ck[i] = false;
			v[i].clear();
		}
	}
}