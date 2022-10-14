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
mp ok[1001];
int main(){
	fastio;
	fill(ok,ok+1000+1,II(-1,-1));
	rb(i,0,1001)
		rb(j,0,1001)
			if(i*3+j*5<=1000)
				ok[i*3+j*5]=II(i,j);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool okh=0;
		rb(i,0,n){
			if((n-i)%7==0){
				if(ok[i].FIR==-1) continue;
				cout<<ok[i].FIR<<" "<<ok[i].SEC<<' '<<(n-i)/7<<endl;
				okh=1;
				break;
			}
		}
		if(!okh) cout<<-1<<endl;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/