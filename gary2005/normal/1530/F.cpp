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
const int MAXN=21;
int a[MAXN][MAXN],n;
const int MOD=31607;
int fullmask;
int prod[MAXN][1<<MAXN];
int lg[1<<MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=tmp*tmp%MOD;
	if(B&1) tmp=tmp*A%MOD;
	return tmp;
}
int main(){
	scanf("%d",&n);
	fullmask=1<<n;
	fullmask--;
	rep(i,n) lg[1<<i]=i;
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]),a[i][j]=a[i][j]*quick(10000,MOD-2)%MOD;
	rep(i,n){
		rep(mask,1<<n){
			if(mask==0) prod[i][mask]=1;
			else{
				int lb=mask&-mask;
				prod[i][mask]=prod[i][mask^lb]*a[lg[lb]][i]%MOD;
			}
//			cout<<i<<" "<<mask<<" "<<prod[i][mask]<<endl;
		}
	}
	int ans=0;
	rep(i,2) rep(j,2) rep(mask,1<<n){
		int tmp=1;
		if(i) rep(i,n) tmp=tmp*a[i][i]%MOD;
		if(j) rep(y,n) if(n-1-y!=y||!i) tmp=tmp*a[n-1-y][y]%MOD;
		int dp[2]={0,0};
		dp[((i+j+__builtin_popcount(mask))&1)^1]=tmp;
		rep(k,n){
			int newdp[2]={0,0};
			rep(f,2){
				rep(g,2){
					int cons;
					if(f){
						int mas=fullmask;
						if(i)if((mas>>k)&1) mas^=1<<k;
						if(j)if((mas>>(n-1-k))&1) mas^=1<<(n-1-k);
						cons=prod[k][mas];
					}
					else{
						int mas=mask;
						if(i)if((mas>>k)&1) mas^=1<<k;
						if(j)if((mas>>(n-1-k))&1) mas^=1<<(n-1-k);
						cons=prod[k][mas];
					}
					newdp[f^g]+=dp[g]*cons;
					newdp[f^g]%=MOD;
				}
			}
			dp[0]=newdp[0];
			dp[1]=newdp[1];
//			cout<<dp[0]<<' '<<dp[1]<<endl;
		}
		ans+=dp[0];
		ans+=MOD-dp[1];
		ans%=MOD;
	}
	ans++;
	ans%=MOD;
	printf("%d\n",ans);
	return 0;
}