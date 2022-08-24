#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int n;
double p[100001],q[100001],sum[100001];
int par[100001];
vector<int>adj[100001];
int d[100001];
bool vis[100001];
void dfs(int id){
	vis[id]=true;
	for(auto cur:adj[id]){
		if(vis[cur]) continue;
		par[cur]=id;
		d[id]++;
		dfs(cur);
	}
}
double ans=1;
void in(int& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
void in(double& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
	int y=0;
	c=getchar();
	while(c>=48 && c<=57){
		y=y*10+c-48;
		c=getchar();
	}
	x+=y*0.01;
}
int main(){
	ios::sync_with_stdio(false);
	in(n);
	for(int i=1; i<=n ;i++) in(q[i]);
	p[0]=1;
	for(int i=1; i<n ;i++){
		int u,v;
		in(u);in(v);
		u++;v++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	for(int i=1; i<=n ;i++){
		sum[par[i]]+=q[i];
		ans-=q[i]*(p[par[i]]-d[i]+sum[i]);
		p[i]=q[i];
	}
	int q;
	in(q);
	for(int i=1; i<=q ;i++){
		int pos;
		double r,s;
		in(pos);in(r);
		pos++;
		s=r-p[pos];
		sum[par[pos]]+=s;
		ans-=s*(p[par[pos]]-d[pos]+sum[pos]);
		p[pos]=r;
		printf("%.5lf\n",ans);
	}
}