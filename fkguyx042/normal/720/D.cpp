#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 1000000007

using namespace std;
int i,j,m,n,p,k,Ans[N*4],Ans_add[N*4],Max[N*4],Max_add[N*4];
int sx,sy,ex,ey,change[N];
struct Node
{
		int type,x,y;
};
vector<Node>block[N];
void jia(int &x,int y)
{
		x+=y; if (x>=Mo) x-=Mo;
}
void Ans_down(int t,int len)
{
		if (Ans_add[t]==-1) return;
		Ans_add[ls]=Ans_add[rs]=0;
		Ans[ls]=Ans[rs]=0;
		Ans_add[t]=-1;
}
void ins(int ll,int rr,int c,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{
				Ans[t]=1ll*c*(r-l+1)%Mo;
				Ans_add[t]=c;
		}
		else 
		{
				Ans_down(t,r-l+1);
				if (ll<=mid) ins(ll,rr,c,l,mid,ls);
				if (rr>mid)  ins(ll,rr,c,mid+1,r,rs);
				Ans[t]=(Ans[ls]+Ans[rs])%Mo; 
		}
}
int getans(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return Ans[t];
		Ans_down(t,r-l+1);
		int S=0;
		if (ll<=mid) jia(S,getans(ll,rr,l,mid,ls));
		if (rr>mid)  jia(S,getans(ll,rr,mid+1,r,rs));
		return S;
}
//----------------------------------------------------------------
void Max_down(int t,int l,int r)
{
		if (Max_add[t]==-1) return;
		if (Max_add[t]==0)
		{
			  Max[ls]=Max[rs]=0;
			  Max_add[ls]=Max_add[rs]=0;
		}
		else 
		{
			  Max[ls]=mid;
			  Max[rs]=r;
			  Max_add[ls]=Max_add[rs]=1;
		}
		Max_add[t]=-1;
}
void update(int ll,int rr,int c,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{
				Max_add[t]=c;
				if (c==1) Max[t]=r;
				else Max[t]=0;
		}
		else 
		{
				Max_down(t,l,r);
				if (ll<=mid) update(ll,rr,c,l,mid,ls);
				if (rr>mid)  update(ll,rr,c,mid+1,r,rs);
				Max[t]=max(Max[ls],Max[rs]); 
		}
}
int FindMax(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return Max[t];
		Max_down(t,l,r);
		int S=0;
		if (ll<=mid) S=max(S,FindMax(ll,rr,l,mid,ls));
		if (rr>mid)  S=max(S,FindMax(ll,rr,mid+1,r,rs));
		return S; 
}
inline int cmp(int a,int b)
{
		return a>b;
}
int main()
{
	memset(Max_add,-1,sizeof(Max_add));
	memset(Ans_add,-1,sizeof(Ans_add));
	scanf("%d%d%d",&n,&m,&k);
	for (;k--;)
	{
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
			block[sx].pb((Node){1,sy,ey});
			block[ex+1].pb((Node){-1,sy,ey});
	}
	ins(1,1,1,1,m,1);
	for (i=0;i<(int)block[1].size();++i)
			update(block[1][i].x,block[1][i].y,1,1,m,1);
	for (j=2;j<=n;++j)
	{
			change[0]=0;
			for (i=0;i<(int)block[j].size();++i)
				if (block[j][i].type==1)
				{
					 int gg=block[j][i].y;
					 if (gg==m) continue;
					 change[++change[0]]=gg;
				}
			sort(change+1,change+change[0]+1,cmp);
			change[0]=unique(change+1,change+change[0]+1)-(change+1);
			for (i=1;i<=change[0];++i)
			{
					int gg=change[i];
					int lim=FindMax(1,gg+1,1,m,1);
					if (lim==gg+1) continue;
					ins(gg+1,gg+1,getans(lim+1,gg+1,1,m,1),1,m,1);
			}
			for (i=0;i<(int)block[j].size();++i)
				if (block[j][i].type==-1)
					update(block[j][i].x,block[j][i].y,0,1,m,1);
			for (i=0;i<(int)block[j].size();++i)
				if (block[j][i].type==1)
					update(block[j][i].x,block[j][i].y,1,1,m,1),
					ins(block[j][i].x,block[j][i].y,0,1,m,1);
	}
	printf("%d\n",getans(Max[1]+1,m,1,m,1));
}