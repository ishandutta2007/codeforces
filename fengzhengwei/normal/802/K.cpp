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
int n;
int f[100005][2];//01 
struct nod
{
	int t,v;
	bool operator<(const nod&w)const
	{
		return f[t][0]+v>f[w.t][0]+w.v;
	}
};
vector<nod>v[100005];
void add(int x,int y,int z)
{
	v[x].push_back((nod){y,z});
}
void wdd(int x,int y)
{
	x++;
	y++;
	int o=read();
	add(x,y,o);
	add(y,x,o);
}
int vis[100005];
int k;
void dfs(int x,int y)
{
	for(int i=0;i<v[x].size();++i)
	{
		if(y==v[x][i].t)
		{
			v[x].erase(v[x].begin()+i);
			i--;
			continue;
		}
		dfs(v[x][i].t,x);
	}
//	cout<<x<<" "<<v[x].size()<<endl;
	sort(v[x].begin(),v[x].end());int maxx=0;
	for(int i=0;i<min(int(v[x].size()),k-1);i++)maxx+=f[v[x][i].t][0]+v[x][i].v,vis[v[x][i].t]=1;
	f[x][0]=maxx;
	for(int i=0;i<v[x].size();i++)
	{
		int w=0;
		if(v[x].size()>k-1)
		w=f[v[x][k-1].t][0]+v[x][k-1].v;
		if(vis[v[x][i].t])
		f[x][1]=max(f[x][1],maxx-f[v[x][i].t][0]+w+f[v[x][i].t][1]);
		else 
		{
			f[x][1]=max(f[x][1],maxx+f[v[x][i].t][1]+v[x][i].v);
		}
	}
}
int main(){
	n=read();
	k=read();
	for(int i=2;i<=n;i++)wdd(read(),read());
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<endl;
	return 0;
}