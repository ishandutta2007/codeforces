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
const int N=1<<18;
struct SEGMENT_TREE{
	/*  
	 * 1. max 
	 * 2max 
	 */	
	int tree[N+N];
	SEGMENT_TREE(){
		memset(tree,0,sizeof(tree));
	} 
	void modify(int a,int b,int val,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return;
		}
		if(r<=b&&l>=a){
			check_max(tree[now],val);
			return;
		}
		int mid=(l+r)>>1;
		modify(a,b,val,now<<1,l,mid);
		modify(a,b,val,now<<1|1,mid,r);
	}
	int query(int index){
		index+=N-1;
		int rest=0;
		while(index){
			check_max(rest,tree[index]);
			index>>=1;
		}
		return rest;
	}
}sgt1,sgt2;//| 
map<int,int> used;// 
vector<int> goup,gole;///    * 
int n,q;
int Find_up(int x){
	return lower_bound(ALL(goup),x)-goup.begin()+1;
}
int Find_le(int x){
	return lower_bound(ALL(gole),x)-gole.begin()+1;
}
int main(){
	scanf("%d%d",&n,&q);
	vector<pair<mp,char> > v;
	rb(i,1,q){
		int xi,yi;//- 
		scanf("%d%d",&yi,&xi);
		char c;
		cin>>c;
		if(c=='L'){
			gole.PB(xi);
		}
		else{
			goup.PB(yi);
		}
		v.PB(II(II(xi,yi),c));
	}
	sort(ALL(gole));
	gole.erase(unique(ALL(gole)),gole.end());
	sort(ALL(goup));
	goup.erase(unique(ALL(goup)),goup.end());
	for(auto it:v){
		int xi,yi;
		char c;
		xi=it.FIR.FIR;
		yi=it.FIR.SEC;
		c=it.SEC;
		if(used[xi]){
			puts("0");
			continue;
		} 
		used[xi]=1;
		if(c=='L'){
			int can=sgt2.query(Find_le(xi));
			int l,r;
			l=Find_up(can);
			r=Find_up(yi+1);
			if(l<r)
				sgt1.modify(l,r,xi);
			printf("%d\n",yi-can);
		}
		else{
			int can=sgt1.query(Find_up(yi));
			int l,r;
			l=Find_le(can);
			r=Find_le(xi+1);
			if(l<r)
				sgt2.modify(l,r,yi);
			printf("%d\n",xi-can);
		}
	}
	return 0;
}
/** 
  * 1.  
  * 2.  
  * 3.  / 
  * 4.  
  * 5. / 
  **/