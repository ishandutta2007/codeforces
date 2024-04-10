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
int gt[10000000+233];
bool vis[10000000+233];
int a[200000+233];
int dp[200000+233][21];
int pre[10000000+233];
void solve(){
	int k;
	scanf("%d%d",&n,&k);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	rb(i,1,n){
		a[i]=gt[a[i]];
		pre[a[i]]=0;
	}
	set<int,greater<int > > ok;
	rb(i,1,n) rb(j,0,k) dp[i][j]=INF; 
	dp[0][0]=0;
	ok.insert(0);
	rb(i,1,n){
		if(pre[a[i]]){
			ok.insert(pre[a[i]]);
		}
		pre[a[i]]=i;
		rb(j,0,k){
			auto now=ok.begin();
			rb(z,0,j){
				check_min(dp[i][j],dp[*now][j-z]+1);
				if(*now==0) break;
				now=next(now);
			}
		}
	}
	int ret=INF;
	rb(j,0,k) check_min(ret,dp[n][j]);
	check_max(ret,1);
	printf("%d\n",ret);
}
int main(){
	gt[1]=1;
	rb(i,2,10000000){
		if(!vis[i]){
			gt[i]=i;
			for(int j=i+i;j<=10000000;j+=i){
				vis[j]=1;
				int cnt=0;
				int now=j;
				while(now%i==0){
					cnt++;
					now/=i;
				}
				if(cnt&1) gt[j]=gt[now]*i;
				else gt[j]=gt[now];
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}