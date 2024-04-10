#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int O=6e5;
int n,m,N,dfn[O+5],low[O+5],sign,fa[O+5],st[O+5],top;
vector<int> g[O+5],ve[O+5];
vector<vector<int>> orders[O+5];
vector<pr> ed[O+5];
void Tarjan(int x){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(int y:g[x]){
		if(!dfn[y]){
			Tarjan(y),low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				int t;
				++N,ve[N].push_back(x),fa[N]=x;
				do t=st[top--],fa[t]=N,ve[N].push_back(t); while(t!=y);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
struct Thing{
	int at,id,val;
};
bool operator <(const Thing &x,const Thing &y){
	return x.val>y.val;
}
vector<int> Merge(vector<vector<int>> a){
	priority_queue<Thing> q;
	vector<int> res;
	for(int i=0;i<a.size();i++)if(a[i].size())q.push({i,0,a[i][0]});
	while(!q.empty()){
		Thing x=q.top();
		q.pop(),res.push_back(x.val);
		if(x.id+1<a[x.at].size())q.push({x.at,x.id+1,a[x.at][x.id+1]});
	}
	return res;
}
struct Oper{
	int x,y,z;
}op[O+5];
int co,L[O+5],R[O+5],inq[O+5],tmp[O+5],at[O+5],S,P;
set<int> e1[O+5];
vector<int> E[O+5];
bool cmp(int x,int y){
	x=(at[x]-P+S+S-1)%S+1;
	y=(at[y]-P+S+S-1)%S+1;
	return x<y;
}
bool Solve(int id){
	//cout<<"Solve:"<<id<<'\n';
	for(pr i:ed[id]){
		int x=i.first,y=i.second;
		//printf("edge:(%d,%d)\n",x,y);
		e1[x].insert(y),e1[y].insert(x),E[x].push_back(y),E[y].push_back(x);
	}
	//for(int i:ve[id])cout<<"ver:"<<i<<'\n';
	co=0;
	queue<int> q;
	for(int i:ve[id])if(e1[i].size()<=2)q.push(i),inq[i]=1;
	int X=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(!e1[x].size())X=x;//,cout<<"X:"<<x<<'\n';
		else if(e1[x].size()==1){
			int y=*e1[x].begin();
			e1[x].erase(y),e1[y].erase(x),op[++co]={y,x,y};
			if(!inq[y]&&e1[y].size()<=2)q.push(y),inq[y]=1;
		}
		else {
			int y=*e1[x].begin(),z=*--e1[x].end();
			e1[x].erase(y),e1[y].erase(x);
			e1[x].erase(z),e1[z].erase(x);
			e1[y].insert(z),e1[z].insert(y),op[++co]={y,x,z};
			if(!inq[y]&&e1[y].size()<=2)q.push(y),inq[y]=1;
			if(!inq[z]&&e1[z].size()<=2)q.push(z),inq[z]=1;
		}
		//cout<<"Del:"<<x<<'\n';
	}
	if(co+1!=ve[id].size())return 0;
	L[X]=R[X]=X;
	for(int i=co;i>=1;i--){
		int x=op[i].x,y=op[i].y,z=op[i].z;
		//printf("Adding:%d %d %d\n",x,y,z);
		if(L[x]!=z&&L[z]!=x)return 0;
		if(L[z]!=x)swap(x,z);
		L[y]=x,R[y]=z,L[z]=y,R[x]=y;
	}
	int p=*min_element(ve[id].begin(),ve[id].end()),ts=0;
	if(L[p]<R[p]){
		int x=p;
		tmp[++ts]=x;
		while(L[x]!=p)x=L[x],tmp[++ts]=x;
	}
	else {
		int x=p;
		tmp[++ts]=x;
		while(R[x]!=p)x=R[x],tmp[++ts]=x;
	}
	S=ts;
	for(int i=1;i<=ts;i++)at[tmp[i]]=i;
	for(int i=1;i<=ts;i++){
		int x=tmp[i];
		P=i,sort(E[x].begin(),E[x].end(),cmp);
		orders[x].push_back(E[x]);
	}
	for(int i:ve[id])E[i].clear(),L[i]=R[i]=inq[i]=0,e1[i].clear();
	return 1;
}
void Solve(){
	scanf("%d%d",&n,&m),N=n;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),x++,y++,g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++){
		for(int j:g[i])
			if(j>i){
				int x=i,y=j;
				if(fa[x]==fa[y]||fa[fa[x]]==y)ed[fa[x]].push_back(pr(x,y));
				else ed[fa[y]].push_back(pr(x,y));
			}
	}
	bool ok=1;
	for(int i=n+1;i<=N;i++){
		if(!Solve(i)){
			ok=0;
			break;
		}
	}
	if(!ok)puts("NO");
	else {
		puts("YES");
		for(int i=1;i<=n;i++){
			vector<int> res=Merge(orders[i]);
			for(int j:res)cout<<j-1<<' ';
			puts("");
		}
	}
	for(int i=1;i<=N;i++){
		dfn[i]=low[i]=fa[i]=st[i]=0;
		g[i].clear(),ve[i].clear(),orders[i].clear(),ed[i].clear();
		L[i]=R[i]=inq[i]=tmp[i]=at[i]=0,e1[i].clear(),E[i].clear();
	}
	sign=top=0;
	// 
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}