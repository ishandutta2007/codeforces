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
int n,m,i,j;
LL solve(int x,int y,int X,int Y){
	return 1ll*abs(x-X)+abs(Y-y)+abs(x-i)+abs(y-j)+abs(X-i)+abs(Y-j);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&i,&j);
		LL x=1,y=1,X=1,Y=1;
		if(solve(1,1,1,m)>solve(x,y,X,Y)) x=1,y=1,X=1,Y=m;
		if(solve(1,1,n,1)>solve(x,y,X,Y)) x=1,y=1,X=n,Y=1;
		if(solve(n,m,1,m)>solve(x,y,X,Y)) x=n,y=m,X=1,Y=m;
		if(solve(n,m,n,1)>solve(x,y,X,Y)) x=n,y=m,X=n,Y=1;
		if(solve(1,m,n,1)>solve(x,y,X,Y)) x=1,y=m,X=n,Y=1;
		cout<<x<<" "<<y<<" "<<X<<' '<<Y<<endl;
	}
	return 0;
}