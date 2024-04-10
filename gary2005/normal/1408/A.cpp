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
vector<int> rest[101];
void solve(){
	int n;
	R(n);
	rb(i,1,n) rest[i].clear();
	rb(i,1,n)
	{
		int a;
		R(a);
		rest[i].PB(a);
	}
	rb(i,1,n)
	{
		int b;
		R(b);
		rest[i].PB(b);
	}
	rb(i,1,n)
	{
		int c;
		R(c);
		rest[i].PB(c);
	}
	int pre=-1,fir=-1;
	rb(i,1,n){
		for(auto it:rest[i]){
			if(it!=pre){
				if(i==n&&it==fir) continue;
				cout<<it<<" ";
				pre=it;
				if(i==1) fir=it;
				break;
			}
		} 
		
	}
	cout<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--){
		solve();
	}	
	return 0;
}
/** 
  *
  *
  *
  *
  **/