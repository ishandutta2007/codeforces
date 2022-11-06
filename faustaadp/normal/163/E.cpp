#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll MM = 1e5 + 5;
const ll mo = 1e9 + 7;
int trie[NN][26];
int fail[NN];
int sz, te;
int IN[NN], OUT[NN];
ll BIT[NN];
ll a[MM], b[MM];
vector<int> v[NN];
ll n, q;
ll add(string s, ll idx)
{
	ll now = 0;
	for(ll i = 0; i < s.length(); i++)
	{
		if(trie[now][s[i] - 'a'] == -1)
			trie[now][s[i] - 'a'] = ++sz;
		now = trie[now][s[i] - 'a'];
	}
	// cout << s << " " << now << "\n";
	return now;
}
void build()
{
	queue<ll> q;
	fail[0] = 0;
	for(ll i = 0; i < 26; i++)
		if(trie[0][i] == -1)
			trie[0][i] = 0;
		else
		{
			ll nx = trie[0][i];
			fail[nx] = 0;
			v[fail[nx]].pb(nx);
			q.push(nx);
		}
	while(!q.empty())
	{
		ll now = q.front();
		q.pop();
		for(ll i = 0; i < 26; i++)
			if(trie[now][i] == -1)
				trie[now][i] = trie[fail[now]][i];
			else
			{
				ll nx = trie[now][i];
				fail[nx] = trie[fail[now]][i];
				v[fail[nx]].pb(nx);
				q.push(nx);
			}
	}
}
void dfs1(ll pos)
{
	IN[pos] = ++te;
	for(ll i = 0; i < v[pos].size(); i++)
		dfs1(v[pos][i]);
	OUT[pos] = te;
	// cout << pos << " " << IN[pos] << " " << OUT[pos] << "\n";
}
void upd(ll pos, ll z)
{
	for(ll i = pos; i <= 1000001; i += (i & (-i)))
		BIT[i] += z;
}
ll que(ll pos)
{
	ll H = 0;
	for(ll i = pos; i > 0; i -= (i & (-i)))
		H += BIT[i];
	return H;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(trie, -1, sizeof(trie));
	cin >> q >> n;
	for(ll i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		a[i] = add(s, i);
	}
	build();
	dfs1(0);
	// return 0;
	for(ll i = 1; i <= n; i++)
	{
		upd(IN[a[i]], 1);
		upd(OUT[a[i]] + 1, -1);
		b[i] = 1;
		// cout << IN[a[i]] << " " << OUT[a[i]] << "\n";
	}
	for(ll i = 1; i <= q; i++)
	{
		char ct;
		cin >> ct;
		if(ct == '?')
		{
			string s;
			cin >> s;
			ll now = 0, hz = 0;
			for(ll i = 0; i < s.length(); i++)
			{
				now = trie[now][s[i] - 'a'];
				// cout << now << " " << IN[now] << " " << que(IN[now]) << "_\n";
				hz += que(IN[now]);
			}
			cout << hz << "\n";
		}
		else
		if(ct == '-')
		{
			ll ta;
			cin >> ta;
			if(b[ta])
			{
				b[ta] = 0;
				upd(IN[a[ta]], -1);
				upd(OUT[a[ta]] + 1, 1);
			}
		}
		else
		{
			ll ta;
			cin >> ta;
			if(!b[ta])
			{
				b[ta] = 1;
				upd(IN[a[ta]], 1);
				upd(OUT[a[ta]] + 1, -1);
			}
		}
	}
}