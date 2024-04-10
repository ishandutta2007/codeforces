#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
struct Edge{
	int to,id;
};
int n,iso[200005],ok,ind[200005],X[200005],Y[200005];
vector<Edge> g[200005];
vector<int> G[200005];
void Add(int x,int y){
	G[x].push_back(y),ind[y]++;
}
void dfs(int x,int fi){
	vector<int> c[2];
	for(Edge i:g[x]){
		int y=i.to;
		if(i.id==fi)continue;
		dfs(y,i.id);
		c[iso[y]].push_back(i.id);
	}
	int w=c[1].size()-c[0].size();
	if(x==1)ok&=w>=0&&w<=1;
	else {
		if(w<(int)g[x].size()%2)iso[x]=1;
		else iso[x]=0;
		c[iso[x]].push_back(fi);
		w=c[1].size()-c[0].size();
		ok&=w>=0&&w<=1;
	}
	if(!ok)return ;
	if(g[x].size()&1){
		for(int i=0;i<c[0].size();i++){
			Add(c[1][i],c[0][i]);
			Add(c[0][i],c[1][i+1]);
		}
	}
	else {
		int p=0,q=1;
		for(int i=0;i+1<c[p].size();i++){
			Add(c[p][i],c[q][i]);
			Add(c[q][i],c[p][i+1]);
		}
		if(c[p].size())Add(c[p].back(),c[q].back());
	}
}
void Solve(){
	for(int i=1;i<=n;i++){
		g[i].clear(),G[i].clear();
		ind[i]=0;
	}
	cin>>n,ok=1;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back({y,i});
		g[y].push_back({x,i});
		X[i]=x,Y[i]=y;
	}
	dfs(1,0);
	if(!ok)return puts("NO"),void();
	puts("YES");
	queue<int> q;
	for(int i=1;i<n;i++)if(!ind[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<X[x]<<' '<<Y[x]<<'\n';
		for(int y:G[x]){
			if(!--ind[y])q.push(y);
		}
	}
}
int main(){
    int t;
	cin>>t;
	while(t--)Solve();
}