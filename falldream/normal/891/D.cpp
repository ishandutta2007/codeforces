#include<iostream>
#include<cstdio>
#include<vector>
#define MN 500000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,size[MN+5];vector<int> v[MN+5];long long ans=0;
struct data
{
	int s[4];
	data operator * (data b)
	{
		data c;c.s[0]=c.s[1]=c.s[2]=c.s[3]=0;int k; 
		for(int i=0;i<4;++i) for(int j=0;j<4;++j) 
			if((k=(i&1)+(j&1)+bool((i&2)&&(~j&2)))<2)
				c.s[k+2*(!((~i&2)&&(j&2)))]+=s[i]*b.s[j];
		return c.s[1]+=s[0]*b.s[0],c;
	}
	data operator + (data b)
	{
		data c;c.s[0]=c.s[1]=c.s[2]=c.s[3]=0;
		for(int i=0;i<4;++i) for(int j=0;j<4;++j)
			if((i&2)+(j&2)<4&&(i&1)+(j&1)<2)
				c.s[i+j]+=s[i]*b.s[j];
		return c;
	}
}f[MN+5],g[MN+5];
inline void ins(int f,int t){v[f].push_back(t);v[t].push_back(f);}
void Pre(int x,int fa)
{
	f[x].s[0]=1;size[x]=1;
	for(int i=0;i<v[x].size();++i) if(v[x][i]!=fa)
		Pre(v[x][i],x),size[x]+=size[v[x][i]],f[x]=f[x]*f[v[x][i]];
}
void Dfs(int x,int fa)
{
	vector<data> p;data s=(data){{1,0,0,0}};p.push_back(g[x]);
	for(int i=0;i<v[x].size();++i) if(v[x][i]!=fa)
		p.push_back(p.back()*f[v[x][i]]);
	for(int i=v[x].size(),j=p.size()-1;i--;) if(v[x][i]!=fa)
		g[v[x][i]]=(data){{1,0,0,0}}*(p[--j]+s),s=s*f[v[x][i]],Dfs(v[x][i],x);
}
int main()
{
	n=read();if(n&1) return 0*puts("0");
	for(int i=1;i<n;++i) ins(read(),read());
	Pre(1,0);g[1].s[0]=1;Dfs(1,0);
	for(int i=2;i<=n;++i)
		if(g[i].s[0]&&f[i].s[2]) ans+=1LL*size[i]*(n-size[i]);
		else ans+=1LL*g[i].s[1]*(f[i].s[3]+f[i].s[0]);
	printf("%lld\n",ans);
	return 0;
}