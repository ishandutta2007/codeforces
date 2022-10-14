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
int t;
int main(){
	cin>>t;
	while(t--){
		LL p,q;
		cin>>p>>q;
		if(p%q!=0){
			cout<<p<<endl;
			continue;
		}
		vector<int> fact;
		for(LL i=1;i*i<=q;i++){
			if(q%i==0){
				if(i!=1)
				fact.PB(i);
				if(q/i!=1)
				fact.PB(q/i);		
			}
		}
		LL rest=1;
		for(auto it:fact){
			LL tmp=p;
			while(tmp%q==0){
				tmp/=it;
			}
			check_max(rest,tmp);
		}
		cout<<rest<<endl;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/