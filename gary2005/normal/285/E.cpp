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
const int MOD=1e9+7;
int f[1001][1001][1<<3];
int n,k;
void add(int& x,int y){
	x+=y;
	if(x>=MOD)
		x-=MOD;
}
LL fact[1001],rfact[1001];
LL quick(int A,int B){
	if(!B) return 1ll;
	LL rest=quick(A,B>>1);
	rest*=rest;
	rest%=MOD;
	if(B&1) rest=rest*A%MOD;
	return rest;
}
int c(int A,int B){
	return fact[A]*rfact[B]%MOD*rfact[A-B]%MOD;
}
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	R2(n,k);
	f[0][0][0]=1;
	fact[0]=1;
	rb(i,1,1000)
		fact[i]=fact[i-1]*i%MOD;
	rfact[1000]=quick(fact[1000],MOD-2);
	rl(i,999,1){
		rfact[i]=rfact[i+1]*(i+1)%MOD;
	}
	rfact[0]=1;
	rep(i,n){
		rep(j,i+1){
			rep(mask,1<<3){
				if(f[i][j][mask]){
					int nex_mask=mask;
					nex_mask<<=1;
					nex_mask&=(1<<3)-1;
					if(i+2<=n){ 
						add(f[i+1][j+1][nex_mask+1],f[i][j][mask]);
					}
					if(i>=1&&!(nex_mask&4)){ 
						add(f[i+1][j+1][nex_mask+4],f[i][j][mask]);
					}
					add(f[i+1][j][nex_mask],f[i][j][mask]);  
				}
			}
		}
	} 
	int rest=0;
	rb(kk,k,n){
		int res=0;
		rep(mask,1<<3){
			add(res,f[n][kk][mask]);
		}
		rb(i,1,n-kk){
			res=1ll*res*i%MOD;
		}
		if((kk-k)&1){
			res=1ll*res*c(kk,k)%MOD;
			res=MOD-res;
			rest+=res;
			rest%=MOD;
		}
		else{
			add(rest,1ll*res*c(kk,k)%MOD);
		}
	}
	cout<<rest<<endl;
	return 0;
}
/*
20 2
483564804

*/