#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 150001
int N,P,M,K,B,a[MAXN],b[MAXN],cnt[MAXN],p[MAXN],*f=p+70000,sum[MAXN],pre[MAXN],tg[MAXN],ans[MAXN];struct que{int l,r,id;}q[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void pt(int k,int v){int sum1=(1ll*sum[k]*f[v+1]+1ll*pre[k]*f[v])%P,pre1=(1ll*sum[k]*f[v]+1ll*pre[k]*f[v-1])%P;tg[k]+=v,sum[k]=sum1,pre[k]=pre1;}
void dwn(int k){pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void insert(int k,int l,int r,int x){if(l==r){sum[k]=1ll*b[x]*f[tg[k]+1]%P;pre[k]=1ll*b[x]*f[tg[k]]%P;return;}if(tg[k])dwn(k);x<=R?insert(ls(k),l,R,x),pt(rs(k),1):insert(rs(k),L,r,x);sum[k]=(sum[ls(k)]+sum[rs(k)])%P,pre[k]=(pre[ls(k)]+pre[rs(k)])%P;}
void erase(int k,int l,int r,int x){if(l==r){sum[k]=pre[k]=0;return;}if(tg[k])dwn(k);x<=R?erase(ls(k),l,R,x),pt(rs(k),-1):erase(rs(k),L,r,x);sum[k]=(sum[ls(k)]+sum[rs(k)])%P,pre[k]=(pre[ls(k)]+pre[rs(k)])%P;}
int main()
{
	N=get(),P=get();For(i,1,N)a[i]=get();f[1]=f[2]=1;For(i,3,N+100)f[i]=(f[i-1]+f[i-2])%P;FOR(i,0,-N-100)f[i]=(f[i+2]-f[i+1]+P)%P;
	M=get();B=250;For(i,1,M)q[i].l=get(),q[i].r=get(),q[i].id=i;sort(q+1,q+M+1,[&](const que&a,const que&b){return a.l/B<b.l/B||a.l/B==b.l/B&&a.r<b.r;});
	For(i,1,N)b[i]=a[i];sort(b+1,b+N+1);K=unique(b+1,b+N+1)-b-1;For(i,1,N)a[i]=lower_bound(b+1,b+K+1,a[i])-b;int l=1,r=0;
	For(i,1,M)
	{
		while(r<q[i].r){cnt[a[++r]]++;if(cnt[a[r]]==1)insert(1,1,K,a[r]);}
		while(l>q[i].l){cnt[a[--l]]++;if(cnt[a[l]]==1)insert(1,1,K,a[l]);}
		while(r>q[i].r){if(cnt[a[r]]==1)erase(1,1,K,a[r]);cnt[a[r--]]--;}
		while(l<q[i].l){if(cnt[a[l]]==1)erase(1,1,K,a[l]);cnt[a[l++]]--;}
		ans[q[i].id]=sum[1];
	}
	For(i,1,M)cout<<ans[i]<<'\n';return 0;
}