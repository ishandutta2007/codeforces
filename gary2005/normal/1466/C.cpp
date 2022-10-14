/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
int t;
int dp[2][2][2];
void solve(){
	string s;
	cin>>s;
	if(s.length()==1){
		cout<<0<<endl;
		return;
	}
	memset(dp[0],63,sizeof(dp[0]));
	dp[0][0][0]=0;
	int n=s.length();
	rb(i,1,n){
		memset(dp[i&1],63,sizeof(dp[i&1]));
		rep(j,2){
			rep(k,2){
				rep(l,2){
					if(!l){
						if(!j&&i-2>=1){
							if(s[i-1]==s[i-2-1]) continue;
						}
						if(!k&&i-1>=1){
							if(s[i-1]==s[i-1-1]) continue;
						}
					}
					check_min(dp[i&1][k][l],dp[(i&1)^1][j][k]+l); 
				}
			}
		}
	}
	int rest=INF;
	rep(i,2)rep(j,2) check_min(rest,dp[n&1][i][j]);
	printf("%d\n",rest);
}
int main(){
	cin>>t;
	while(t--) solve();
	return 0;
}