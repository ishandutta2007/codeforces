/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
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
int n,k;
vector<int> x,y;
const int MOD=1000000007; 
map<LL,int> dp[55][55];
vector<mp> g[55];
int fac[100000+20];
LL have[55];
int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1;
	rb(i,1,n)
		fac[i]=1ll*fac[i-1]*i%MOD;
	vector<pair<mp,int> > e;  
	rb(i,1,k){
		int xi,yi,wi;
		scanf("%d%d%d",&xi,&yi,&wi);
		x.PB(xi);
		y.PB(yi);
		e.PB(II(II(xi,yi),wi-1));
	}	
	sort(ALL(x));
	sort(ALL(y));
	for(auto & it:e){
		it.FIR.FIR=lower_bound(ALL(x),it.FIR.FIR)-x.begin();
		it.FIR.SEC=lower_bound(ALL(y),it.FIR.SEC)-y.begin();
		g[it.FIR.FIR].PB({it.FIR.SEC,it.SEC});
	}
	int sz=x.size();
	rl(i,sz-1,0){
		have[i]=have[i+1];
		for(auto it:g[i]) have[i]|=1ll<<it.FIR;
	}
	dp[0][0][0]=1;
	rb(i,0,sz-1){
		rb(j,0,sz){
			for(auto sta=dp[i][j].begin();sta!=dp[i][j].end();sta++){
				dp[i+1][j][sta->FIR & (have[i+1])]+=sta->SEC;
				if(dp[i+1][j][sta->FIR & (have[i+1])]>=MOD) dp[i+1][j][sta->FIR & (have[i+1])]-=MOD;
				for(auto it:g[i]){
					int nex=it.FIR;
					int w=it.SEC;
					if(((sta->FIR)>>nex)&1);
					else
						(dp[i+1][j+1][(sta->FIR|1ll<<nex)&(have[i+1])]+=1ll*sta->SEC * w%MOD)%=MOD;
				}
			}
		}
	}
	int rest=0;
	rb(i,0,sz){
		(rest+=1ll*fac[n-i]*dp[sz][i][0]%MOD)%=MOD;
	}
	cout<<rest<<endl;
	return 0;
}