#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 998244353;
ll n, a[NN], po[NN], te, dep[NN], p[22][NN], Z[NN], sub[NN];
vector<ll> v[NN], isi[NN], v2[NN], w2[NN];
ll pr[NN];
ll has;
void dfs(ll pos, ll par, ll dpt)
{
	p[0][pos] = par;
	for(ll i = 1; i <= 20; i++)
		p[i][pos] = p[i - 1][p[i - 1][pos]];
	dep[pos] = dpt;
	for(ll i = 0; i < v[pos].size(); i++)
	{
		ll nx = v[pos][i];
		if(nx == par)
			continue;
		dfs(nx, pos, dpt + 1);
	}
	po[pos] = ++te;
}
ll LCA(ll X, ll Y)
{
	if(dep[X] < dep[Y])
		swap(X, Y);
	for(ll i = 20; i >= 0; i--)
		if(dep[X] - (1 << i) >= dep[Y])
			X = p[i][X];
	if(X == Y)
		return X;
	for(ll i = 20; i >= 0; i--)
		if(p[i][X] != p[i][Y])
		{
			X = p[i][X];
			Y = p[i][Y];
		}
	return p[0][X];
}
void dfs2(ll pos, ll par, ll tot)
{
	sub[pos] = Z[pos];
	for(ll i = 0; i < v2[pos].size(); i++)
	{
		ll nx = v2[pos][i];
		if(nx == par)
			continue;
		ll wx = w2[pos][i];
		dfs2(nx, pos, tot);
		sub[pos] += sub[nx];
		ll atas = tot - sub[nx];
		ll bawah = sub[nx];
		ll j1 = atas * (bawah * (bawah - 1LL)) / 2LL;
		// cout << bawah * (bawah - 1LL) / 2 << "@@@\n";
		// cout << bawah * (bawah - 1LL) << "@@@\n";
		ll j2 = bawah * (atas * (atas - 1LL)) / 2LL;
		j1 %= mo;
		j2 %= mo;
		ll too = (j1 + j2) * wx;
		too %= mo;
		// cout << j1 << " " << j2 << "   " << pos << " " << nx << "   " << atas << " " << bawah << "\n";
		// cout << too << "\n";
		has = (has + too) % mo;
	}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    pr[1] = 1;
    for(ll i = 2; i <= n; i++)
    	if(!pr[i])
    		for(ll j = i * i; j <= n; j += i)
    			pr[i] = 1;
    for(ll i = 1; i <= n; i++)
    {
    	cin >> a[i];
    	ll x = a[i];
    	for(ll j = 2; j * j <= x; j++)
    	{
    		// cout << j << " " << x << "@\n";
    		if(x % j == 0)
    		{
    			// cout << i << " " << j << "_\n";
    			isi[j].pb(i);
    		}
    		while(x % j == 0)
    			x /= j;
    	}
    	// cout << i << " " << x << "_\n";
    	if(x > 1)
    		isi[x].pb(i);
    }
    for(ll i = 1; i < n; i++)
    {
    	ll ta, tb;
    	cin >> ta >> tb;
    	v[ta].pb(tb);
    	v[tb].pb(ta);
    }
    dfs(1, 1, 1);
    for(ll i = 2; i <= 200000; i++)
    {
    	if(isi[i].empty())
    		continue;
		priority_queue<pll> pq;
		vector<ll> semua;
    	for(ll j = 0; j < isi[i].size(); j++)
    	{
    		Z[isi[i][j]] = 1;
    		pq.push(mp(-po[isi[i][j]], isi[i][j]));
    	}
    	while(!pq.empty())
    	{
    		pll now = pq.top();
    		pq.pop();
    		if(pq.empty())
    			break;
    		pll now2 = pq.top();
    		if(now.se == now2.se)
    			continue;
    		semua.pb(now.se);
    		ll lc = LCA(now.se, now2.se);
    		if(lc != now2.se)
    		{
    			pq.push(mp(-po[lc], lc));
    		}	
    		// cout << i << "  (" << now.se << " dan " << now2.se << ") " << lc << "\n";
    		ll jar = dep[now.se] - dep[lc];
    		v2[now.se].pb(lc);
    		w2[now.se].pb(jar);
    		v2[lc].pb(now.se);
    		w2[lc].pb(jar);
    		// cout << i << "  " << now.se << " " << lc << " " << jar << "\n";
    		// ll z;
    		// cin >> z;
    	}
    	semua.pb(pq.top().se);
    	// cout << i << "_\n";
    	dfs2(semua[0], semua[0], isi[i].size());

    	for(auto zz : semua)
    	{
    		v2[zz].clear();
    		w2[zz].clear();
    		sub[zz] = 0;
    	}
    	for(ll j = 0; j < isi[i].size(); j++)
    	{
    		Z[isi[i][j]] = 0;
    		pq.push(mp(-po[isi[i][j]], isi[i][j]));
    	}
    }
    cout << has << "\n";
    // for(ll i = 1; i <= n; i++)
    	// for(ll j = i + 1; j <= n; j++)
    		// cout << i << " " << j << " " << LCA(i, j) << "\n";
}