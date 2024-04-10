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
const int MAXN=1e5+1;
int dp[MAXN][2];
vector<int> pos[26][2];
int main(){
	int q;
	cin>>q;
	while(q--){
		string s,t;
		cin>>s>>t;
		int n,m;
		n=s.length();
		m=t.length();
		rep(c,26) rep(j,2) pos[c][j].clear();
		rep(i,n) pos[s[i]-'a'][i&1].PB(i);
		rep(c,26) rep(j,2) pos[c][j].PB(INF);
		rb(i,1,m){
			int c=t[i-1]-'a';
			rep(t,2){
				dp[i][t]=*lower_bound(ALL(pos[c][t]),dp[i-1][t^1]);
			}
		}
		puts(dp[m][(n&1)^1]!=INF? "YES":"NO");
	}
	return 0;
}