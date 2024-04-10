#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
typedef unsigned long long ull;
int n,m,a[1005],b[1005],p1[1005],p2[1005],X[1005],Y[1005];
namespace BHZT{

const ll inf=1e18;
int n,m,tot,h[1005],cnt=1,S,T,dis[1005],gap[1005],vst[1005];
struct Edge{
	int to,nxt;
	ll flow;
}e[10005];
void Add(int x,int y,ll z){
	e[++cnt]={y,h[x],z},h[x]=cnt,e[++cnt]={x,h[y],0},h[y]=cnt;
}
ll DFS(int x,ll maxf,int s,int t){
	if(x==t)return maxf;
	ll ret=0;
	for(int i=h[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!e[i].flow||dis[y]+1!=dis[x])continue;
		ll dlt=DFS(y,min(maxf,e[i].flow),s,t);
		e[i].flow-=dlt,e[i^1].flow+=dlt,maxf-=dlt,ret+=dlt;
		if(dis[s]==tot||!maxf)return ret;
	}
	if(!(--gap[dis[x]]))dis[s]=tot;
	else gap[++dis[x]]++;
	return ret;
}
void dfs(int x){
	if(vst[x])return ;
	vst[x]=1;
	for(int i=h[x];i;i=e[i].nxt)if(e[i].flow)dfs(e[i].to);
}
set<int> Solve(int nn,vector<int> E,vector<pair<int,ll> > A){
	n=nn,tot=n+2,cnt=1,S=n+1,T=n+2;
	for(int i:E)Add(X[i],Y[i],inf);
	for(auto i:A)if(i.second>0)Add(i.first,T,i.second);else Add(S,i.first,-i.second);
	gap[0]=tot;
	while(dis[S]<tot)DFS(S,inf,S,T);
	dfs(S);
	set<int> w;
	for(auto i:A)if(vst[i.first])w.insert(i.first);
	A.push_back(make_pair(S,0ll)),A.push_back(make_pair(T,0ll));
	int mx=0;
	for(auto i:A)mx=max(mx,dis[i.first]);
	for(int i=0;i<=mx;i++)gap[i]=0;
	for(auto i:A)h[i.first]=vst[i.first]=dis[i.first]=0;
	return w;
}

}
void Solve(vector<int> P,vector<int> Q,int l,int r){
	if(!P.size())return ;
	if(l==r){
		for(int i:P)b[i]=l;
		return ;
	}
	int mid=(l+r)/2;
	vector<pair<int,ll> > A;
	for(int i:P)A.push_back(make_pair(i,abs(a[i]-mid-1)-abs(a[i]-mid)));
	set<int> s=BHZT::Solve(n,Q,A);
	vector<int> pp[2],qq[2];
	for(int i:P)pp[s.count(i)].push_back(i);
	for(int i:Q)if(s.count(X[i])==s.count(Y[i]))qq[s.count(X[i])].push_back(i);
	Solve(pp[0],qq[0],l,mid),Solve(pp[1],qq[1],mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&X[i],&Y[i]);
	vector<int> P,Q;
	for(int i=1;i<=n;i++)P.push_back(i);
	for(int i=1;i<=m;i++)Q.push_back(i);
	Solve(P,Q,0,1e9);
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
}