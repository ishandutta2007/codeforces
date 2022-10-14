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
int ans[505][505];
void solve(int n){
	if(n==1) return ;
	bool ok=0;
	rb(i,1,n){
		if(ans[i][n-i+1]==1){
			ok=1;
			continue;
		}
		if(!ok){
			ans[i][n-i+1-1]=ans[i][n-i+1]-1;
		}
		else{
			ans[i-1][n-i+1]=ans[i][n-i+1]-1;
		}
	}
	solve(n-1);
}
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&ans[i][n-i+1]);
	solve(n);
	rl(j,n,1){
		rb(i,1,n-j+1){
			printf("%d ",ans[i][j]+(n-i+1)-j);
		}
		puts("");
	} 
	return 0;
}