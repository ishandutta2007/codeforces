#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,q;
const int xx=1e6+5;
int a[xx];
struct nod{int l,r,id;}e[xx];
bool cmp1(nod a,nod b){return a.l<b.l;}
bool cmp2(nod a,nod b){return a.r<b.r;}
int mx[xx],mn[xx],l[xx],r[xx],stk[xx],top;
int lb(int x){return x&-x;}
struct szsz
{
	ll sum[xx];
	void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
	void clear(){memset(sum,0,sizeof(sum));}
	ll ask(int l,int r){return ask(r)-ask(l-1);}
}s1,s2;
basic_string<int>mxid[xx];
basic_string<int>mnid[xx];
void dfs(int x)
{
	mx[x]=mn[x]=x;
	if(l[x])dfs(l[x]),mx[x]=max(mx[x],mx[l[x]]),mn[x]=min(mn[x],mn[l[x]]);
	if(r[x])dfs(r[x]),mx[x]=max(mx[x],mx[r[x]]),mn[x]=min(mn[x],mn[r[x]]);
	//r-(l-1)
	if(x)mxid[mx[x]].push_back(x);
	if(x)mnid[mn[x]-1].push_back(x);
}
ll ans[xx];
signed main(){
	n=read();
	q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)e[i].l=read(),e[i].id=i;
	for(int i=1;i<=q;i++)e[i].r=read();
	stk[++top]=0;
	a[0]=1e9;
	for(int i=1;i<=n;i++)//big root heap
	{
		if(a[i]<a[stk[top]])r[stk[top]]=i;
		else 
		{
			int last=0;
			while(a[i]>a[stk[top]])last=stk[top--];
			r[stk[top]]=i;
			l[i]=last;
		}
		stk[++top]=i;
	}
	dfs(0);
	sort(e+1,e+q+1,cmp2);//r 
	for(int i=1;i<=n;i++)s1.add(i,mx[i]);
	int tt=n;
//		cout<<s1.ask(e[2].l,e[2].r)<<"\n";
	for(int i=q;i>=1;i--)
	{
		while(tt>=0&&tt>=e[i].r)
		{
			for(int j=0;j<mxid[tt].size();j++)
			{
				int x=mxid[tt][j];
				s1.add(x,-mx[x]);
				s2.add(x,1);
			}
			tt--;
		}
		ans[e[i].id]=s1.ask(e[i].l,e[i].r)+s2.ask(e[i].l,e[i].r)*e[i].r;
//	cout<<ans[1]<<" "<<ans[2]<<" "<<s1.ask(e[i].l,e[i].r)<<"\n";
	}
	s1.clear();
	s2.clear();
	for(int i=1;i<=n;i++)mn[i]--,s1.add(i,mn[i]);
	sort(e+1,e+q+1,cmp1);//l 
	tt=0;
	for(int i=1;i<=q;i++)
	{
//		cout<<e[i].id<<"\n";
		while(tt<=n&&tt<=e[i].l-1)
		{
			for(int j=0;j<mnid[tt].size();j++)
			{
//	puts("qweqe");
				int x=mnid[tt][j];
				s1.add(x,-mn[x]);
				s2.add(x,1);
			}
			tt++;
		}
		ans[e[i].id]-=(s1.ask(e[i].l,e[i].r)+s2.ask(e[i].l,e[i].r)*(e[i].l-1));
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<" \n"[i==q];
	return 0;
}