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
int a[100000+20];
vector<int> pos[100000+20];
const int N=1<<17;
struct seg{
	int tag[N+N]={0},tree[N+N]={0};
	void pd(int index){
		check_max(tree[index],tag[index]);
		if(index<N){
			
		check_max(tag[index<<1],tag[index]);
		check_max(tag[index<<1|1],tag[index]);
		}
		tag[index]=0;
	}
	void modify(int a,int b,int val,int now=1,int l=1,int r=N+1)
	{
		pd(now);
		if(r<=a||l>=b){
			return ;
		} 
		if(r<=b&&l>=a){
			tag[now]=max(tag[now],val);
			pd(now);
			return ;
		}
		int mid=(l+r)>>1;
		modify(a,b,val,now<<1,l,mid);
		modify(a,b,val,now<<1|1,mid,r);
		tree[now]=min(tree[now<<1],tree[now<<1|1]);
	} 
	int query(int a,int b,int now=1,int l=1,int r=N+1)
	{
		pd(now);	
		if(r<=a||l>=b){
			return INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt;
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) pos[a[i]].PB(i);
	if(pos[1].size()==n){
		cout<<1<<endl;
		return 0;
	}
	rb(i,1,n){
		int las=0;
		bool ok=0;
		for(auto it:pos[i]){
			if(it!=las+1){
				ok|=(sgt.query(las+1,it)<it);
			} 
			las=it;
		} 
		if(las!=n)
		ok|=sgt.query(las+1,n+1)<=n;
		if(i!=1&&!ok){
			cout<<i<<endl;
			return 0;
		}
		las=0;
		for(auto it:pos[i]){
			sgt.modify(las+1,it+1,it);
			las=it;
		}
		sgt.modify(las+1,N+1,INF);
		if(pos[i].empty()){
			cout<<i+1<<endl;
			return 0;
		}
	}
	if(sgt.query(1,n+1)<=n){
		cout<<n+2<<endl;
	}
	else 
	cout<<n+1<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/