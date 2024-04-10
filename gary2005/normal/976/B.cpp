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
int n,m;
LL k;
#define print(x,y) cout<<x<<" "<<y<<endl;
int main(){
	fastio;
	cin>>n>>m>>k;
	if(k<n){
		print(k+1,1);
		return 0;
	}
	k-=n-1;
	int N=(k+m-2)/(m-1);
	N=n-N+1;
	int M=k%(m-1);
	if(M==0) M=m-1;
	if(N%2==0){
		M++;
	}
	else{
		M=m-M+1;
	}
	print(N,M);
	return 0;
}