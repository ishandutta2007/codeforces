#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll f[100010][21],res;
int num[100010],sum[100010],n,k,curl,curr;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll calc(const int &x,const int &y)
{
	if (x>y) return 0;
	while (curr<y) curr++,res+=sum[num[curr]],sum[num[curr]]++;
	while (curl>x) curl--,res+=sum[num[curl]],sum[num[curl]]++;
	while (curr>y) sum[num[curr]]--,res-=sum[num[curr]],curr--;
	while (curl<x) sum[num[curl]]--,res-=sum[num[curl]],curl++;
	return res;
}

inline void gao(int l,int r,int ql,int qr,int now)
{
	int mid=(l+r)>>1,pos=0;
	for (int i=ql;i<=qr&&i<=mid;i++) if (f[i][now-1]+calc(i+1,mid)<f[mid][now]) pos=i,f[mid][now]=f[i][now-1]+calc(i+1,mid);
	if (l<mid) gao(l,mid-1,ql,pos,now);
	if (r>mid) gao(mid+1,r,pos,qr,now);
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) for (int j=0;j<=k;j++) f[i][j]=inf;
	for (int i=1;i<=k;i++)
	{
		memset(sum,0,sizeof(sum));
		res=0;curl=1;curr=0;
		gao(0,n,0,n,i);
	}
	printf("%lld\n",f[n][k]);
	return 0;
}