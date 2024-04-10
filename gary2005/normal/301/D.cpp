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
pair<mp,int> q[200000+20];
int pos[200000+20];
int ans[200000+20];
int bit[200000+10]={0};
int n,m;
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=n){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		pos[ai]=i;
	}
	vector<mp> p; 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			p.PB(II(min(pos[i],pos[j]),max(pos[i],pos[j])));
		}
	}
	sort(ALL(p));
	rb(i,1,m){
		int l,r;
		scanf("%d%d",&l,&r);
		q[i]=II(II(l,r),i);
	}
	for(auto it:p){
		add(it.SEC);
	}
	sort(q+1,q+1+m);
	int is=0;
	rb(i,1,m){
		while(is<p.size()&&p[is].FIR<q[i].FIR.FIR){
			add(p[is++].SEC,-1);
		}
		ans[q[i].SEC]=sum(q[i].FIR.SEC);
	}
	rb(i,1,m) printf("%d\n",ans[i]);
	return 0;
}
/** 
  *
  *
  *
  *
  **/