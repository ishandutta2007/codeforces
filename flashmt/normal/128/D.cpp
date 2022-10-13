#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

int n,a[100100],d[100100];

int main()
{
	cin >> n;
	int mn=oo,mx=0;
	rep(i,n) 
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	rep(i,n) 
	{
		a[i]-=mn;
		if (a[i]>n)
		{
			puts("NO"); return 0;
		}
		d[a[i]]++;
	}
	mx-=mn;
	d[0]--; d[mx]--;
	fr(i,1,mx-1)
		if (d[i]<2)
		{
			puts("NO"); return 0;
		}
		else d[i]-=2;
	fr(i,0,mx)
		if (d[i])
		{
			if (d[i]>d[i+1])
			{
				puts("NO"); return 0;
			}
			d[i+1]-=d[i];
		}
	puts("YES");
}