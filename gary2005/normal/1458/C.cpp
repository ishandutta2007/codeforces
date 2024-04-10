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
int n,m;
int ret[1001][1001];
int shift[3];
int v[1000000+1][3];
int mod(int val){
	val%=n;
	val+=n;
	if(val>n) val-=n;
	return val;
}
void solve(){
	scanf("%d%d",&n,&m);
	int is[3];
	rb(i,0,2) is[i]=i;
	rb(i,1,n)
		rb(j,1,n) {
			int ai;
			scanf("%d",&ai);
			v[(i-1)*n+j][0]=i;
			v[(i-1)*n+j][1]=j;
			v[(i-1)*n+j][2]=ai;	
		}
	memset(shift,0,sizeof(shift));
	rb(i,1,m){
		char c;
		cin>>c;
		if(c=='R') shift[1]++;
		if(c=='L') shift[1]--;
		if(c=='U') shift[0]--;
		if(c=='D') shift[0]++;
		if(c=='I') swap(is[1],is[2]),swap(shift[1],shift[2]);
		if(c=='C') swap(is[0],is[2]),swap(shift[0],shift[2]);
	}
	rb(i,1,n*n){
		int old[3];
		rep(j,3) old[j]=v[i][j];
		rep(j,3) v[i][j]=mod(old[is[j]]+shift[j]);
		ret[v[i][0]][v[i][1]]=v[i][2];
	}
	rb(i,1,n){
		rb(j,1,n){
			printf("%d ",ret[i][j]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}