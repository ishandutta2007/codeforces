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
const int MAXN=1e5+233;
int a[MAXN],n,m,b[MAXN],dp[MAXN],pos[MAXN],pre[MAXN];
vector<int> u;
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i+1]);
	a[1]=0;
	a[n+2]=1e9+3;
	n+=2;
	scanf("%d",&m);
	rb(i,1,m) scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	memset(dp,63,sizeof(dp));
	dp[1]=0;
	pos[1]=1;
	rb(i,2,n){
		if(a[i]!=-1){
			int l=1,r=n+3;
			while(l<r){
				int mid=(l+r)>>1;
				if(dp[mid]<a[i]) l=mid+1;
				else r=mid;
			}
			pre[i]=pos[l-1];
			pos[l]=i;
			dp[l]=a[i];
		}
		else{
			int pt=n+3;
			rl(j,m,1){
				while(dp[pt-1]>=b[j]) --pt;
				dp[pt]=b[j];
				pos[pt]=pos[pt-1];
			}
		}
	}
	int r=n,l=pre[n];
	int pt=m;
	rl(i,n-1,2){
		if(i==l){
			r=i;
			l=pre[i];
		}
		if(a[i]==-1){
			while(pt>=1&&b[pt]>=a[r]) u.PB(b[pt]),--pt;
			if(b[pt]>a[l]){
				a[i]=b[pt];
				--pt;
				while(pt>=1&&b[pt]==a[i]) u.PB(b[pt]),--pt;
			}
		}
	}
	rb(i,2,n-1){
		if(a[i]==-1) a[i]=u.back(),u.POB();
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}