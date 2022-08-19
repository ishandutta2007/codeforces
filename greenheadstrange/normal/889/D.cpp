#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define ll long long
#define ld long double
#define maxn 2005
ll ns[maxn];
int n; 
ll x[maxn], y[maxn];
int ans = 0;
struct fs
{
	ll a, b;
	fs(){a = b = 0;}
	fs(ll x, ll y)
	{
		a = x, b = y;
		if(b < 0) 
			b = -b, a = -a;
	}
	bool operator < (const fs &x)const
	{
		return a * x.b < b * x.a;
	} 
	bool operator == (const fs &x)const
	{
		return a * x.b == b * x.a;
	}
	bool operator > (const fs &x)const
	{
		return a * x.b > b * x.a;
	}
	void otp()
	{
		cout<<a<<"/"<<b<<endl;
	}
};
map <fs, int> q;
void judge(ll a, ll b)
{	// ax + by;
	fs n1 = fs(a, b);
	if(q[n1]) return;
//	cout<<"JUDGE"<<a<<" "<<b<<endl;
	for(int i = 1; i <= n; i++)
		ns[i] = x[i] * a + y[i] * b; 
	sort(ns + 1, ns + 1 + n);
	ll nsum;
	bool flag = 0;
	for(int i = (n + 1) / 2; i >= 1; i--)
		if((ns[i] + ns[n + 1 - i]) != nsum && flag)
			return ;
		else nsum = ns[i] + ns[n + 1 - i], flag = 1;
	ans++; 
//	cout<<"TRUE"<<endl;
	q[n1] = 1;
}
bool hv[maxn];
fs l[2][maxn], r[2][maxn];
int flag[2][maxn];
ll inf = 2000000005;
int main() 
{
	scanf("%d", &n);
	ll sum[2] = {0, 0};
	for(int i = 1; i <= n; i++)
		scanf("%I64d%I64d", &x[i], &y[i]), 
		sum[0] += x[i], sum[1] += y[i];
	for(int i = 1; i <= n; i++)
		hv[i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!hv[j] || !hv[i]) continue;
			if((x[i] + x[j]) * (ll)n != sum[0] * 2) continue;
			if((y[i] + y[j]) * (ll)n != sum[1] * 2) continue;
			hv[i] = hv[j] = 0;
		}
	int ncnt = 0;
	for(int i = 1; i <= n; i++)
		if(hv[i]) ncnt++, x[ncnt] = x[i], y[ncnt] = y[i];
//	
	sum[0] = sum[1] = 0;	
	n = ncnt;
	for(int i = 1; i <= n; i++)
		sum[0] += x[i], sum[1] += y[i];

	if(n <= 2)
		printf("-1\n");
	else
	{
		judge(0, 1);
		// 0 : min 
		// cal l, r
		for(int i = 1; i <= n; i++)
		{
			flag[0][i] = flag[1][i] = 1;
			l[0][i] = l[1][i] = fs(-inf, 1);
			r[0][i] = r[1][i] = fs(inf, 1);
			for(int j = 1; j <= n; j++)
			{
				if(j == i) continue;
				fs n1 = fs(x[j] - x[i], y[i] - y[j]);
			//	cout<<"BMAX"<<i<<" "<<" "<<x[i] - x[j]<<" "<<y[i] - y[j]<<endl;
			//	n1.otp();
			//	l[1][i].otp(), r[1][i].otp();
				if(y[i] == y[j])
					if(x[i] > x[j]) flag[0][i] = 0;
					else flag[1][i] = 0;
				else
				{
					if(y[i] > y[j])
					{
						if(n1 > l[1][i]) 
							l[1][i] = n1;
						if(n1 < r[0][i])
							r[0][i] = n1; 
					}
					else
					{
						if(n1 < r[1][i]) 
							r[1][i] = n1;
						if(n1 > l[0][i])
							l[0][i] = n1; 
					}
				}
			}
		//	while(1);
		//	cout<<"BMAX"<<i<<" "<<endl;
		//	l[1][i].otp(), r[1][i].otp();
		//	cout<<"BMIN"<<i<<" "<<endl;
		//	l[0][i].otp(), r[0][i].otp();
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(!flag[1][i] || !flag[0][j]) continue;
				fs nl = l[1][i];
				if(nl < l[0][j]) nl = l[0][j];
				fs nr = r[1][i];
				if(nr > r[0][j]) nr = r[0][j];
				if(nl > nr) continue;
				if((y[i] + y[j]) * n == sum[1] * 2) continue;
				fs ns = fs(sum[0] * 2 - (x[i] + x[j]) * n, (y[i] + y[j]) * n - sum[1] * 2);
				if(ns < nl) continue;
				if(ns > nr) continue;
				judge(ns.b, ns.a);
			}	
		printf("%d\n", ans);
	}
//	system("pause");
	return 0;
}
/*
9
-100 -50
-75 25
-50 100
-25 -25
0 -100
25 75
50 0
75 -75
100 50
*/