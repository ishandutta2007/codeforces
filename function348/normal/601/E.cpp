#include<cstdio>
#include<iostream>
using namespace std;
const int C=31000,N=C*4,K=1100,P=10000019,Q=1000000007;
struct Edge {int y,ne;};
int n,k,num,m,q;
int f[20][K],w[C],v[C],p[C];
Edge e[N*16];int last[N];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void cover(int i,int l,int r,int ll,int rr,int k)
{
	if (ll>rr) return;
	if (ll<=l&&r<=rr)
	{
		add(i,k);
		return;
	}
	int mid=(l+r)>>1;
	if (ll<=mid) cover(i*2,l,mid,ll,rr,k);
	if (rr> mid) cover(i*2+1,mid+1,r,ll,rr,k);
}
void dfs(int i,int l,int r,int p,int de)
{
	if (l>p) return;
	int mid=(l+r)>>1;
	for (int j=0;j<=k;j++) f[de][j]=f[de-1][j];
	for (int j=last[i];j;j=e[j].ne) 
	for (int q=k;q>=w[e[j].y];q--)
		f[de][q]=max(f[de][q],f[de][q-w[e[j].y]]+v[e[j].y]);
		
		
	if (l==r)
	{
		int res=0;
		for (int j=k;j>=1;j--) res=(1LL*res*P+f[de][j])%Q;
	//	for (int j=1;j<=k;j++) printf("%d ",f[de][j]);printf("\n");
		printf("%d\n",res);	
		return;
	}
		
	dfs(i*2,l,mid,p,de+1);
	dfs(i*2+1,mid+1,r,p,de+1);
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	scanf("%d%d",&n,&k);
	m=0;
	for (int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
	scanf("%d",&q);
	for (int i=1;i<=n;i++) p[i]=1;
	while (q--)
	{
		int kd;
		scanf("%d",&kd);
		if (kd==1)
		{
			n++;
			scanf("%d%d",&v[n],&w[n]);
			p[n]=m+1;
		}
		if (kd==2)
		{
			int x;
			scanf("%d",&x);
			cover(1,1,C,p[x],m,x);
			p[x]=-1;
		}
		if (kd==3) m++;
	}
	for (int i=1;i<=n;i++) if (p[i]!=-1) cover(1,1,C,p[i],m,i);
	dfs(1,1,C,m,1);
	return 0;
}