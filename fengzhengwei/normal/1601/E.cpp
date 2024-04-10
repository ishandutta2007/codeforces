// LUOGU_RID: 91685917
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5;
struct seg
{
	vector<ll>sum,adt;
	int N;
	void ini(int len){N=len,sum.resize(len*4+5),adt.resize(len*4+5);}
	void ad(int k,int l,int r,ll z){sum[k]+=z*(r-l+1),adt[k]+=z;}
	void pd(int k,int l,int r){if(!adt[k])return;int mid=l+r>>1;ad(k<<1,l,mid,adt[k]),ad(k<<1|1,mid+1,r,adt[k]);adt[k]=0;}
	void cg(int k,int l,int r,int x,int y,int z)
	{
		if(x>y)return;
		if(x<=l&&r<=y)return ad(k,l,r,z);
		pd(k,l,r);int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,y,z);
		if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
		sum[k]=sum[k<<1]+sum[k<<1|1];
	}
	ll ask(int k,int l,int r,int x,int y)
	{
		if(x>y)return 0;
		if(x<=l&&r<=y)return sum[k];
		pd(k,l,r);int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return ask(k<<1,l,mid,x,y)+ask(k<<1|1,mid+1,r,x,y);
	}
	void cg(int x,int y,int z){return cg(1,1,N,x,y,z);}
	ll ask(int x,int y){return ask(1,1,N,x,y);}
}s[xx];
struct nod{int l,r,id;}Q[xx];
ll ans[xx];
int mn[xx<<2],a[xx],id[xx],bel[xx],siz[xx];
void build(int k,int l,int r)
{
	if(l==r)return mn[k]=a[l],void();
	int mid=l+r>>1;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
int ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mn[k];
	int mid=l+r>>1;
	if(y<=mid)return ask(k<<1,l,mid,x,y);
	if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
	return min(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
}
int n,q,k;
struct tp{int l,r,mn;};
vector<tp>stk[xx];
vector<int>I[xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)
		Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
	sort(Q+1,Q+q+1,[&](nod&A,nod&B){return A.l>B.l;});
	for(int i=1;i<=n;i++)
	{
		if(i-k<=0)id[i]=1,bel[i]=i,siz[i]++;
		else id[i]=id[i-k]+1,bel[i]=bel[i-k],siz[bel[i]]++;
		I[bel[i]].push_back(i);
	}
	build(1,1,n);
	for(int i=1;i<=n;i++)if(bel[i]==i)s[i].ini(siz[i]);
	int lp=1;
	for(int i=n;i>=1;i--)
	{
		if(i+k<=n)swap(stk[i],stk[i+k]);
		int Mn=ask(1,1,n,i,min(i+k,n)),tl=-1,tr=-1; 
		while(stk[i].size()&&stk[i].back().mn>Mn)
		{
			s[bel[i]].cg(id[stk[i].back().l],id[stk[i].back().r],-stk[i].back().mn);
			if(tl==-1)tl=stk[i].back().l,tr=stk[i].back().r;
			else tr=stk[i].back().r;
			stk[i].pop_back();
		}
		if(tl!=-1)s[bel[i]].cg(id[tl],id[tr],Mn),stk[i].push_back({tl,tr,Mn});
		stk[i].push_back({i,i,a[i]});
		s[bel[i]].cg(id[i],id[i],a[i]);
		while(lp<=q&&Q[lp].l==i)
		{
			int tid=*--upper_bound(I[bel[i]].begin(),I[bel[i]].end(),Q[lp].r);
//			cerr<<id[i]<<" "<<id[tid]<<"@@\n";
			ans[Q[lp].id]=s[bel[i]].ask(1,id[tid]);
			++lp;
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}