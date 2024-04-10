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
const int xx=2e5+5;
int n,a[xx],stk[xx],tot,l[xx],r[xx],t[xx],size[xx],son[xx],id,ans;
void dfs(int x)
{
	size[x]=1;
	if(l[x])dfs(l[x]),size[x]+=size[l[x]];
	if(r[x])dfs(r[x]),size[x]+=size[r[x]];
	if(size[l[x]]>size[r[x]])son[x]=l[x];
	else son[x]=r[x];
}
void clear(int x)
{
	t[a[x]]=0;
	if(l[x])clear(l[x]);
	if(r[x])clear(r[x]);
}
void get(int x)
{
	ans+=t[id-a[x]];
//	cout<<x<<" "<<id<<" "<<a[x]<<" "<<ans<<"\n";
	if(l[x])get(l[x]);
	if(r[x])get(r[x]);
}
void ad(int x)
{
	t[a[x]]=1;
	if(l[x])ad(l[x]);
	if(r[x])ad(r[x]);
}
void Dfs(int x)
{
	if(!son[x])return t[a[x]]=1,void();
	if(l[x]&&l[x]!=son[x])Dfs(l[x]),clear(l[x]);
	if(r[x]&&r[x]!=son[x])Dfs(r[x]),clear(r[x]);
	Dfs(son[x]);
	t[a[x]]=1;id=a[x];
	if(l[x]&&l[x]!=son[x])get(l[x]),ad(l[x]);
//	cout<<x<<" "<<l[x]<<" sas "<<r[x]<<"\n";
	if(r[x]&&r[x]!=son[x])get(r[x]),ad(r[x]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	stk[tot=1]=0;
	a[0]=11111140;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=a[stk[tot]])r[stk[tot]]=i;
		else 
		{
			int last=0;
			while(a[i]>a[stk[tot]])last=stk[tot--];
			r[stk[tot]]=i;
			l[i]=last;
		}
		stk[++tot]=i;
	}
	dfs(r[0]);
	Dfs(r[0]);
	cout<<ans<<'\n';
	return 0;
}