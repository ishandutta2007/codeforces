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
int n,r1,r2;
vector<int> g[50000+20];
int rest[50000+20];
void run(int now,int pre){
	rest[now]=pre;
	for(auto it:g[now]){
		if(it!=pre){
			run(it,now);
		}
	}
}
int main(){
	fastio;
	cin>>n>>r1>>r2;
	rb(i,1,n){
		if(i==r1) continue;
		int f;
		R(f);
		g[f].PB(i);
		g[i].PB(f);
	}
	run(r2,0);
	rb(i,1,n) if(i!=r2)cout<<rest[i]<<" ";
	cout<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/