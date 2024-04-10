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
int n;
int a[300000+20];
vector<int> have[300000+20];
int rest[300000+20];
void solve(){
	R(n);
	fill(rest+1,rest+1+n,-1);
	rb(i,1,n)
		have[i].clear();
	rb(i,1,n)
		R(a[i]),have[a[i]].PB(i);
	int is=n;
	rb(i,1,n){
		int len=1;
		int las=0;
		for(auto it:have[i]){
			check_max(len,it-las);
			las=it;
		}
		check_max(len,n+1-las);
		while(is&&is>=len){
			rest[is--]=i;
		}
	}
	rb(i,1,n){
		cout<<rest[i]<<" "; 
	}
	cout<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--) solve();
	return 0;
}
/** 
  * 
  *
  *
  *
  **/