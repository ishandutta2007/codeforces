#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll D[NN], ki, ka, pki, pka;
ll n, m, b[NN];
vector<ll> v[NN];
ll tanya(ll aa, ll bb)
{
	cout << "? " << aa << " " << bb << endl;
	ll temp;
	cin >> temp;
	return temp;
}
void jawab(ll pos)
{
	cout << "! " << pos << endl;
	exit(0);
}
void dfs(ll pos, ll par)
{
	// cout << pos << "\n";
	if(D[pos] == 1)
	{
		if(ki == -1)
		{
			ki = pos;
			pki = par;
		}
		ka = pos;
		pka = par;
	}
	for(ll i = 0; i < v[pos].size(); i++)
		if((b[v[pos][i]] == 0) && (v[pos][i] != par))
			dfs(v[pos][i], pos);
}
void hai()
{
	ll R = -1;
	for(ll i = 1; i <= n; i++)
		if(b[i] == 0)
			R = i;
	for(ll i = 1; i <= n; i++)
		if((D[i] > 1) && (b[i] == 0))
			R = i;
	ki = -1;
	ka = -1;
	// cout << R << "\n";
	dfs(R, 0);
	D[ki]--;
	D[ka]--;
	D[pki]--;
	D[pka]--;
	b[ki] = 1;
	b[ka] = 1;
	ll temp = tanya(ki, ka);
	if(temp == ki)
		jawab(ki);
	if(temp == ka)
		jawab(ka);
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i < n; i++)
    {
    	ll ta, tb;
    	cin >> ta >> tb;
    	D[ta]++;
    	D[tb]++;
    	v[ta].pb(tb);
    	v[tb].pb(ta);
    }
    for(ll i = 1; i <= (n/2); i++)
    {
    	hai();
    }
    ll R = -1;
	for(ll i = 1; i <= n; i++)
		if(b[i] == 0)
			jawab(i);

}