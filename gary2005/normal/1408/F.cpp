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
vector<mp> ope;
void work(int delta,int n){
	for(int i=1;i<=n/2;i<<=1){
		for(int j=1;j<=n;j+=i+i){
			for(int k=j;k<=j+i-1;k++){
				ope.PB(II(k+delta+i,k+delta));
			} 
		}
	}
}
int n;
int main(){
	fastio;
	R(n);
	if(n<=2){
		cout<<0<<endl;
		return 0;	
	} 
	int is=1;
	while(is*2<n) is<<=1;
//	cout<<is<<endl;
	work(0,is);
	work(n-is,is); 
	cout<<ope.size()<<endl;
	for(auto it:ope) cout<<it.FIR<<" "<<it.SEC<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/