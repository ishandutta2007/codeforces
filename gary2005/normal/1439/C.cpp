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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,q;

set<pair<mp,int> > s1;
set<pair<int,mp> > s2;

void modify(int x,int y){
	auto ite=s1.upper_bound(II(II(x,INF),INF));
	assert(ite!=s1.begin());
	ite--;
	if(ite->SEC>=y) return;
	mp seg;
	int val;
	seg=ite->FIR;
	val=ite->SEC;
	while(true){
		if(ite->SEC>y) break;
		bool b=0;
		set<pair<mp,int> > :: IT nex;
		if(ite!=s1.begin()){
			nex=--ite;
			ite++;
		}
		else b=1;
		seg.FIR=(ite->FIR).FIR;
		s1.erase(ite);
		s2.erase(II(ite->SEC,ite->FIR));
		if(b) break;
		ite=nex;
	}
	if(seg.SEC>x){
		s1.insert(II(II(x+1,seg.SEC),val));
		s2.insert(II(val,II(x+1,seg.SEC)));
		seg.SEC=x;
	}
	s1.insert(II(seg,y));
	s2.insert(II(y,seg));
}
int solve(int x,int y){
	auto ite=s1.upper_bound(II(II(x,INF),INF));
	assert(ite!=s1.begin());
	ite--;
	auto ite2=s2.lower_bound(II(ite->SEC,ite->FIR));
	int rest=0;
	while(true){
		if(ite2->FIR>y){
			ite2=s2.upper_bound(II(y,II(INF,INF)));
			if(ite2==s2.begin()) break;
			ite2--;	
		}
		int b=0;
		set<pair<int,mp> > :: IT nex;
		if(ite2!=s2.begin()){
			nex=--ite2;
			ite2++;
		}
		else b=1;
		
		int val;
		mp seg;
		
		val=ite2->FIR;
		seg=ite2->SEC;
		
		int have=min(seg.SEC-max(x,seg.FIR)+1,y/val);
		y-=have*val;
		rest+=have;
		
		if(b) break;
		
		ite2=nex;
	}
	return rest;
}

int main(){
	scanf("%d%d",&n,&q);
	s1.insert(II(II(1,n),1));
	s2.insert(II(1,II(1,n)));
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		modify(i,ai);
	}
	rb(i,1,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			scanf("%d%d",&x,&y);
			modify(x,y);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",solve(x,y));
		}
	}
	return 0;	
}
/** 
  * 
  *
  *
  *
  **/