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
const int DELTA=1000000;
typedef bitset<2001000+1> BS;
int h,v,l[1001],p[1001];
vector<int> sz[2],sp[2];
BS dp[1001];
void construct(){
	bool rev=0;
	if(sp[0].size()<sz[0].size()){
		sp[0].swap(sz[0]);
		sp[1].swap(sz[1]);
		rev=1;
	}
	deque<mp> delta;
	while(sz[1].size()>sp[1].size()){
		delta.PB({0,-sz[1].back()});	
		delta.PB({sp[0].back(),0});
		sz[1].POB();
		sp[0].POB();
	}
	sort(ALL(sz[0]));
	reverse(ALL(sz[0]));
	sort(ALL(sp[0]));
	
	sort(ALL(sz[1]));
	reverse(ALL(sz[1]));
	sort(ALL(sp[1]));
	reverse(ALL(sz[0]));
	reverse(ALL(sp[0]));
	rep(i,sz[0].size()){
		delta.push_front({sp[0][i],0});
		delta.push_front({0,sz[0][i]});
	}
	
	rep(i,sz[1].size()){
		delta.PB({0,-sz[1][i]});
		delta.PB({-sp[1][i],0});
	}
	
	int x=0,y=0;
	for(auto dt:delta){
		x+=dt.FIR;
		y+=dt.SEC;
		if(rev){
			printf("%d %d\n",y,x);
		}
		else{
			printf("%d %d\n",x,y);
		}
	}
}
void solve(){
	rep(i,2) sz[i].clear(),sp[i].clear();
	rb(i,0,h) dp[i].reset();
	scanf("%d",&h);
	rb(i,1,h) scanf("%d",&l[i]);	
	scanf("%d",&v);
	rb(i,1,v) scanf("%d",&p[i]);
	if(h!=v){
		puts("No");
		return ;
	}
	dp[0].set(DELTA);
	rb(i,1,h){
		dp[i]=(dp[i-1]>>l[i])|(dp[i-1]<<l[i]);
	}
	if(!dp[h][DELTA]){
		puts("No");
		return ;
	}
	int j;
	j=DELTA;
	rl(i,h,1){
		if(dp[i-1][j+l[i]]){
			sp[1].PB(l[i]);
			j+=l[i];
		}
		else{
			sp[0].PB(l[i]);
			j-=l[i];
		}
	}
	rb(i,0,v) dp[i].reset();
	dp[0].set(DELTA);
	rb(i,1,v){
		dp[i]=(dp[i-1]>>p[i])|(dp[i-1]<<p[i]);
	}
	if(!dp[v][DELTA]){
		puts("No");
		return ;
	}
	j=DELTA;
	rl(i,v,1){
		if(dp[i-1][j+p[i]]){
			sz[1].PB(p[i]);
			j+=p[i];	
		}
		else{
			sz[0].PB(p[i]);
			j-=p[i];
		}
	}
	puts("Yes");
	construct();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();	
	return 0;
}