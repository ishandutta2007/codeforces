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
vector<int> v1,v2;
int n,a[5005];
int dp[5005][5005];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) if(a[i]==0) v1.PB(i);else v2.PB(i);
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	rb(i,0,v1.size()-1)
		rb(j,0,v2.size()){
			if(dp[i][j]!=INF){
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				check_min(dp[i+1][j],dp[i][j]);
				if(j!=v2.size()) check_min(dp[i+1][j+1],dp[i][j]+abs(v2[j]-v1[i]));
			}
		}
	cout<<dp[v1.size()][v2.size()]<<endl;
	return 0;
}