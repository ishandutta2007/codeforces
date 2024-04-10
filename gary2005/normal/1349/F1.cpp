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
const int MAXN=5005;
const int MOD=998244353;
int n,s[MAXN][MAXN],val[MAXN],fact[MAXN],inv[MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int main(){
	cin>>n;
	s[0][0]=1;
	fact[0]=1;
	rb(i,1,n) fact[i]=1ll*fact[i-1]*i%MOD;
	inv[n]=quick(fact[n],MOD-2);
	rl(i,n-1,0) inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	rb(i,1,n) rb(j,1,n) s[i][j]=(1ll*s[i-1][j]*j%MOD+s[i-1][j-1])%MOD;
//	rb(i,1,n){
//		rb(j,1,n){
//			cout<<s[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	rb(y,0,n-1){
		rb(x,y+1,n){
			val[y]+=1ll*s[x][x-y]*fact[x-y]%MOD*inv[x]%MOD; 
			val[y]%=MOD;
		}
	}
	rb(i,1,n){	
		int ans=0;
		rb(y,i-1,n-1){
			if((y-i+1)&1){
				ans-=1ll*fact[y]*val[y]%MOD*inv[y-i+1]%MOD;
				ans+=MOD;
				ans%=MOD;
			}
			else{
				ans+=1ll*fact[y]*val[y]%MOD*inv[y-i+1]%MOD;
				ans%=MOD;
			}
		}
		ans=1ll*ans*fact[n]%MOD;
		ans=1ll*ans*inv[i-1]%MOD;
		printf("%d ",ans);
	}
	return 0;
}