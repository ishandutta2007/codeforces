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
struct ITEM{
	int t,d,p,id;
	bool operator < (ITEM & oth) const{
		return d<oth.d; 
	}
	ITEM(int a,int b,int c,int I){
		t=a;d=b;p=c;id=I;
	}
}; 
vector<ITEM> v;
const int MAXT=20*100;
pair<int,vector<int> > dp[MAXT+1];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		b--;
		v.PB(ITEM(a,b,c,i));
	}
	sort(ALL(v));
	pair<int,vector<int> > rest=II(0,vector<int>(0));
	for(auto it:v){
		rl(i,it.d,it.t){
			if(dp[i].FIR<dp[i-it.t].FIR+it.p){
				dp[i]=dp[i-it.t];
				dp[i].FIR+=it.p;
				dp[i].SEC.PB(it.id);
				if(rest.FIR<dp[i].FIR){
					rest=dp[i];
				} 
			}
		}
	}
	printf("%d\n%d\n",rest.FIR,rest.SEC.size());
	for(int it:rest.SEC) printf("%d ",it);
	return 0;
}
/** 
  *
  *
  *
  *
  **/