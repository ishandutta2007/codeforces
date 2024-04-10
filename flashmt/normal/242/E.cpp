#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int f[22][500000],n,a[100100];
bool active[22][500000];

void init(int z,int nd,int l,int r)
{
	if (l==r) 
	{
		f[z][nd]=(a[l]>>z&1);
		return;
	}
	int m=(l+r)/2;
	init(z,nd*2,l,m);
	init(z,nd*2+1,m+1,r);
	f[z][nd]=f[z][nd*2]+f[z][nd*2+1];
}

long long get(int f[],bool active[],int nd,int l,int r,int x,int y)
{
	if (l==x && r==y) return f[nd];
	int m=(l+r)/2;
	long long u=0,v=0;
	if (x<=m) u=get(f,active,nd*2,l,m,x,min(y,m));
	if (m<y) v=get(f,active,nd*2+1,m+1,r,max(x,m+1),y);
	return active[nd]?y-x+1-(u+v):u+v;
}

void flip(int f[],bool active[],int nd,int l,int r,int x,int y)
{
	if (l==x && r==y) 
	{
		f[nd]=r-l+1-f[nd];
		active[nd]^=1;
	}
	else
	{
		int m=(l+r)/2;
		if (x<=m) flip(f,active,nd*2,l,m,x,min(y,m));
		if (m<y) flip(f,active,nd*2+1,m+1,r,max(x,m+1),y);
		f[nd]=f[nd*2]+f[nd*2+1];
		if (active[nd]) f[nd]=r-l+1-f[nd];
	}
}

int main()
{
	int m,type,l,r,x;
	
	cin >> n;
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=0;i<20;i++) init(i,1,1,n);
		
	cin >> m;
	while (m--)
	{
		scanf("%d%d%d",&type,&l,&r);
		if (type==1)
		{
			long long sum=0;
			for (int i=0;i<20;i++) sum+=get(f[i],active[i],1,1,n,l,r)<<i;
			cout << sum << endl;
		}
		else
		{
			scanf("%d",&x);
			for (int i=0;i<20;i++)
				if (x>>i&1) flip(f[i],active[i],1,1,n,l,r);
		}
	}
}