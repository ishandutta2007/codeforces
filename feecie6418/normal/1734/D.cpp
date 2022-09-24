#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
typedef pair<ll,ll> pr;
int n,K;
ll a[200005],b[200005];
vector<int> g[200005];
struct Heap{
	ll tag;
	priority_queue<pr,vector<pr>,greater<pr>> q;
	void push(pr x){x.first-=tag,q.push(x);}
	void pop(){assert(q.size());q.pop();}
	pr top(){assert(q.size());pr x=q.top();x.first+=tag;return x;}
	void add(ll x){tag+=x;}
	int size(){return q.size();}
	void print(){
		auto qq=q;
		while(qq.size()){
			auto x=qq.top();
			qq.pop();
			cout<<x.first+tag<<' '<<x.second<<'\n';
		}
	}
}q[200005];
void dfs(int x){
	for(int y:g[x]){
		dfs(y);
		if(q[x].size()<q[y].size())swap(q[x],q[y]);
		while(q[y].size())q[x].push(q[y].top()),q[y].pop();
	}
	if(a[x]-b[x]>0){
		ll s=a[x];
		while(q[x].size()&&q[x].top().first<=s)s+=q[x].top().second,q[x].pop();
		//q[x].add(b[x]-a[x]);
		q[x].push(pr(b[x],s-b[x]));
	}
	else {
		ll cur=a[x],nd=b[x];
		while(q[x].size()){
			pr w=q[x].top();
			if(cur<w.first){
				if(cur>nd)break;
				nd+=w.first-cur,cur=w.first+w.second;
				q[x].pop();
			}
			else cur+=w.second,q[x].pop();
		}
		//q[x].add(b[x]-a[x]);
		if(cur>nd)q[x].push(pr(nd,cur-nd));
	}
}
void Solve(){
	scanf("%d%d",&n,&K),a[0]=a[n+1]=inf;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int rt=n+2;
	for(int i=0;i<=n+1;i++){
		int fa;
		if(i==K)fa=rt;
		else if(i<K)fa=i+1;
		else fa=i-1;
		g[fa].push_back(i);
		if(a[i]<0)b[i]=-a[i],a[i]=0;
	}
	dfs(rt);
	ll cur=0,nd=0;
	while(cur<inf/2){
		pr x=q[rt].top();
		q[rt].pop();
		if(cur>=x.first)cur+=x.second;
		else nd+=x.first-cur,cur=x.first+x.second;
	}
	if(nd==0)puts("Yes");
	else puts("No");
	for(int i=0;i<=n+2;i++){
		a[i]=0,b[i]=0,g[i].clear();
		while(q[i].size())q[i].pop();
		q[i].tag=0;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}