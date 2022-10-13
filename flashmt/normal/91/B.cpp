#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int n,a[100100],f[500500],re[100100];

int find(int nd,int l,int r,int x)
{
	if (l==r)
	{
		if (f[nd]<x) return l;
		return -1;
	}
	int m=(l+r)/2;
	if (f[nd*2]<x) return find(nd*2,l,m,x);
	if (f[nd*2+1]<x) return find(nd*2+1,m+1,r,x);
	return -1;
	
}

void add(int nd,int l,int r,int x)
{
	if (l==r) f[nd]=a[x];
	else
	{
		int m=(l+r)/2;
		if (x<=m) add(nd*2,l,m,x);
		else add(nd*2+1,m+1,r,x);
		f[nd]=min(f[nd],a[x]);
	}
}

void init(int nd,int l,int r)
{
	f[nd]=oo;
	int m=(l+r)/2;
	if (l<r)
	{
		init(nd*2,l,m);
		init(nd*2+1,m+1,r);
	}
}

int main()
{
	//freopen("b.in.2","r",stdin);
	int i,x;
	cin >> n;
	init(1,1,n);
	fr(i,0,n-1) scanf("%d",&a[n-i]);
	fr(i,1,n)
	{
		x=find(1,1,n,a[i]);
		if (x>=0) re[i]=i-x-1;
		else re[i]=-1;
		add(1,1,n,i);
	}
	frr(i,n,1) printf("%d ",re[i]);
	printf("\n");
	return 0;
}