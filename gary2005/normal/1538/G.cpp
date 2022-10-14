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
LL x,y,a,b;
LL check(LL i){
	if(i<0) return -INF;
	LL rx,ry;
	rx=1ll*x-1ll*i*a;
	ry=1ll*y-1ll*i*b;
	if(rx<0||ry<0) return -INF;
	return i+min(rx/b,ry/a);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if(a==b){
			printf("%lld\n",min(x,y)/b);
			continue;
		}
		double k1,b1,k2,b2;
		k1=-1.0*a/b;
		b1=1.0*x/b;
		k2=-1.0*b/a;
		b2=1.0*y/a;
		double X=(b1-b2)/(k2-k1);
		LL ans=0;
		check_max(ans,min(x/a,y/b));
		check_max(ans,min(y/a,x/b));
		rb(i,-10,10){
			check_max(ans,check(llround(X-i)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}