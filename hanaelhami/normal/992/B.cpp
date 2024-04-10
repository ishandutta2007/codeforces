#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l , r , x , y;
	cin >> l >> r >> x >> y;

	if(y % x != 0)
		return cout << 0 << endl , 0;

	y /= x;
	if(l > r)
		return cout << 0 << endl , 0;

	int res = 0;
	for(int i = 1; i * i <= y; i++)
		if(y % i == 0)
		{
			int tmp = y / i;
			if(l <= i * x && i * x <= r && l <= tmp * x && tmp * x <= r && __gcd(tmp , i) == 1)
			{
				if(tmp == i)
					res++;
				else
					res += 2;
			}
		}

	cout << res << endl;
}