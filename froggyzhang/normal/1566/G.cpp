#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1e10;
tree<pair<int,ll>,null_type,less<pair<int,ll> >,rb_tree_tag,tree_order_statistics_node_update> T[N],all;
map<int,int> mp[N];
int n,m,Q;
multiset<ll> S;
vector<int> G[N];
void calc(auto &T,int opt){
	if(T.size()<3)return;
	ll w=(ll)(T.find_by_order(0)->first)+(T.find_by_order(1)->first)+(T.find_by_order(2)->first);
	if(opt==1)S.insert(w);
	else S.erase(S.find(w));
}
void Ins(int u,int v,int w){
	if(u>v)swap(u,v);
	calc(T[u],-1);
	calc(T[v],-1);
	T[u].insert(make_pair(w,v));
	T[v].insert(make_pair(w,u));
	calc(T[u],1);
	calc(T[v],1);
	all.insert(make_pair(w,1LL*(u-1)*n+v));
	mp[u][v]=w;
}
void Del(int u,int v){
	if(u>v)swap(u,v);
	calc(T[u],-1);
	calc(T[v],-1);
	int w=mp[u][v];
	T[u].erase(make_pair(w,v));
	T[v].erase(make_pair(w,u));
	calc(T[u],1);
	calc(T[v],1);
	all.erase(make_pair(w,1LL*(u-1)*n+v));	
}
inline ll Get(int u,int v){
	int l=0,r=1e9+233;
	ll ans=inf;
	if(!mp[u].count(v))return ans;
	while(l<r){
		int mid=(l+r)>>1;
		auto jb=make_pair(mid+1,0LL);
		if(all.order_of_key(jb)-T[u].order_of_key(jb)-T[v].order_of_key(jb)+(mp[u][v]<=mid)>0){
			ans=r=mid;	
		}
		else{
			l=mid+1;
		}
	}
	return ans+mp[u][v];
}
ll get_ans(){
	auto [len1,tmp1]=*all.find_by_order(0);
	auto [len2,tmp2]=*all.find_by_order(1);
	vector<int> V;
	V.push_back((tmp1-1)/n+1);
	V.push_back((tmp1-1)%n+1);
	V.push_back((tmp2-1)/n+1);
	V.push_back((tmp2-1)%n+1);
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	if(V.size()==4)return len1+len2;
	return min(min(min(Get(V[0],V[1]),Get(V[0],V[2])),Get(V[1],V[2])),S.empty()?inf:*S.begin());
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		Ins(u,v,w);
	}
	cin>>Q;
	cout<<get_ans()<<'\n';
	while(Q--){
		int opt,u,v;
		cin>>opt>>u>>v;
		if(opt==1){
			int w;cin>>w;Ins(u,v,w);	
		}
		else Del(u,v);
		cout<<get_ans()<<'\n';
	}
	return 0;
}