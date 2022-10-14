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
int n,a[2002];
bool dp[2002];
unordered_map<int,vector<mp> > M;
void solve(){
	memset(dp,0,sizeof(dp));
	M.clear();
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		int tmp=0;
		rb(j,i,n){
			if((j-i+1)==n) continue;
			tmp^=a[j];
			if(i==1||M.find(tmp)!=M.end())
				M[tmp].PB(II(i,j));
		}
	}
	for(auto ite=M.begin();ite!=M.end();ite++){
		dp[0]=1;
		for(auto it:ite->SEC){
			dp[it.SEC]|=dp[it.FIR-1];
		}
		if(dp[n]){
			puts("YES");
			return ;
		}
		for(auto it:ite->SEC) dp[it.SEC]=0;
	}
	puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}