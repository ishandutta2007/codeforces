#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
#define INF 0x3fffffff
int N,M,a[MAXN],tg[MAXN*4];
struct seg
{
	int l,r,v;seg(){l=MAXN,r=v=0;}seg(int type){l=MAXN,r=0,v=type*INF;}seg(int a,int b,int c){l=a;r=b;v=c;}
	friend bool operator<(const seg&a,const seg&b){return a.v<b.v;}
	friend seg operator+(const seg&a,const seg&b){return seg(min(a.l,b.l),max(a.r,b.r),a.v+b.v);}
};
struct node
{
	seg sum,lmx,rmx,lmn,rmn,mx,mn;node(){sum=seg();lmx=rmx=mx=seg(-1);lmn=rmn=mn=seg(1);}
	node(seg a,seg b,seg c,seg d,seg e,seg f,seg g){sum=a;lmx=b;rmx=c;lmn=d;rmn=e;mx=f;mn=g;}
	node(int x,int v){sum=lmx=rmx=lmn=rmn=mx=mn=seg(x,x,v);}
	friend node operator+(const node&a,const node&b){return node(a.sum+b.sum,max(a.lmx,a.sum+b.lmx),max(b.rmx,b.sum+a.rmx),min(a.lmn,a.sum+b.lmn),min(b.rmn,b.sum+a.rmn),max(max(a.mx,b.mx),a.rmx+b.lmx),min(min(a.mn,b.mn),a.rmn+b.lmn));}
}sum[MAXN*4];
void pt(int k)
{
	swap(sum[k].lmn,sum[k].lmx);swap(sum[k].rmn,sum[k].rmx);swap(sum[k].mn,sum[k].mx);
	sum[k].sum.v=-sum[k].sum.v;sum[k].lmn.v=-sum[k].lmn.v;sum[k].lmx.v=-sum[k].lmx.v;
	sum[k].rmn.v=-sum[k].rmn.v;sum[k].rmx.v=-sum[k].rmx.v;sum[k].mn.v=-sum[k].mn.v;sum[k].mx.v=-sum[k].mx.v;tg[k]^=1;
}
void dwn(int k){if(tg[k])pt(ls(k)),pt(rs(k)),tg[k]=0;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),sum[k]=sum[ls(k)]+sum[rs(k)]:sum[k]=node(l,a[l]);}
void upd(int k,int l,int r,int x,int v){l!=r?dwn(k),x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),sum[k]=sum[ls(k)]+sum[rs(k)]:sum[k]=node(x,v);}
void upd1(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return pt(k);dwn(k);x<=R&&(upd1(ls(k),l,R,x,y),0),y>=L&&(upd1(rs(k),L,r,x,y),0),sum[k]=sum[ls(k)]+sum[rs(k)];}
node ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return sum[k];dwn(k);node ans;x<=R&&(ans=ans+ask(ls(k),l,R,x,y),0);y>=L&&(ans=ans+ask(rs(k),L,r,x,y),0);return ans;}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();build(1,1,N);M=get();
	For(i,1,M)
	{
		int opt=get(),x=get(),y=get();
		if(opt==1)
		{
			int k=get(),ans=0;vector<pair<int,int>>Seg;
			while(k--){node tmp=ask(1,1,N,x,y);if(tmp.mx.v<0)break;ans+=tmp.mx.v;Seg.push_back({tmp.mx.l,tmp.mx.r});upd1(1,1,N,tmp.mx.l,tmp.mx.r);}
			cout<<ans<<'\n';for(auto i:Seg)upd1(1,1,N,i.first,i.second);
		}
		else upd(1,1,N,x,y);
	}
	return 0;
}