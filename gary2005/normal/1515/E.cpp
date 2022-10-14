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
int n;
int MOD;
int k[404];
int fact[404],rfact[404];
int c[404][404],dp[404][404],ans[404];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp; 
}
int main(){
	scanf("%d%d",&n,&MOD);
	rb(i,0,400) c[i][0]=1;
	rb(i,1,400) rb(j,1,400) (c[i][j]=c[i-1][j-1]+c[i-1][j])%=MOD;
	fact[0]=1;
	rb(i,1,400) fact[i]=1ll*fact[i-1]*i%MOD,rfact[i]=quick(fact[i],MOD-2);
	rb(i,1,400){
		rb(j,1,i){
			(k[i]+=c[i-1][j-1])%=MOD;
		}
	}
	dp[0][0]=1;
	rb(i,1,n){
		rb(j,1,n){
			rb(l,1,j){
				(dp[i][j]+=1ll*dp[i-1][j-l]*k[l]%MOD*rfact[l]%MOD)%=MOD;
			}
		}
	}
	rb(i,1,n){
		rb(j,1,n){
			if(i-1+j==n) (ans[j]+=dp[i][j])%=MOD;
		}
	}
	int rest=0;
	rb(i,1,n){
		(rest+=1ll*ans[i]*fact[i]%MOD)%=MOD;
	}
	cout<<rest<<endl;
	return 0;
}