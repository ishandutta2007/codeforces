/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=300000+20;
vector<mp> goup[MAXN];
int depth[MAXN];
int merge_times=0;
struct CHOICE{
	LL delta;
	LL rest;
	multiset<pair<LL,LL> > * ch;
	CHOICE(){
		rest=0;
		delta=0;
		ch=new multiset<pair<LL,LL > >;
	}
	
	void update1 (int now){
		for(auto it:goup[now]){
			ch->insert({-delta+it.SEC,it.FIR});
		}
	}
	void update2 (int now){
		while(ch->begin()!=ch->end()&&(ch->begin())->SEC>=depth[now]){
			ch->erase(ch->begin());
		}
		auto ite=ch->begin();
		if(ite==ch->end()){// 
			puts("-1");
			exit(0);
		}
		rest+= (*ite).FIR + delta;
		delta-= (*ite).FIR + delta;
	}
};
CHOICE merge (CHOICE A,CHOICE B){
		if(A.ch->size()<B.ch->size()){
			swap(A,B);
		}	
		//Put B into A
		for(auto ite=B.ch->begin();ite!=B.ch->end();ite++){
			LL real=(*ite).FIR+B.delta;
			A.ch->insert({real-A.delta,(*ite).SEC}); 
		}
		A.rest+=B.rest;
		return A;	
	}
int n,m;
vector<int> g[MAXN];
void dfs(int now,int pre,int deep=0){
	depth[now]=deep;
	for(auto it:g[now]){
		if(it!=pre){
			dfs(it,now,deep+1);
		}
	}
}
CHOICE calc(int now,int pre){
	CHOICE ret;
	if(now==1){
		LL rest=0;
		for(auto it:g[now]){
			if(it!=pre){
				rest+=calc(it,now).rest;
			}
		}
		printf("%lld\n",rest);
	}
	else{
		for(auto it:g[now]){
			if(it!=pre){
				ret=merge(ret,calc(it,now));
			}
		}
		ret.update1(now);
		ret.update2(now);
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	rb(i,1,m){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		goup[u].PB(II(depth[v],c));
	} 
	calc(1,0);
	return 0;
}
/** 
  *  choice[i] 
  *   delta 
  *   
  *   
  **/