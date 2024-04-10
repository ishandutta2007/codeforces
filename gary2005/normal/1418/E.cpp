/*
{By GWj
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
int d[200000+20],inv[200000+20];
const int MOD=998244353 ;
LL quick(int A,int B){
	if(B==0) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1) tmp=tmp*A%MOD;
	return tmp;
}
LL sum[200000+20];
int main(){
	fastio;
	R2(n,m);
	rb(i,1,n){
		R(d[i]); 
	}
	sort(d+1,d+1+n);
	rb(i,1,200010){
		inv[i]=quick(i,MOD-2);
	}
	rb(i,1,n){
		sum[i]=sum[i-1]+d[i];
		sum[i]%=MOD;
	}
	rb(i,1,m){
		int a,b;
		R2(a,b);
		int ix=lower_bound(d+1,d+1+n,b)-d;
		if(ix>n){
			cout<<0<<endl;
			continue;
		}	
		else{
			int p=n-ix+1;
			if(a>p){
				cout<<0<<endl;
				continue; 
			}
			int save=p-a,save2=p;
			p=1ll*(p-a)*inv[p]%MOD;
			LL rest=0;
			rest=sum[n]-sum[ix-1];
			if(rest<0) rest+=MOD;
			rest=rest*p%MOD;
			LL zzz;
			zzz=1ll*(save+1)*inv[save2+1]%MOD;
			rest=(rest+sum[ix-1]*zzz%MOD)%MOD;
			cout<<rest<<endl;
		}
	}
	return 0;
}