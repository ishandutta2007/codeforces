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
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		int las=0,las2=INF;
		bool ok=1;
		rb(i,1,n){
			int ai;
			scanf("%d",&ai);
			int can=max(las,ai-las2);//ai-can<=las2
			if(can>ai) ok=0;
			las2=ai-can;
			las=can;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/