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
int n,m,q;
const int xx=2e5+5; 
int to[xx][22],now[xx],val[xx],a[xx],nxt[xx];//avalnxttoi2^j 
vector<pair<int,int> >v[xx];//id,r
int ans[xx];
int main(){
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)nxt[val[i]]=val[i+1]; 
	nxt[val[n]]=val[1];
	for(int i=1;i<=m;i++)a[i]=read();
	for(int i=1;i<=n;i++)now[i]=m+1;
	for(int j=0;j<=20;j++)to[m+1][j]=m+1;
	for(int i=m;i>=1;i--)
	{
		to[i][0]=now[nxt[a[i]]];
		now[a[i]]=i;
	}
	for(int j=1;j<=20;j++)
		for(int i=1;i<=m;i++)to[i][j]=to[to[i][j-1]][j-1];
//	return 0;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		l=read();r=read();
		v[l].push_back(make_pair(i,r));
	}
	int mn=2147483647;
	for(int i=m;i>=1;i--)
	{
		int o=i;
		for(int j=20;j>=0;j--)if((n-1)>>j&1)o=to[o][j];
		mn=min(mn,o);
		for(int j=0;j<v[i].size();j++)ans[v[i][j].first]=(mn<=m)*(mn<=v[i][j].second);
	}
	for(int i=1;i<=q;i++)cout<<ans[i];
	puts("");
	return 0;
}