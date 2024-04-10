#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n, k, i, a[303030], p[303030], naik[303030], K, has;
pair<ll,ll> A[303030];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(i = 1; i <= n; i++)
		cin >> a[i];
	for(i = n; i > 1; i--)
	{
		p[i] = p[i+1] + a[i];
		A[i] = mp(p[i], i);
	}
	sort(A+2, A+1+n);
	reverse(A+2, A+1+n);
	naik[1] = 1;
	for(i = 2; i <= k; i++)
		naik[A[i].se] = 1;
	for(i = 1; i <= n; i++)
	{
		if(naik[i])
			K++;
		// cout << a[i] << " " << K << "\n";
		has += K * a[i];
	}
	cout << has << "\n";
}