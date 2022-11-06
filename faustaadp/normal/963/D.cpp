#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e5 + 5;
ll trie[NN][26];
ll fail[NN];
ll sz;
ll x[NN];
ll idx[NN];
string s, z[NN];
ll d[NN];
vector<ll> isi[NN];
ll n;
void add(string str, ll id)
{
	ll cur = 0;
	for(ll i = 0; i < str.length(); i++)
	{
		ll nx = str[i] - 'a';
		if(trie[cur][nx] == -1)
			trie[cur][nx] = ++sz;
		cur = trie[cur][nx];
	}
	idx[cur] = id;
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
				q.push(nx);
			}
	}
}
ll depe(ll pos)
{
	if(pos == 0)
		return 0;
	else
	if(idx[pos])
		return pos;
	if(d[pos] == -1)
		d[pos] = depe(fail[pos]);
	return d[pos];
}
void upd(ll id, ll cur)
{
	while(cur != 0)
	{
		cur = depe(cur); 
		isi[idx[cur]].pb(id);
		cur = fail[cur];
	}
}
void jalan(string str)
{
	ll cur = 0;
	for(ll i = 0; i < str.length(); i++)
	{
		cur = trie[cur][str[i] - 'a'];
		upd(i, cur);
	}
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(trie, -1, sizeof(trie));
    cin >> s;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
    	cin >> x[i] >> z[i];
    	add(z[i], i);
    }
    build();
    memset(d, -1, sizeof(d));
    jalan(s);
    for(ll i = 1; i <= n; i++)
    {
    	ll m = z[i].size();
    	ll jaw = 1e18;
    	for(ll j = x[i] - 1; j < isi[i].size(); j++)
    		jaw = min(jaw, isi[i][j] - isi[i][j - x[i] + 1] + m);
    	if(jaw == 1e18)
    		jaw = -1;
    	cout << jaw << "\n";
    }
}