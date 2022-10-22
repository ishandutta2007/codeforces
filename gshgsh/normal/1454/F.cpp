#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define INF 0x3fffffff
#define MAXN 200001
int T,N,a[MAXN],mx[MAXN*4],mn[MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),mx[k]=max(mx[ls(k)],mx[rs(k)]),mn[k]=min(mn[ls(k)],mn[rs(k)]):mx[k]=mn[k]=a[l];}
int ask1(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?max(ask1(ls(k),l,R,x,y),ask1(rs(k),L,r,x,y)):mx[k]:0;}
int ask2(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?min(ask2(ls(k),l,R,x,y),ask2(rs(k),L,r,x,y)):mn[k]:INF;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();build(1,1,N);int mx=0;bool flag=0;
		For(i,1,N)
		{
			mx=max(mx,a[i]);int l=i+1,r=N-1,ans=-1;while(l<=r){int Min=ask2(1,1,N,i+1,R),Max=ask1(1,1,N,R+1,N);if(Max==Min&&mx==Min){ans=R;break;}if(mx>=Min&&mx>=Max)r=R-1;else if(mx<=Min&&mx<=Max)l=R+1;else break;}
			if(ans!=-1){cout<<"YES\n";put(i),putchar(' '),put(ans-i),putchar(' '),put(N-ans),putchar('\n');flag=1;break;}
		}
		if(!flag)cout<<"NO\n";
	}
	return 0;
}