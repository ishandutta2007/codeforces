#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
struct pr{
	ll first,second,id;
}a[10000005];
struct Dist{
	ll id1,id2,dif;
};
int tot;
char del[10000005];
bool operator <(const pr &x,const pr &y){
	return x.first!=y.first?x.first<y.first:(x.second!=y.second?x.second<y.second:x.id<y.id);
}
bool operator <(const Dist &x,const Dist &y){
	return x.dif!=y.dif?x.dif>y.dif:(x.id1!=y.id1?x.id1>y.id1:x.id2>y.id2);
}
struct Edge{
	int to,val;
};
int n,m;
vector<Edge> g[100005];
int AAA=0;
struct Set{
 
ll tag;
set<pr> spos,sneg;
priority_queue<Dist> tq;
void insert(pr x){
	if(x.second>0){
		ll t=x.first+tag;
		auto it=spos.lower_bound({t,-inf,0});
		if(it==spos.end()||it->first>t){
			x.id=++tot;
			a[tot]={t,x.second,x.id};
			spos.insert(a[tot]);
			auto it2=sneg.upper_bound({x.first-tag,-inf,0});
			if(it2!=sneg.begin()){
				--it2;
				tq.push({it2->id,x.id,t-it2->first});
			}
		}
		else {
			auto w=*it;
			spos.erase(w);
			w.second+=x.second,a[w.id]=w;
			spos.insert(w);
		}
	}
	else {
		ll t=x.first-tag;
		auto it=sneg.lower_bound({t,-inf,0});
		if(it==sneg.end()||it->first>t){
			x.id=++tot;
			a[tot]={t,x.second,x.id};
			sneg.insert(a[tot]);
			auto it2=spos.lower_bound({x.first+tag,-inf,0});
			if(it2!=spos.end()){
				tq.push({x.id,it2->id,it2->first-t});
			}
		}
		else {
			auto w=*it;
			sneg.erase(w);
			w.second+=x.second,a[w.id]=w;
			sneg.insert(w);
		}
	}
}
void extend(ll x){
	while(tq.size()&&tq.top().dif<=2*(tag+x)){
		auto w=tq.top();
		tq.pop();
		if(del[w.id1]||del[w.id2])continue;
		sneg.erase(a[w.id1]);
		spos.erase(a[w.id2]);
		ll v=a[w.id1].second+a[w.id2].second;
		//if(v==0){
		//	del[w.id1]=del[w.id2]=1;
		//}
		if(v>=0){
			a[w.id2].second=v;
			spos.insert(a[w.id2]);
			auto it2=sneg.upper_bound({a[w.id2].first-2*tag,-inf,0});
			if(it2!=sneg.begin()){
				--it2;
				tq.push({it2->id,w.id2,a[w.id2].first-it2->first});
			}
			del[w.id1]=1;
		}
		if(v<0){
			a[w.id1].second=v;
			sneg.insert(a[w.id1]);
			auto it2=spos.lower_bound({a[w.id1].first+2*tag,-inf,0});
			if(it2!=spos.end()){
				tq.push({w.id1,it2->id,it2->first-a[w.id1].first});
			}
			del[w.id2]=1;
		}
	}
	tag+=x;
}
ll get(ll x){
	auto it=spos.lower_bound({x+tag,-inf,0});
	if(it!=spos.end()&&it->first-tag==x)return it->second;
	it=sneg.lower_bound({x-tag,-inf,0});
	if(it!=sneg.end()&&it->first+tag==x)return it->second;
	return 0;
}
ll size(){return spos.size()+sneg.size();}
}f[100005];
vector<Edge> q[100005];
void dfs(int x,int fa,int val){
	for(Edge i:g[x]){
		int y=i.to;
		if(y==fa)continue;
		dfs(y,x,i.val);
		if(f[x].size()<f[y].size())swap(f[x],f[y]);
		for(auto i:f[y].spos)i.first-=f[y].tag,f[x].insert(i);
		for(auto i:f[y].sneg)i.first+=f[y].tag,f[x].insert(i);
	}
	if(!x)return ;
	for(auto &i:q[x]){
		ll u1=-f[x].get(i.to),u2=f[x].get(i.to+1);
		i.val-=min((ll)i.val,max(0ll,max(u1,u2)));
	}
	f[x].extend(1);
	for(auto i:q[x]){
		ll t=i.to,v=i.val;
		if(!v)continue;
		f[x].insert({t,v,0});
		f[x].insert({t+1,-v,0});
	}
	f[x].extend(val-1);
}
pair<int,int> fin[200005];
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z),z*=2,g[x].push_back({y,z}),g[y].push_back({x,z});
	}
	scanf("%d",&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),x*=2,q[z].push_back({x,y});
	}
	g[0].push_back({1,2}),g[1].push_back({0,2});
	dfs(0,0,0);
	ll sum=0,mx=0,ts=0;
	for(auto i:f[0].spos){
		fin[++ts]=make_pair(i.first-f[0].tag,i.second);
	}
	for(auto i:f[0].sneg){
		fin[++ts]=make_pair(i.first+f[0].tag,i.second);
	}
	sort(fin+1,fin+ts+1);
	for(int i=1;i<=ts;i++)mx=max(mx,sum+=fin[i].second);
	cout<<mx;
}