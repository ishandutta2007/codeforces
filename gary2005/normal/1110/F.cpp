/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL tree[500000*8],lazy[500000*8];int treen;
LL change(int a,int b,LL val,int l=1,int r=treen+1,int now=1){
	if(r<=a||l>=b){
		return tree[now]+lazy[now];
	}
	if(r<=b&&l>=a){
		lazy[now]+=val;
		return tree[now]+lazy[now];
	}
	int mid=(l+r)>>1;
	return (tree[now]=min(change(a,b,val,l,mid,now<<1),change(a,b,val,mid,r,(now<<1)+1)))+lazy[now]; 
}
LL query(int a,int b,int l=1,int r=treen+1,int now=1){
	if(r<=a||l>=b){
		return (LL)(1e17);
	}
	if(r<=b&&l>=a){
		return tree[now]+lazy[now];
	}
	int mid=(l+r)>>1;
	return min(query(a,b,l,mid,now<<1),query(a,b,mid,r,(now<<1)+1))+lazy[now];
}
vector<mp> each[500000+1];
vector<pair<mp,int> > qq[500000+1]; 
LL ans[500000+1],dis[500000+1];
int id[500000+1],maxi[500000+1],tmptt=0;
void dfs(int now,int prev=-1,LL dist=0){
	dis[now]=dist;
	id[now]=++tmptt;
	maxi[now]=id[now];
	for(auto it:each[now]){
		if(it.FIR!=prev){
			dfs(it.FIR,now,dist+it.SEC);
			maxi[now]=max(maxi[now],maxi[it.FIR]);	
		}
	}
}
int n,q;
void calc(int now,int prev=-1){
	for(auto it:qq[now]){
		ans[it.SEC]=query(it.FIR.FIR,it.FIR.SEC+1);
	}
	for(auto it:each[now]){
		int u=it.FIR;
		if(u!=prev){
			change(1,n+1,it.SEC);
			change(id[u],maxi[u]+1,-2*it.SEC);
//			cout<<u<<" "<<query(id[u],id[u]+1)<<" "<<maxi[u]+1<<endl; 
			calc(u,now);
			change(1,n+1,-it.SEC);
			change(id[u],maxi[u]+1,2*it.SEC);
		}
	}
}
int main(){
	fastio;
//	memset()
	cin>>n>>q;
	treen=1<<(int)(ceil(log2(double(n))));
	rep(i,n-1){
		int p,w;
		cin>>p>>w;
		each[p].PB(II(i+2,w));
		each[i+2].PB(II(p,w));
	} 
	rb(i,1,q){
		int v,l,r;
		cin>>v>>l>>r;
		qq[v].PB(II(II(l,r),i));
	}
	rb(i,1,n)
		sort(ALL(each[i]));
	dfs(1);
	change(id[1],id[1]+1,(LL)(1e17));
	rb(i,2,n){
		if(each[i].size()!=1){
			change(id[i],id[i]+1,(LL)(1e17));
		}
		else{
			change(id[i],id[i]+1,dis[i]);
		}
	}
//	cout<<query(2,3)<<endl;
	calc(1);
	rb(i,1,q){
		cout<<ans[i]<<endl;
	} 
	return 0;
}