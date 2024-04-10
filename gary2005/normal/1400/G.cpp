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
const int MOD=998244353 ;
LL fact[300001],rfact[300001];
LL quick(LL A,LL B){
	if(!B) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
LL c(LL A,LL B){
	return fact[B]*rfact[B-A]%MOD*rfact[A]%MOD;
}
LL sum[300000+1][41];
int have[300000+2];
mp seg[300000+1];
mp bad[22];
bool vis[300000+1];
int m;
mp merge(mp A,mp B){
	return II(max(A.FIR,B.FIR),min(A.SEC,B.SEC));
}
	int n;
LL calc(int mask){
	int have=0;
	mp nnn=II(1,n);
	rep(i,m){
		if((mask>>i)&1){
			if(!vis[bad[i+1].SEC]){
				have++;
				nnn=merge(nnn,seg[bad[i+1].SEC]);
			}
			if(!vis[bad[i+1].FIR]){
				have++;
				nnn=merge(nnn,seg[bad[i+1].FIR]);
			}
			vis[bad[i+1].SEC]=vis[bad[i+1].FIR]=1;
		}
	}
	rep(i,m){
		if((mask>>i)&1){
			vis[bad[i+1].SEC]=vis[bad[i+1].FIR]=0;
		}
	}
	if(nnn.SEC<nnn.FIR) return 0ll;
	return (sum[nnn.SEC][have]-sum[nnn.FIR-1][have]+MOD)%MOD;
}
int main(){
	fastio;
	fact[0]=1ll;
	rb(i,1,300001-1)
		fact[i]=fact[i-1]*i%MOD;
	rfact[300000]=quick(fact[300000],MOD-2);
	rfact[0]=1;
	rl(i,300000-1,1){
		rfact[i]=rfact[i+1]*(i+1)%MOD;
	}
	R2(n,m);
	rb(i,1,n){
		R2(seg[i].FIR,seg[i].SEC);
		have[seg[i].FIR]++;
		have[seg[i].SEC+1]--;
	}
	rb(i,1,n)
		have[i]+=have[i-1];
	rb(j,0,40){
		rb(i,1,n){
			if(have[i]>=i&&i>=j)
			sum[i][j]=c(i-j,have[i]-j);
		}
		rb(i,1,n)
			sum[i][j]+=sum[i-1][j],sum[i][j]%=MOD;
	}
	rb(i,1,m){
		R2(bad[i].FIR,bad[i].SEC);
	}
	LL rest=0;
	rep(mask,1<<m){
		int count=0;
		rep(j,m)
			count+=(mask>>j)&1;
		int is=1;
		rep(i,count)
			is=-is;
		rest+=is*calc(mask);
		rest+=MOD;
		rest%=MOD;
	}
	cout<<rest<<endl;
	return 0;
}