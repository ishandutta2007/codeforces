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
int t;
int n;
void solve(){
	LL w;
	scanf("%d%lld",&n,&w);
	LL l=(w+1)/2;
	LL tot=0;
	vector<int> rest;
	bool haveans=0;
	rb(i,1,n){
		LL wi;
		scanf("%lld",&wi);
		if(haveans) continue;
		if(wi>w) continue;
		if(wi>=l){
			tot=wi;
			rest.clear();
			rest.PB(i);
			haveans=1;
			continue;
		}
		tot+=wi;
		rest.PB(i);
		if(tot>=l){
			haveans=1;
		}
	}
	if(tot<l){
		puts("-1");
		return;
	}
	printf("%d\n",(int)rest.size());
	for(auto it:rest){
		printf("%d ",it);
	}
	printf("\n");
}
int main(){
	cin>>t;
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