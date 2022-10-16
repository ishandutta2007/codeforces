#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long 
#define dd double
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
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5,B=1805;
int n,m,re[xx],bel[xx],L[xx],R[xx];
int ans[xx],cr[xx];
//vector<pair<int,int> >qu[xx/B+5];
vector<int>qu[xx/B+5][xx];
//id 
namespace trie
{
	struct nod{int to[2],sz;}e[xx*32];
	int cst,sum,rt;
	// 
	void cls(){cst=sum=rt=0;}
	void ins(int &k,int d,int x)
	{
		if(!k)k=++cst,e[k].sz=0,e[k].to[0]=e[k].to[1]=0;
		e[k].sz++;if(d==18)return;
		ins(e[k].to[x>>d&1],d+1,x);
	}
	void in(int x){/*cerr<<x<<" s "<<sum<<"!!\n",*/sum^=x,ins(rt,0,x);}
	void add(int &k,int d)
	{
		if(!k)return;
		if(d==18)return;
		if(e[e[k].to[0]].sz&1)sum^=(1<<d);
		if(e[e[k].to[1]].sz&1)sum^=(1<<d);
		swap(e[k].to[0],e[k].to[1]);
		add(e[k].to[0],d+1);
	}
	void A(){add(rt,0);}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)re[read()]^=1;
	for(int i=1;i<=m;i++)bel[i]=(i-1)/B+1,(!L[bel[i]]?L[bel[i]]=i:0),R[bel[i]]=i;
//	for(int i=1;i<=m;i++)cout<<L[i]<<" "<<R[i]<<"!!\n";
	int q=read();
	for(int I=1;I<=q;I++)
	{
		int l=read(),r=read();
		if(bel[l]==bel[r]||bel[l]+1==bel[r])
		{
			for(int i=l;i<=r;i++)ans[I]^=re[i]?(i-l):0;
			continue;
		}
		int to=R[bel[l]];
		for(int i=l;i<=to;i++)ans[I]^=re[i]?(i-l):0;
		to=L[bel[r]];
		for(int i=to;i<=r;i++)ans[I]^=re[i]?(i-l):0;
//		cerr<<bel[l]<<" "<<bel[r]<<"!!\n";
		for(int i=bel[l]+1;i<=bel[r]-1;i++)qu[i][l].push_back(I),cr[i]=1;
	}
	for(int i=1;i<=bel[m];i++)
	{
		if(!cr[i])continue;
//		cerr<<i<<" ss "<<"\n";
		trie::cls();
//		for(int j=L[i];j<=R[i];j++)cerr<<j<<"!@AD\n";
		for(int j=L[i];j<=R[i];j++)if(re[j])trie::in(j-L[i]);
//		,cerr<<j<<"ASD\n";
		for(int j=L[i];j>=1;j--)
		{
			for(auto it:qu[i][j])ans[it]^=trie::sum;
			if(j!=1)trie::A();
		}
		//sort 
//		sort(qu[i].begin(),qu[i].end());
	}
	for(int i=1;i<=q;i++)if(ans[i])cout<<"A";else cout<<"B";
	pc('1',1);
	return 0;
}