#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
const ld eps = 1e-9;
ll t, n, k, a[NN], p[NN], cnt[NN], ada;
ll cek()
{
	for(ll i = 1; i < n; i++)
		if(a[i] - 1 > a[i + 1])
			return 0;
	return 1;
}
void cetak()
{
	for(ll i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
}
void cari()
{
	ll hz = 1;
	ll bts = -1;
	for(ll i = 0; i <= 100; i++)
		cnt[i] = 1;
	for(ll i = 0; i <= 100; i++)
	{
		p[i] = hz;
		p[i + 1] = hz * 2LL;
		if(hz >= k)
		{
			bts = i + 1;
			break;
		}
		hz *= 2LL;
	}
	for(ll i = 1; i <= n - bts; i++)
		a[i] = i;
	if(bts > n)
	{
		ada = 0;
		return ;
	}
	ll zz = n - bts;
	// cout << bts << "\n";
	for(ll i = n - bts + 1; i <= n; i++)
	{
		ll pan = p[n - i - 1];
		ll hv = 0;
		ll ke = 0;
		ll lp = 0;
		// cout << i << " " << pan << "\n";
		if(pan == 0)
			pan = 1;
		for(ll j = 1; j <= 100; j++)
		{
			hv += pan;
			// cout << " " << j << " " << hv << " " << k<< "\n";
			if(hv >= k)
			{
				k -= lp;
				ke = j;
				break;
			}
			lp += pan;
			pan /= 2;
			if(pan == 0)pan = 1;
		}
		// cout << i << " " << k << " " << ke << "\n";
		ll kan = 0;
		if(ke > 1)
			kan = 1;
		vector<ll> hai;
		for(ll j = 1; j <= 100; j++)
		{
			if(cnt[j])
			{
				hai.pb(j);
				ke--;
			}
			if(ke == 0)
			{
				// cout << "hai\n";
				a[i] = j + zz;
				cnt[j] = 0;
				hai.pop_back();
				reverse(hai.begin(), hai.end());
				for(auto zzz : hai)
				{
					i++;
					a[i] = zzz + zz;
					cnt[zzz] = 0;
				}
				break;
			}
		}
	}
	if(k > 1)ada = 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
    	cin >> n >> k;
    	ll kk = k;
    	ada = 1;
    	cari();
    	if(!ada)cout << -1 << "\n";
    	else cetak();

    	// for(ll i = 1; i <= n; i++)
    	// 	a[i] = i;
    	// do
    	// {
    	// 	if(cek())
    	// 	{
    	// 		kk--;
    	// 		if(kk == 0)
    	// 		{
    	// 			cetak();
    	// 			break;
    	// 		}
    	// 	}
    	// }
    	// while(next_permutation(a + 1, a + 1 + n));
    	// if(kk > 0)
    	// {
    	// 	cout << -1 << "\n";
    	// }
    	// cout << "\n\n";
    }
}