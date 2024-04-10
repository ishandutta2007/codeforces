#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
#define IT  multiset<int> :: iterator 
using namespace std;
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int n;
string s[200001];
int son[200001][26],tot,l[200001],dep[200001],rk[200001],v[200001],to[200001];
ll ans;
vector<int> vec[2000001];
inline void Insert(string s,int x)
{
	int len=s.length();
	int now=0;
	For(i,0,len-1)
	{
		if(!son[now][s[i]-'a']) son[now][s[i]-'a']=++tot;
		dep[son[now][s[i]-'a']]=dep[now]+1;now=son[now][s[i]-'a'];
	}
	to[now]=x;
}
int vis[200001]; 
multiset<int> hav[200001];
inline void Dfs(int x)
{
	// cout<<x<<' '<<to[x]<<endl;
	if(to[x])   hav[x].insert(dep[x]),ans+=dep[x];
	For(c,0,25)
	{
		if(!son[x][c])	continue;
		Dfs(son[x][c]);
		IT it=hav[son[x][c]].begin();
		while(1)
		{
			it++;
			if(*it==1e9)    break;
			hav[x].insert(*it);
		}
	}
	IT it=hav[x].end();it--;it--;
	if(*it!=-1e9&&x&&!to[x])
	{
		ans-=*it;ans+=dep[x];
		hav[x].insert(dep[x]);
		hav[x].erase(it);
	}
}
inline bool cmp(int x,int y){return v[l[x]]>v[l[y]];}
int main()
{
	n=read();
	For(i,1,n)
	{
		cin>>s[i];
		Insert(s[i],i);
	}
	For(i,1,tot)    hav[i].insert(-1e9),hav[i].insert(1e9);
	Dfs(0);
	writeln(ans);
}