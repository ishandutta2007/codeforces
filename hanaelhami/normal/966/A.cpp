#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;

int a[maxn] , b[maxn] , n , m , ce , cs , v , t = 0;

int f(int x1 , int y1 , int x2 , int y2)
{
    t++;
	int ans = 2e9;

	if(y1 == y2)
		ans = abs(x1 - x2);
    t++;
	int k = lower_bound(a , a + cs , x1) - a;
	if(cs && k < cs)
		ans = min(ans , abs(a[k] - x1) + abs(y1 - y2) + abs(a[k] - x2));
	if(cs && k > 0)
	{
	    t++;
		k--;
		ans = min(ans , abs(a[k] - x1) + abs(y1 - y2) + abs(a[k] - x2));
	}

	int t = (abs(y1 - y2) + v - 1) / v;

	k = lower_bound(b , b + ce , x1) - b;
	if(ce && k < ce)
		ans = min(ans , abs(b[k] - x1) + t + abs(b[k] - x2));
	if(ce && k > 0)
	{
		k--;
		ans = min(ans , abs(b[k] - x1) + t + abs(b[k] - x2));
	}
	t++;

	return ans;

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	t++;

	cin >> n >> m >> cs >> ce >> v;

	for(int i = 0; i < cs; i++)
		cin >> a[i];
	for(int i = 0; i < ce; i++)
		cin >> b[i];

	int q;
	cin >> q;
	while(q--)
	{
		int x1 , y1 , x2 , y2;
		cin >> x1 >> y1 >> x2 >> y2;

		swap(x1 , y1);
		swap(x2 , y2);

		cout << min(f(x1 , y1 , x2 , y2) , f(x2 , y2 , x1 , y1)) << endl;
	}
	
	t++;

}