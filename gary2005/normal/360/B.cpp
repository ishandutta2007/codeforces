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
int n,k,a[200000+20],dp[200000+20];
bool check(int w){
	int rest=INF;
	deque<int> useful;
	int mini=INF; 
	int delta=0;
	rb(i,1,n){
		dp[i]=i-1;
		delta++;
		while(!useful.empty()&&1ll*w*(i-useful.front())>=2000000000ll) check_min(mini,(i-useful.front()-1)+dp[useful.front()]-delta),useful.pop_front();
		check_min(dp[i],mini+delta);
		for(auto j:useful){
			if(1ll*(i-j)*w>=(LL)abs(a[i]-a[j])){
				check_min(dp[i],dp[j]+(i-j-1));
			}
		}
		if(dp[i]<rest&&dp[i]<=k){
			useful.PB(i);
		}
		check_min(rest,n-i+dp[i]);
		if(rest<=k) return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&k);
	rb(i,1,n) scanf("%d",&a[i]);
	LL l=0,r=2000000000+1;
	while(l<r){
		LL mid=(LL)(l+r)>>1;
		if(check(mid)){
			r=mid;			
		}
		else{
			l=mid+1;
		}
	}	
	cout<<l<<endl;
	return 0;
}
/*
5 2
4 7 4 7 4

3 1
-100 0 100

6 3
1 2 3 7 8 9
*/