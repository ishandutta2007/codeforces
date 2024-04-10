#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1 
#define MAXN 200001
int T,N,M,a[MAXN],b[MAXN],l[MAXN],r[MAXN],tr[MAXN*4],tg[MAXN*4];
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),tr[k]=tr[ls(k)]+tr[rs(k)]:tr[k]=b[l],tg[k]=-1;}
void pt(int k,int l,int r,int v){tr[k]=v*(r-l+1);tg[k]=v;}void dwn(int k,int l,int r){if(tg[k]!=-1)pt(ls(k),l,R,tg[k]),pt(rs(k),L,r,tg[k]),tg[k]=-1;}
void upd(int k,int l,int r,int x,int y,int v){l<=y&&r>=x?l<x||r>y?dwn(k,l,r),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),tr[k]=tr[ls(k)]+tr[rs(k)]:(pt(k,l,r,v),0):0;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k,l,r),ask(ls(k),l,R,x,y)+ask(rs(k),L,r,x,y):tr[k]:0;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N){char c;cin>>c;a[i]=c-'0';}For(i,1,N){char c;cin>>c;b[i]=c-'0';}FOR(i,M,1)cin>>l[i]>>r[i];build(1,1,N);
		bool flag=1;For(i,1,M){int k=ask(1,1,N,l[i],r[i]);if(k*2==r[i]-l[i]+1){cout<<"NO\n";flag=0;break;}upd(1,1,N,l[i],r[i],k*2>r[i]-l[i]+1);}
		if(flag)For(i,1,N)if(ask(1,1,N,i,i)!=a[i]){cout<<"NO\n";flag=0;break;}if(flag)cout<<"YES\n";
	}
	return 0;
}