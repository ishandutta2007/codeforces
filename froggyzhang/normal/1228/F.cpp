#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int P,n,rt1,rt2,maxp[N],siz[N];
vector<int> G[N];
void get_root(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		get_root(v,u);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);	
	}
	maxp[u]=max(maxp[u],n-siz[u]);
	if(!rt1||maxp[u]<maxp[rt1])rt1=u,rt2=0;
	else if(maxp[u]==maxp[rt1])rt2=u;
}
bool check(int rt,int X){
	if(!rt)return false;
	function<bool(int,int)> dfs = [&](int u,int fa) -> bool{
		siz[u]=1;
		vector<int> V;
		for(auto v:G[u]){
			if(v==fa)continue;
			if(!dfs(v,u))return false;
			siz[u]+=siz[v];
			V.push_back(siz[v]);
		}
		sort(V.begin(),V.end());
		if(V.empty())return true;
		if((V.size()==1||V.size()==3)&&u^X)return false;
		if(V.size()==1||V.size()==3)++siz[u];
		if(V.size()==1)return V[0]==1;
		if(V.size()==2)return V[0]==V[1];
		if(V.size()==3)return V[0]+V[1]+1==V[2]&&V[0]==V[1];
		return false;
	};
	return dfs(rt,0);
}
int main(){
	P=read();
	if(P==2){
		printf("2\n1 2\n");
		return 0;
	}
	n=(1<<P)-2;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	get_root(1,0);
	vector<int> ans;
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(G[i].size()==2||G[i].size()==4||((i==rt1||i==rt2)&&G[i].size()==3)){
			++cnt;
			if(cnt>6){
				puts("0");return 0;
			}
			if(check(rt1,i)||check(rt2,i))ans.push_back(i);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	return 0;
}