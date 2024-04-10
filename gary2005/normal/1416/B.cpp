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
int a[10000+20];
int sum=0;
void solve(){
	sum=0;
	int n;
	R(n);
	rb(i,1,n) R(a[i]),sum+=a[i];
	if(sum%n!=0){
		cout<<-1<<endl;
		return;
	}
	vector<pair<mp,int> > rest;
	rb(i,2,n){
		int need=(a[i]+i-1)/i*i-a[i];
		rest.PB(II(II(1,i),need));
		rest.PB(II(II(i,1),(a[i]+i-1)/i));
	}
	rb(i,2,n){
		rest.PB(II(II(1,i),sum/n));
	}
	cout<<rest.size()<<endl;
	for(auto it:rest){
		cout<<it.FIR.FIR<<" "<<it.FIR.SEC<<" "<<it.SEC<<endl;
}
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