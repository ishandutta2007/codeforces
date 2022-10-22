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
int N,P,phi,M,K,val[10],pw[10][MAXN*20+1],a[MAXN],sum[MAXN*4],tg[MAXN*4],cnt[10][MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int getP(int x){int ans=1;For(i,1,K)while(x%val[i]==0)ans*=val[i],x/=val[i];return ans;}
void build(int k,int l,int r){if(l==r){sum[k]=a[l]%P;int x=getP(a[l]);a[l]/=x;tg[k]=a[l];For(i,1,K)while(x%val[i]==0)cnt[i][k]++,x/=val[i];return;}build(ls(k),l,R),build(rs(k),L,r),sum[k]=(sum[ls(k)]+sum[rs(k)])%P,tg[k]=1;}
void pt(int k,int v){sum[k]=1ll*sum[k]*v%P;int x=getP(v);v/=x;tg[k]=1ll*tg[k]*v%P;For(i,1,K)while(x%val[i]==0)cnt[i][k]++,x/=val[i];}
void dwn(int k)
{
	sum[ls(k)]=1ll*sum[ls(k)]*tg[k]%P,tg[ls(k)]=1ll*tg[ls(k)]*tg[k]%P,sum[rs(k)]=1ll*sum[rs(k)]*tg[k]%P,tg[rs(k)]=1ll*tg[rs(k)]*tg[k]%P,tg[k]=1;
	For(i,1,K)sum[ls(k)]=1ll*sum[ls(k)]*pw[i][cnt[i][k]]%P,cnt[i][ls(k)]+=cnt[i][k],sum[rs(k)]=1ll*sum[rs(k)]*pw[i][cnt[i][k]]%P,cnt[i][rs(k)]+=cnt[i][k],cnt[i][k]=0;
}
void upd1(int k,int l,int r,int x,int y,int v){if(l>=x&&r<=y)return pt(k,v);dwn(k);x<=R&&(upd1(ls(k),l,R,x,y,v),0),y>=L&&(upd1(rs(k),L,r,x,y,v),0),sum[k]=(sum[ls(k)]+sum[rs(k)])%P;}
void upd2(int k,int l,int r,int x,int v)
{
	if(l==r){int x=getP(v);v/=x;tg[k]=1ll*tg[k]*pow(v,phi-1)%P;For(i,1,K)while(x%val[i]==0)cnt[i][k]--,x/=val[i];sum[k]=tg[k];For(i,1,K)sum[k]=1ll*sum[k]*pw[i][cnt[i][k]]%P;return;}
	dwn(k);x<=R?upd2(ls(k),l,R,x,v):upd2(rs(k),L,r,x,v),sum[k]=(sum[ls(k)]+sum[rs(k)])%P;
}
int ask(int k,int l,int r,int x,int y){if(l>=x&&r<=y)return sum[k];dwn(k);int ans=0;x<=R&&(ans=(ans+ask(ls(k),l,R,x,y))%P),y>=L&&(ans=(ans+ask(rs(k),L,r,x,y))%P);return ans;}
int main()
{
	N=get(),P=get();int x=P;phi=P;for(int i=2;i*i<=x;i++)if(x%i==0){val[++K]=i;while(x%i==0)x/=i;phi/=i,phi*=i-1;}if(x>1)val[++K]=x,phi/=x,phi*=x-1;
	For(i,1,K){pw[i][0]=1;For(j,1,MAXN*20)pw[i][j]=1ll*pw[i][j-1]*val[i]%P;}For(i,1,N)a[i]=get();build(1,1,N);M=get();
	while(M--){int opt=get(),x=get(),y=get();opt==1?upd1(1,1,N,x,y,get()):opt==2?upd2(1,1,N,x,y):void(cout<<ask(1,1,N,x,y)<<'\n');}return 0;
}