#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long
#define N 100010
#define M 25
using namespace std;
ll f[M][N];
int tot[N],num[N],lt,rt;
ll ans=0;
void update(int u,ll opt)
{
	ans=ans-1ll*tot[num[u]]*(tot[num[u]]-1)/2;
	tot[num[u]]=tot[num[u]]+opt;
	ans=ans+1ll*tot[num[u]]*(tot[num[u]]-1)/2;
}
void change(int l,int r)
{
	while(lt<l){update(lt,-1);lt++;}
	while(lt>l){lt--;update(lt,1);}
	while(rt<r){rt++;update(rt,1);}
	while(rt>r){update(rt,-1);rt--;}
}
void work(int k,int l,int r,int L,int R)
{
	if(l>r) return;
	int mid=(l+r)>>1,id=0;
	f[k][mid]=10000000000ll;
	for(int i=L;i<=R;i++)
	{
		change(i+1,mid);
		if(f[k][mid]>f[k-1][i]+ans)
		{
			f[k][mid]=f[k-1][i]+ans;
			id=i;
		}
	}
	if(l==r) return;
	work(k,l,mid,L,id);
	work(k,mid+1,r,id,R);
}
int main()
{
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	tot[num[1]]++;
	lt=rt=1;
	for(int i=1;i<=m;i++)
	work(i,1,n,0,n-1);
	printf("%lld",f[m][n]);
	return 0;
}