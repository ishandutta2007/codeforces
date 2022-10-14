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
int ans[22][22];
bool check(int x,int y){
	rb(i,-1,1) rb(j,-1,1) if(i!=0||j!=0) if(ans[i+x][j+y]) return 0;
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(ans,0,sizeof(ans));
		rb(i,1,m) ans[1][i]=check(1,i);
		rb(i,1,n) ans[i][m]=check(i,m);
		rl(i,m,1) ans[n][i]=check(n,i);
		rl(i,n,1) ans[i][1]=check(i,1);
		rb(i,1,n){
			rb(j,1,m){
				printf("%d",ans[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}