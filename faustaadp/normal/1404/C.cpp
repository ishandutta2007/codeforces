#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll n, q, ST[4 * NN], LZ[4 * NN], idx, jaw[NN], x[NN], BIT[NN], a[NN];
vector<pair<ll, ll> > v[NN];
void turun(ll aa, ll bb, ll ee)
{
	if(LZ[ee])
	{
		ST[ee] += LZ[ee];
		if(aa < bb)
		{
			LZ[ee * 2] += LZ[ee];
			LZ[ee * 2 + 1] += LZ[ee];
		}	
		LZ[ee] = 0;
	}
}
void upd(ll aa, ll bb, ll cc, ll dd, ll ee, ll ff)
{
	turun(aa, bb, ee);
	if(bb < cc || dd < aa)
		return ;
	if(cc <= aa && bb <= dd)
	{
		LZ[ee] += ff;
		turun(aa, bb, ee);
	}
	else
	{
		ll ce = (aa + bb) / 2;
		upd(aa, ce, cc, dd, ee * 2, ff);
		upd(ce + 1, bb, cc, dd, ee * 2 + 1, ff);
		// cout << aa << " " << bb << " " << ST[ee] << "\n";
		ST[ee] = min(ST[ee * 2], ST[ee * 2 + 1]);
	}
}
void buang(ll aa, ll bb, ll ee)
{
	turun(aa, bb, ee);
	if(ST[ee] >= 0)	return ;
	if(aa == bb)
	{
		// cout << aa << " " << bb << " " << ee << "___\n";
		upd(1, n, aa, bb, 1, 1e18);	
	}
	else
	{
		ll ce = (aa + bb) / 2;
		buang(aa, ce, ee * 2);
		buang(ce + 1, bb, ee * 2 + 1);
	}
}
void cari(ll aa, ll bb, ll ee)
{
	turun(aa, bb, ee);
	if(ST[ee] > 0)	return ;
	if(aa == bb)
		idx = aa;
	else
	{
		ll ce = (aa + bb) / 2;
		turun(aa, ce, ee * 2);
		turun(ce + 1, bb, ee * 2 + 1);
		if(ST[ee * 2 + 1] == 0)
			cari(ce + 1, bb, ee * 2 + 1);
		else
			cari(aa, ce, ee * 2);
	}
}
void bupd(ll pos, ll z)
{
	for(ll i = pos; i <= n; i += (i & (-i)))
		BIT[i] += z;
}
ll bque(ll pos)
{
	ll H = 0;
	for(ll i = pos; i > 0; i -= (i & (-i)))
		H += BIT[i];
	return H;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(ll i = 1; i <= n; i++)
    {
    	ll ta;
    	cin >> ta;
    	ta = i - ta;
    	upd(1, n, i, i, 1, ta);
    }
    buang(1, n, 1);
    ll ma = 0;
    for(ll i = 1; i <= n; i++)
    {
    	idx = -1;
    	cari(1, n, 1);
    	if(idx == -1)
    		break;
    	upd(1, n, idx, n, 1, -1);
    	x[idx] = i; 
    	// cout << idx << " ___ " << i << "\n";
    	a[i] = idx;
    	buang(1, n, 1);
    	bupd(idx, 1);
    	ma = i;
    	// cout << idx << "\n";
    }
    for(ll i = 1; i <= q; i++)
    {
    	ll ta, tb;
    	cin >> ta >> tb;
    	ta += 1;
    	tb = n - tb;
    	v[ta].pb(mp(tb, i));
    	// cout << ta << " " << tb << "\n";
    }
    // return 0;
    ll lst = ma + 1;
    for(ll i = 1; i <= n; i++)
    {
    	for(ll j = 0; j < v[i].size(); j++)
    		jaw[v[i][j].se] = bque(v[i][j].fi);
    	if(x[i])
    	{
    		for(ll j = x[i]; j < lst; j++)
    		{
    			// cout << i << " " << j << " " << a[j] << "_\n";
    			bupd(a[j], -1);
    		}
    		lst = min(lst, x[i]);
    	}
    }
    for(ll i = 1; i <= q; i++)
    	cout << jaw[i] << "\n";

}