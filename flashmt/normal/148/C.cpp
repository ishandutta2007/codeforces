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
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,wow,oh,a[111],OH,WOW;

int wrong()
{
	int s=0,mx=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<1 || a[i]>50000) return 1;
		if (i>1)
		{
			if (a[i]>s) WOW--;
			else
				if (a[i]>mx) OH--;
		}
		mx=max(mx,a[i]);
		s+=a[i];
	}
	if (WOW || OH) return 1;
	return 0;
}

int main()
{
	int s=1,i=1;
	cin >> n >> oh >> wow;
	OH=oh; WOW=wow;
	if (!wow)
	{
		a[1]=1000;
		while (i+oh<n) a[++i]=1000;
		while (i<=n) ++i, a[i]=a[i-1]+1;
	}
	else
	{
		a[1]=1;
		while (wow--)	a[++i]=s+1,	s+=a[i];
		while (i+oh<n) ++i, a[i]=a[i-1], s+=a[i];
		while (oh--) 
		{
			i++; 
			a[i]=a[i-1]+1;
			while (a[i]>s)
			{
				s=++a[1];
				for (int j=2;j<=1+WOW;j++) a[j]=s+1, s+=a[j];
				for (int j=WOW+2;j<i;j++) a[j]=a[j-1], s+=a[j];
				a[i]=a[i-1]+1;
			}
			s+=a[i];
		}
	}
	if (wrong()) puts("-1");
	else
		for (int i=1;i<=n;i++) cout << a[i] << ' ';
}