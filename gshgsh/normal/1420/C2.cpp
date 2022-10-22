#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 300001
int T,N,M,a[MAXN];ll mx[MAXN*4][2],mn[MAXN*4][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void psh(int k)
{
	mx[k][0]=max(mx[ls(k)][0]+mx[rs(k)][0],mx[ls(k)][1]-mn[rs(k)][1]),mx[k][1]=max(mx[ls(k)][0]+mx[rs(k)][1],mx[ls(k)][1]-mn[rs(k)][0]);
	mn[k][0]=min(mn[ls(k)][0]+mn[rs(k)][0],mn[ls(k)][1]-mx[rs(k)][1]),mn[k][1]=min(mn[ls(k)][0]+mn[rs(k)][1],mn[ls(k)][1]-mx[rs(k)][0]);
}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),psh(k),0:(mx[k][0]=mn[k][0]=0,mx[k][1]=mn[k][1]=a[l]);}
void upd(int k,int l,int r,int x,int v){l!=r?x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),psh(k),0:(mx[k][0]=mn[k][0]=0,mx[k][1]=mn[k][1]=v);}
int main()
{
	T=get();
	while(T--)
	{
		int N=get(),M=get();For(i,1,N)a[i]=get();build(1,1,N);
		cout<<mx[1][1]<<endl;For(i,1,M){int l=get(),r=get();swap(a[l],a[r]);upd(1,1,N,l,a[l]),upd(1,1,N,r,a[r]);cout<<mx[1][1]<<endl;}
	}
	return 0;
}