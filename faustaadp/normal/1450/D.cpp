#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 3e5 + 5;
ll t, n;
ll a[NN], BIT[NN], cnt[NN];
pair<ll, ll> A[NN];
vector<ll> v[NN], v2[NN];
void upd(ll pos, ll bb)
{
	// cout << "upd" << pos << " " << bb << "\n";
	// pos = n - pos + 1;
	for(ll i = pos; i <= n; i += (i & (-i)))
		BIT[i] += bb;
}
ll que(ll pos)
{
	ll H = 0;
	// pos = n - pos + 1;
	for(ll i = pos; i > 0; i -= (i & (-i)))
		H += BIT[i];
	return H;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		priority_queue<ll> pq;
		priority_queue<ll> pq2;
		for(ll i = 1; i <= n; i++)
			cnt[i] = 0;
		for(ll i = 1; i <= n; i++)
		{
			cin >> a[i];
			cnt[a[i]]++;
			pq.push(a[i]);
			v[i].clear();
			v2[i].clear();
			BIT[i] = 0;
			A[i] = mp(a[i], i);
		}
		for(ll i = 1; i <= n; i++)
			if(cnt[i] != 1)
				upd(i, 1);
		set<ll> st;
		st.insert(0);
		st.insert(n + 1);
		sort(A + 1, A + 1 + n);
		for(ll i = 1; i <= n; i++)
		{
			ll idx = A[i].se;
			auto it = st.lower_bound(idx);
			ll kanan = *it;
			it--;
			ll kiri = *it;
			ll mi = min(kanan - idx - 1, idx - kiri - 1);
			ll hz = kanan - kiri - 1;
			for(ll j = 1; j <= mi; j++)
				v2[j + 1].pb(a[idx]);
			for(ll j = hz; j >= (hz - mi + 1); j--)
				v[j].pb(a[idx]);
			st.insert(idx);
			if(hz < n)
				v[hz + 1].pb(a[idx]);
		}
		ll has = 0;
		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 0; j < v[i].size(); j++)
			{
				// cout << "-" << v[i][j] << "\n";
				ll z = v[i][j];
				cnt[z]--;
				if(cnt[z] == 1)upd(z, -1);
				if(cnt[z] == 0)upd(z, 1);
			}
			for(ll j = 0; j < v2[i].size(); j++)
			{
				// cout << "+" << v2[i][j] << "\n";
				ll z = v2[i][j];
				cnt[z]++;
				if(cnt[z] == 1)upd(z, -1);
				if(cnt[z] == 2)upd(z, 1);
			}
			// cout << (n - i + 1) << " " << pq.top() << " " << que(n - i + 1) << "\n";
			// for(ll j = 1; j <= n; j++)
			// 	cout << cnt[j];
			// cout << "\n";
			if(que(n - i + 1) == 0)
				cout << 1;
			else
				cout << 0;
		}
		cout << "\n";
		// cout << has << "\n";
	}
}