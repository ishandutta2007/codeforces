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
struct Myhash{
	size_t operator ()(const vector<int> & v) const{
		unsigned int val=0;
		for(auto it:v){
			val^=it;
			val^=val<<13;
			val^=val>>7;
			val^=val<<17;
		}
		return val;
	}
};
int n,m;
unordered_map<vector<int>,int,Myhash> M;
vector<vector<int> > tot;
vector<int> Now;
const int MAXN=6;
int a[MAXN],b[MAXN],c[MAXN][MAXN];
void dfs(){
	if(Now.size()==m){
		M[Now]=tot.size();
		tot.PB(Now);
		return ;
	}
	int j=Now.size();
	rb(i,0,b[j]){
		Now.PB(i);
		dfs();
		Now.POB();
	}
}
int dp[MAXN+1][4][15625];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);
	rep(i,n) rep(j,m) scanf("%d",&c[i][j]);
	dfs();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
//	cout<<tot.size()<<endl;
	rep(i,n){
		rep(j,a[i]){
			rep(k,tot.size()){
				if(dp[i][j][k]!=INF){
					vector<int> is=tot[k];
					rep(l,m){
						rb(pt,1,min(a[i]-j,b[l]-is[l])){
							vector<int> Tmp=is;
							Tmp[l]+=pt;
							if(j+pt==a[i]){
								check_min(dp[i+1][0][M[Tmp]],dp[i][j][k]+c[i][l]);
							}
							else{
								check_min(dp[i][j+pt][M[Tmp]],dp[i][j][k]+c[i][l]);
							}
						}
					}
				}
			}
		}
	}
	int rest=INF;
	rep(i,tot.size()) check_min(rest,dp[n][0][i]);
	if(rest==INF) rest=-1;
	printf("%d\n",rest);
	return 0;
}