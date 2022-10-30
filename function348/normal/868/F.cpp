#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
typedef long long LL;
int c[N],a[N];
LL f[N],g[N];
int p,q,n,k;
LL tot;
void move(int l,int r)
{
	while (l<p) p--,tot+=c[a[p]],c[a[p]]++;
	while (r>q) q++,tot+=c[a[q]],c[a[q]]++;
	while (p<l) c[a[p]]--,tot-=c[a[p]],p++;
	while (r<q) c[a[q]]--,tot-=c[a[q]],q--;
}
void work(int l,int r,int fl,int fr)
{
	if (fl>fr) return;
	int mid=(fl+fr)>>1,mi;
	LL mx=1LL<<60;
	for (int i=l;i<=r;i++)
	if (i<mid) 
	{
		move(i+1,mid);
		if (f[i]+tot<mx) mx=f[i]+tot,mi=i;
	}
	g[mid]=mx;
	work(l,mi,fl,mid-1);
	work(mi,r,mid+1,fr);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0]=0;
	for (int i=1;i<=n;i++) f[i]=1LL<<60;
	while (k--)
	{
		p=1,q=0,tot=0;
		for (int i=1;i<=n;i++) c[i]=0;
		work(0,n-1,1,n);
		for (int i=0;i<=n;i++) f[i]=g[i],g[i]=0;
	}
	cout<<f[n];
	return 0;
}