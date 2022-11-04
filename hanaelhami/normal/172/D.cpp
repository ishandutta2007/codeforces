#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e7 + 20;

int res[maxn] , t[maxn];

int main()
{
	int a , n;
	cin >> a >> n;
	for(int i = 2; i < a + n; i++)
		if(!t[i])
		{
			t[i] = i;
			for(ll j = (ll)(i) * i; j < a + n; j += i)
				t[j] = i;
		}
	res[1] = 1;
	for(int i = 2; i < a + n; i++)
	{
		res[i] = res[i / t[i]];
		if(res[i] % t[i] == 0)
			res[i] /= t[i];
		else
			res[i] *= t[i];
	}
	ll ans = 0;
	for(int i = a; i < a + n; i++)
		ans += res[i];
	cout << ans << endl;
}