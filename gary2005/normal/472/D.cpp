/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int fa[2000+20]; 
LL d[2000+20][2002];
vector<mp> g[2002];
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
LL dis[2002];
void calc(int now,int pre=0,LL dd=0){
	dis[now]=dd;
	for(auto it:g[now]){
		if(it.FIR!=pre){
			calc(it.FIR,now,dd+it.SEC);
		}
	}
}
int main(){
//	fastio;
	int n;
	scanf("%d ",&n);
	rb(i,1,n) fa[i]=i;
	vector<pair<int,mp > > edges;
	rb(i,1,n){
		rb(j,1,n){
			scanf("%I64d",&d[i][j]);
		 	if(i!=j)
		 		edges.PB(II(d[i][j],II(i,j)));
		}
	}
	sort(ALL(edges));
	for(auto it:edges){
		int w,u,v;
		w=it.FIR;
		if(w==0){
			cout<<"NO"<<endl;
			return 0;
		}
		u=it.SEC.FIR;
		v=it.SEC.SEC;
		if(root(u)!=root(v)){
			g[u].PB(II(v,w));
			g[v].PB(II(u,w));
			fa[root(u)]=root(v); 
		} 
	}
	rb(i,1,n){
		calc(i);
		rb(j,1,n)
			if(d[i][j]!=dis[j]){
				cout<<"NO"<<endl;
				return 0;
			}
	}
	cout<<"YES"<<endl;
	return 0;
}