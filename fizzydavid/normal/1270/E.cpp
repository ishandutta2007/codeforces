//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int n;
pair<int,int> a[1011];
ll div2(ll x)
{
	if (x>=0) return x/2;
	else return -(-x+1)/2;
}
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &a[i].FF, &a[i].SS);
	}
	while (true)
	{
		vector<int> v;
		for (int i=1; i<=n; i++)
		{
			if ((a[i].FF+a[i].SS)%2==0) v.PB(i);
		}
		if (v.size()==n||v.size()==0)
		{
			for (int i=1; i<=n; i++)
			{
				a[i] = MP(div2(a[i].FF-a[i].SS), div2(a[i].FF+a[i].SS));
			}
		}
		else
		{
			printf("%d\n", int(v.size()));
			for (auto x : v) printf("%d ", x);
			return 0;
		}
	}
	return 0;
}