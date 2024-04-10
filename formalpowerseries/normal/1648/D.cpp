/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL n,q,a[4][500005],sum1[500005],sum2[500005],sum3[500005];
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define Mm LL mid=(l+r)>>1
LL tr[2000005],tag[2000005],maxn[2000005];
void build(LL l,LL r,LL now)
{
	tr[now]=-1e18,tag[now]=1e18;
	if(l==r)	return void(maxn[now]=sum1[l]+sum2[l]);
	Mm;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
	maxn[now]=max(maxn[lc(now)],maxn[rc(now)]);
}
inline void push_down(LL now){if(tag[now]!=1e18)	tr[rc(now)]=max(tr[rc(now)],maxn[lc(now)]-tag[now]),tag[lc(now)]=min(tag[lc(now)],tag[now]),tag[rc(now)]=min(tag[rc(now)],tag[now]);}
void modify(LL l,LL r,LL now,LL x,LL y,LL v)
{
	if(x<=l && r<=y)
	{
		tr[now]=max(tr[now],v);
		return ;
	}
	push_down(now);
	Mm;
	if(x<=mid)	modify(l,mid,lc(now),x,y,v);
	if(mid<y)	modify(mid+1,r,rc(now),x,y,v);
}
void modify(LL l,LL r,LL now,LL x,LL y,LL k,LL &mxn)
{
	if(x<=l && r<=y)
	{
		tr[now]=max(tr[now],mxn-k);
		tag[now]=min(tag[now],k);
		mxn=max(mxn,maxn[now]);
		return ;
	}
	push_down(now);
	Mm;
	if(x<=mid)	modify(l,mid,lc(now),x,y,k,mxn);
	if(mid<y)	modify(mid+1,r,rc(now),x,y,k,mxn);
}
LL query(LL l,LL r,LL now,LL x)
{
	if(l==r)	return max(tr[now],maxn[now]-tag[now]);
	push_down(now);
	Mm,ret=tr[now];
	if(x<=mid)	ret=max(query(l,mid,lc(now),x),ret);
	else	ret=max(query(mid+1,r,rc(now),x),ret);
	return ret;
}
#undef lc
#undef rc
#undef Mm
vector<pair<LL,LL>> G[500005];
#define mp make_pair
LL dp[500005];
int main(){
	n=read(),q=read();
	for(LL i=1;i<=3;++i)	for(LL j=1;j<=n;++j)	a[i][j]=read();
	#define A a[1]
	#define B a[2]
	#define C a[3]
	for(LL i=1;i<=n;++i)	sum1[i]=sum1[i-1]+A[i];
	for(LL i=n;i;--i)	sum2[i]=sum2[i+1]+B[i];
	for(LL i=n;i;--i)	sum3[i]=sum3[i+1]+C[i];
	#undef A
	#undef B
	#undef C
	build(1,n,1);
	for(LL i=1;i<=q;++i)
	{
		LL l=read(),r=read(),k=read();
		G[l].push_back(mp(r,k));
	}
	dp[0]=-1e18;
	LL L=0,ans=-1e18;
	for(LL i=1;i<=n;++i)
	{
		while(L<i-1)	++L,dp[L]=query(1,n,1,L)-sum2[L+1],ans=max(ans,dp[L]+sum3[L]);
		for(auto st:G[i])
		{
			LL r=st.first,w=st.second;
			modify(1,n,1,i,r,dp[i-1]+sum2[i]-w);
			LL mxn=-1e18;
			modify(1,n,1,i,r,w,mxn);
		}
	}
	while(L<=n-1)	++L,dp[L]=query(1,n,1,L)-sum2[L+1],ans=max(ans,dp[L]+sum3[L]);
	write(ans);
	return 0;
}