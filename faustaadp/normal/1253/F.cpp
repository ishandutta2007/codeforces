#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll MAXN = 3e5 + 5;
ll k, n, m, q, ta, tb, tc;
ll dis[MAXN];
ll dkt[MAXN];
ll dep[MAXN];
ll ma[22][MAXN];
ll p[22][MAXN];
vector<ll> v0[MAXN];
vector<ll> w0[MAXN];
vector<ll> v[MAXN];
vector<ll> w[MAXN];
vector<pair<ll, pair<ll, ll> > > isi;
ll P[MAXN];
void djik()
{
	priority_queue<pair<ll, pair<ll, ll> > > pq;
	for(ll i = 1; i <= n; i++)
	{
		dis[i] = 1e18;
		if(i <= k)
		{
			dis[i] = 0;
			dkt[i] = i;
			pq.push(mp(0, mp(i, i)));
		}
	}

	while(!pq.empty())
	{
		ll jar = -pq.top().fi;
		ll u = pq.top().se.fi;
		ll dk = pq.top().se.se;
		// cout << u << "_\n";
		pq.pop();
		for(ll i = 0; i < v0[u].size(); i++)
		{
			ll nx = v0[u][i];
			ll wx = jar + w0[u][i];
			if(dis[nx] > wx)
			{
				dis[nx] = wx;
				dkt[nx] = dk;
				pq.push(mp(-wx, mp(nx,dk)));
			}
			else
			if(dkt[nx] != dk)
			{
				isi.pb(mp(dis[nx] + wx, mp(dkt[nx], dk)));
			}
		}
	}
}
void dfs(ll pos, ll par, ll dlm)
{
	dep[pos] = dlm;
	p[0][pos] = par;
	for(ll i = 1; i <= 20; i++)
	{
		p[i][pos] = p[i - 1][p[i - 1][pos]];
		ma[i][pos] = max(ma[i - 1][pos], ma[i - 1][p[i - 1][pos]]);
	}
	for(ll i = 0; i < v[pos].size(); i++)
	{
		ll nx = v[pos][i];
		if(nx == par)continue;
		ma[0][nx] = w[pos][i]; 
		dfs(nx, pos, dlm + 1);
	}
}
ll LCA(ll A, ll B)
{
	ll H = 0;
	if(dep[A] < dep[B])
		swap(A,B);
	for(ll i = 20; i >= 0; i--)
		if(dep[A] - (1<<i) >= dep[B])
		{
			H = max(H, ma[i][A]);
			A = p[i][A];
		}
	// cout << A << " " << B << " " << H << "\n";
	if(A == B)
		return H;
	for(ll i = 20; i >= 0; i--)
		if(p[i][A] != p[i][B])
		{
			H = max(H, ma[i][A]);
			H = max(H, ma[i][B]);
			A = p[i][A];
			B = p[i][B];
		}
	// cout << A << " " << B << " " << H << "\n";
	// cout << A << " " << p[0] << "\n";
	H = max(H, ma[0][A]);
	H = max(H, ma[0][B]);
	return H;
}
ll car(ll A)
{
	if(P[A] == A)
		return A;
	else
		return P[A]=car(P[A]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k >> q;
	for(ll i = 1; i <= m; i++)
	{
		P[i] = i;
		cin >> ta >> tb >> tc;
		v0[ta].pb(tb);
		w0[ta].pb(tc);
		v0[tb].pb(ta);
		w0[tb].pb(tc);
	}
	djik();
	sort(isi.begin(),isi.end());
	for(ll i = 0; i < isi.size(); i++)
	{
		if(car(isi[i].se.fi) != car(isi[i].se.se))
		{
			v[isi[i].se.fi].pb(isi[i].se.se);
			w[isi[i].se.fi].pb(isi[i].fi);
			v[isi[i].se.se].pb(isi[i].se.fi);
			w[isi[i].se.se].pb(isi[i].fi);
			// cout << isi[i].se.fi << " " << isi[i].se.se << " " << isi[i].fi << "_\n";
			P[car(isi[i].se.fi)] = car(isi[i].se.se);
		}
	}
	dfs(1,1,0);
	while(q--)
	{
		cin >> ta >> tb;
		cout << LCA(ta, tb) << "\n";
	}
}