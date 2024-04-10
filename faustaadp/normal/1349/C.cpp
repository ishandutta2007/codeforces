#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, m, t;
ll a[2][1010][1010];
ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll x[1010][1010];
ll cek(ll X, ll Y, ll XX, ll YY, ll Z)
{
	if(X <= 0)return 0;
	if(X > n)return 0;
	if(Y <= 0)return 0;
	if(Y > m)return 0;
	return (a[Z][XX][YY] == a[Z][X][Y]);
}
ll ceka(ll X, ll Y)
{
	if(X <= 0)return 0;
	if(X > n)return 0;
	if(Y <= 0)return 0;
	if(Y > m)return 0;
	if(x[X][Y] == -1)
		return 1;
	return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m >> t;
    for(ll i = 1; i <= n; i++)
    	for(ll j = 1; j <= m; j++)
    	{
    		char ct;
    		cin >> ct;
 	   		a[0][i][j] = ct - '0';
 	   		x[i][j] = -1;
    	}
    vector<pair<ll, ll > > v;
 	for(ll k = 1; k <= 1; k++)
 	{
 		// cout << "\n";
	    for(ll i = 1; i <= n; i++)
	    {
    		for(ll j = 1; j <= m; j++)
    		{
    			ll hz = 0;
    			for(ll f = 0; f < 4; f++)
    				if(cek(i + dx[f], j + dy[f], i, j, 1 - (k % 2)))
    					hz++;
    			// cout << k << " " << i << " " << j << " " << hz << "\n";
    			if(hz)
    				v.pb(mp(i, j));
    		}
	    }
 	}
 	queue<pair<ll, ll> >  q;
 	for(ll i = 0; i < v.size(); i++)
 	{
 		x[v[i].fi][v[i].se] = 0;
 		q.push(v[i]);
 	}
 	while(!q.empty())
 	{
 		ll X = q.front().fi;
 		ll Y = q.front().se;
 		// cout << X << " " << Y << " " << x[X][Y] << "\n";
 		// ll tmp;cin>>tmp;
 		q.pop();
 		for(ll i = 0; i < 4; i++)
 			if(ceka(X + dx[i], Y + dy[i]))
 			{
 				q.push(mp(X + dx[i], Y + dy[i]));
 				x[X + dx[i]][Y + dy[i]] = x[X][Y] + 1;
 			}
 	}
 	while(t--)
 	{
 		ll ta, tb, tc;
 		cin >> ta >> tb >> tc;
 		ll isi = a[0][ta][tb];
 		if(x[ta][tb] == -1 || x[ta][tb] >= tc)
 			cout << isi << "\n";
 		else
 		{
 			ll prt = tc - x[ta][tb];
 			// cout << prt << "\n";
 			prt %= 2;
 			cout << (isi + prt) % 2 << "\n";
 		}
 	}
}