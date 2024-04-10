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
const int MAXN=505;
int MOD;
int dp[MAXN][MAXN*MAXN],fact[MAXN],c[MAXN][MAXN],pre[MAXN*MAXN],suf[MAXN*MAXN];
void add(int & A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
int m;
int query(int l,int r){
	return (l==0? pre[r]:(pre[r]+MOD-pre[l-1])%MOD);
}
int query2(int l,int r){
	if(r==m) return suf[l];
	int tmp=suf[l]+MOD-suf[r+1];
	tmp%=MOD;
	add(tmp,MOD-1ll*query(l,r)*(m-r)%MOD);
	return tmp;
}
int main(){
	int n;
	scanf("%d%d",&n,&MOD);
	dp[0][0]=1;
	rb(i,1,n){
		int sum=0;
		rb(j,0,i*(i-1)/2){
			add(sum,dp[i-1][j]);
			if(j>=i) add(sum,MOD-dp[i-1][j-i]);
			dp[i][j]=sum;
		}
	}
	rb(i,0,500) c[i][0]=1;
	rb(i,1,500) rb(j,1,500) (c[i][j]=c[i-1][j]+c[i-1][j-1])%=MOD;
	fact[0]=1;
	rb(i,1,n) fact[i]=1ll*fact[i-1]*i%MOD;
	int ans=0;
	rb(i,2,n){
		m=(i-2)*(i-1)/2;
		int tmp=0;
//		rb(j,1,i-2) trans[j+1]=j*i-j*(j+1)/2,trans[j]%=MOD;
		int W=(i-1)*i/2;
		W%=MOD;
		rb(j,0,m){
			if(j) pre[j]=pre[j-1];
			else pre[j]=0;
			add(pre[j],dp[i-1][j]);
		}
		rl(j,m,0){
			suf[j]=suf[j+1];
			add(suf[j],1ll*(m-j+1)*dp[i-1][j]%MOD);
		}
//		cout<<i<<"______________________\n";
		int sum=0;
		rb(j,2,m){
			int l=max(0,j-(i-1)-1);
			int r=j-2;
			add(sum,1ll*query(l,r)*i%MOD);
			add(sum,MOD-query2(l,r));
			if(j>i-1){
				add(sum,MOD-1ll*W*dp[i-1][j-i]%MOD);
			}
//			cout<<sum<<endl;
			add(tmp,1ll*sum*dp[i-1][j]%MOD);
		}
//		cout<<tmp<<endl;
		sum=0;
		rb(j,0,m){
			if(j>i-1) add(sum,dp[i-1][j-(i-1)-1]);
			add(tmp,1ll*sum*dp[i-1][j]%MOD*W%MOD);
		}
		add(ans,1ll*tmp*fact[n-i]%MOD*c[n][n-i]%MOD);
	}
	printf("%d\n",ans);
	return 0;
}