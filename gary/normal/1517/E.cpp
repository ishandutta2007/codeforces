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
int n;
int a[MAXN];
LL sum=0;
LL prefix[MAXN];
LL prefix2[MAXN][2];
int rest=0;
void solve(int st){
	if(st+2<=n&&(a[st]+prefix[n]-prefix[st+1])*2>sum){
		int l=1,r=n;
		while(l<r-1){
			int mid=(l+r)>>1;
			bool ok=0;
			if(2*mid+st>n);
			else{
				int R,L;
				R=2*mid+st;
				L=st;
				ok=(prefix2[R][R&1]-prefix2[L-1][R&1]+prefix[n]-prefix[R])*2>sum;
			}
			if(ok) l=mid;
			else r=mid;
		}
		(rest+=l)%=MOD;
	}
	if(st+2<=n-1&&(a[st]+prefix[n-1]-prefix[st+1])*2>sum){
		int l=1,r=n;
		while(l<r-1){
			int mid=(l+r)>>1;
			bool ok=0;
			if(2*mid+st>n-1);
			else{
				int R,L;
				R=2*mid+st;
				L=st;
				ok=(prefix2[R][R&1]-prefix2[L-1][R&1]+prefix[n-1]-prefix[R])*2>sum;
			}
			if(ok) l=mid;
			else r=mid;
		}
		(rest+=l)%=MOD;
	}
}
void solve2(){
	rb(i,4,n){
		if((prefix[n]-prefix[i-1]+a[1])*2<=sum) break;
		int l=0,r=n;
		while(l<r-1){
			int mid=(l+r)>>1;
			bool ok=0;
			if(2*mid+i>n);
			else{
				int R,L;
				R=2*mid+i;
				L=i;
				ok=(prefix2[R][R&1]-prefix2[L-1][R&1]+a[1]+prefix[n]-prefix[R])*2>sum;
			}
			if(ok) l=mid;
			else r=mid;
		}
		(rest+=l+1)%=MOD;
	}
}
void solve3(){
	rb(i,4,n-1){
		if((prefix[n-1]-prefix[i-1]+a[1])*2<=sum) break;
		int l=0,r=n;
		while(l<r-1){
			int mid=(l+r)>>1;
			bool ok=0;
			if(2*mid+i>n-1);
			else{
				int R,L;
				R=2*mid+i;
				L=i;
				ok=(prefix2[R][R&1]-prefix2[L-1][R&1]+a[1]+prefix[n-1]-prefix[R])*2>sum;
			}
			if(ok) l=mid;
			else r=mid;
		}
		(rest+=l+1)%=MOD;
	}
}
void solve(){
	rest=0;
	sum=0;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]),sum+=a[i],prefix[i]=prefix[i-1]+a[i],prefix2[i][0]=prefix2[i-1][0],prefix2[i][1]=prefix2[i-1][1],prefix2[i][i&1]+=a[i];
	if(n==1){
		puts("1");
		return;
	}
	rb(i,1,n) if(prefix[i]*2>sum) rest++;
	rb(i,1,n) rest+=(sum-prefix[i])*2>sum,rest+=(prefix[n-1]-prefix[i])*2>sum;
	rb(i,1,n) solve(i);
	solve2();
	solve3();
	printf("%d\n",rest);
}
int main(){
	//2*sumb>sum
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}