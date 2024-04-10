#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define int ll

const int maxn = 1e6 + 20;

int t[maxn * 2];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n , k;
	cin >> n >> k;
	for(int i = 0; i < 64; i++)
		if(bit(n , i))
			t[i + maxn]++ , k--;
	if(k < 0)
		return cout << "No" << endl , 0;
	cout << "Yes" << endl;
	for(int i = 2 * maxn - 1; i >= 1; i--)
	{
		if(k >= t[i])
		{
			k -= t[i];
			t[i - 1] += 2 * t[i];
			t[i] = 0;
		}
		else
			break;
	}
	for(int i = 1; i < 2 * maxn; i++)
		if(k && t[i])
		{
			k--;
			t[i]--;
			t[i - 1] += 2;
			i -= 2;
		}
	for(int i = maxn * 2 - 1; i >= 0; i--)
		for(int j = 0; j < t[i]; j++)
			cout << i - maxn << " ";
	cout << endl;
}