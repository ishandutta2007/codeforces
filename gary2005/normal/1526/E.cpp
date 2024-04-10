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
const int MAXN=2e5+233;
const int MOD=998244353;
int n,a[MAXN],pos[MAXN],fact[MAXN],ifact[MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int C(int A,int B){
	if(A<B) return 0;
	return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
int main(){
	fact[0]=1;
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	rb(i,1,n){
		int fk;
		scanf("%d",&fk);
		a[fk+1]=i;
	} 
	rb(i,1,n) pos[a[i]]=i;
	rb(i,1,max(n,k)) fact[i]=1ll*fact[i-1]*i%MOD;
	ifact[max(n,k)]=quick(fact[max(n,k)],MOD-2);
	rl(i,max(n,k)-1,0) ifact[i]=1ll*ifact[i+1]*(i+1)%MOD;
	int cnt=0;
	rb(i,2,n){
		cnt+=a[pos[i]+1]<a[pos[i-1]+1];
	}
	int ans=0;
	rb(i,1,k){
		if(i<=cnt) continue;
		(ans+=1ll*C(k,i)*C(n-1-cnt,i-1-cnt)%MOD)%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}