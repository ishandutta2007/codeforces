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
const int N=1<<18;
struct SEGTREE{
	int tree[N+N],lazy[N+N];
	inline void push_down(int index){
		tree[index]+=lazy[index];
		if(index<N)
			lazy[index<<1]+=lazy[index],lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	void modify(int a,int b,int val,int now=1,int l=1,int r=N+1){
		if(a>=b) return;
		push_down(now);
		if(b<=l||a>=r){
			return ;
		}
		if(r<=b&&l>=a){
			lazy[now]+=val;
			push_down(now);
			return ;
		}
		int mid=(l+r)>>1;
		modify(a,b,val,now<<1,l,mid);
		modify(a,b,val,now<<1|1,mid,r);
		tree[now]=min(tree[now<<1],tree[now<<1|1]);
	}	
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(b<=l||a>=r){
			return INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt;
int a[500000+20];
vector<int> app[500000+20];
vector<int> l,r;
int get(int x){
	return (upper_bound(ALL(l),x)-l.begin());	
}
int main(){
	fastio;
	int t;
	R(t);
	int n;
	while(t--){
		R(n);
		l.clear();
		r.clear();
		rb(i,1,n) app[i].clear();
		rb(i,1,n) R(a[i]),app[a[i]].PB(i);
		vector<int> zero;
		rb(i,1,n)
			if(!a[i])
				zero.PB(i);
		rb(i,1,n/2)
			sgt.modify(i,i+1,-sgt.query(i,i+1));
		int rest=zero.size()/2;
		rep(i,rest)
			l.PB(zero[i]);
		rep(i,rest)
			r.PB(zero[zero.size()-i-1]);
		rb(i,1,rest)
			sgt.modify(i,i+1,-rest+i-1);
		rb(i,1,n)
			if(!app[i].empty()){
				int pos=get(app[i].back());
				sgt.modify(1,pos+1,1);
			}
		int gwj=0;
		int las=n;
		int Z=rest;
		rep(i,Z){
			int now=r[i];
			rl(i,las,now+1){
				int pos=get(i);
				sgt.modify(1,pos+1,-1);
				app[a[i]].pop_back();
				if(!app[a[i]].empty()){
					pos=get(app[a[i]].back());
					sgt.modify(1,pos+1,1);
				}
			}
			while(rest&&sgt.query(1,rest+1)<0){
				sgt.modify(1,rest+1,1);
				rest--; 
			}
			sgt.modify(1,rest+1,1);
			las=now;
			if(rest==0) break;
			gwj++;
			rest--;
		}
		cout<<gwj<<endl;
	}
	return 0;
}