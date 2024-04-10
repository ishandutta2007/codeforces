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
const int MAXN=333335;
vector<pair<LL,LL> > obj; 
int k;
int f[6];
int num=1;
LL dp[MAXN+20];
LL calc(int num){
	LL ret=0;
	rb(i,0,5){
		if((num%10)%3==0){
			ret+=1ll*(num%10)/3*f[i];
		}
		num/=10;
	}
	return ret;
}
int main(){
	scanf("%d",&k);
	k--;
	rb(i,0,5){
		scanf("%d",&f[i]);
		int cnt_obj=3*k;
		int z=1;
		while(cnt_obj>=z){
			cnt_obj-=z;	
			if(1ll*z*num<=1ll*MAXN)
			obj.PB(II(1ll*z*num,1ll*z*f[i]));
			z<<=1;	
		}
		if(cnt_obj){
			if(1ll*cnt_obj*num<=1ll*MAXN)
			obj.PB(II(1ll*cnt_obj*num,1ll*cnt_obj*f[i]));
		}
		num*=10;
	}
	memset(dp,-127,sizeof(dp));
	dp[0]=0;
	for(auto it:obj){
		rl(i,MAXN,it.FIR){
			check_max(dp[i],dp[i-it.FIR]+it.SEC);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int ni;
		scanf("%d",&ni);
		LL rest=0;
		rb(i,0,ni){
			if((ni-i)%3==0){
				check_max(rest,dp[(ni-i)/3]+calc(i));
			}
		}
		cout<<rest<<endl;
	}
	return 0;
}