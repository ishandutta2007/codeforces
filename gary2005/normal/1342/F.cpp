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
const int MAXN=15;
mp pre[MAXN][MAXN][1<<MAXN];
int dp[MAXN][MAXN][1<<MAXN];
int n,a[MAXN],sum[1<<MAXN];
vector<mp> V;
bool era[MAXN];
int id[MAXN+1];
void print(int i,int j,int mask){
	if(j==1){
		era[i]=1;
		return ;
	}
	int smask=mask^(1<<i)^pre[i][j][mask].SEC;
	era[i]=1;
	rep(x,n){
		if((smask>>x)&1){
			era[x]=1;
			V.PB(II(x+1,i+1));
		}
	}
	print(pre[i][j][mask].FIR,j-1,pre[i][j][mask].SEC);
}
int G[MAXN+1];
void solve(){
	scanf("%d",&n);
	bool ok=1;
	rep(i,n) G[i+1]=1,era[i]=0,scanf("%d",&a[i]),ok&=(!i||a[i]>a[i-1]);
	if(ok){
		puts("0");
		return ;
	}
	rep(mask,1<<n){
		rep(j,n){
			if((mask>>j)&1)
				sum[mask]=sum[mask^(1<<j)]+a[j];
		}
	}
	rep(i,n) rep(j,n) rep(mask,1<<n) dp[i][j][mask]=INF;
	rep(i,n) dp[i][1][((1<<n)-1)^(1<<i)]=a[i];
	rep(i,n) rep(j,n) rep(mask,1<<n) if(dp[i][j][mask]<=2e7){
		rb(k,i+1,n-1){
			if((mask>>k)&1){
				for(int smask=mask^(1<<k);;smask=(mask^(1<<k))&(smask-1)){
					if(sum[smask]+a[k]>dp[i][j][mask]){
						if(sum[smask]+a[k]<dp[k][j+1][mask^(1<<k)^smask]){
							dp[k][j+1][mask^(1<<k)^smask]=sum[smask]+a[k];
							pre[k][j+1][mask^(1<<k)^smask]=II(i,mask);
						}
					}
					if(!smask) break; 
				}
			}
		}
	}
	int best,I,J,K;
	best=1e9;
	rep(i,n) rep(j,n) rep(mask,1<<n) if(dp[i][j][mask]<=2e7&&n-j<best){
		best=n-j;
		I=i,J=j,K=mask;
	}
	V.clear();
	print(I,J,K);
	rep(i,n) if(!era[i]) V.PB(II(i+1,I+1));
	cout<<V.size()<<endl;
	for(auto it:V){
		int A=0,B=0;
		rb(i,1,it.FIR) A+=G[i];
		rb(i,1,it.SEC) B+=G[i];
		cout<<A<<" "<<B<<endl;
		G[it.FIR]=0;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}