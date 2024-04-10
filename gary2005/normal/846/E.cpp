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
int n;
LL a[100000+20],b[100000+20];
LL rest[100000+20];
vector<pair<int,LL> > g[100000+20];
LL tot=0;
void run(int now){
	rest[now]=a[now]-b[now];
	for(auto it:g[now]){
		run(it.FIR);
		if(rest[it.FIR]<0){
			rest[now]+=rest[it.FIR]*it.SEC;
			if(rest[now]<-tot){
				printf("NO\n");
				exit(0);
			}
			rest[it.FIR]=0;
		}
		rest[now]+=rest[it.FIR];
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%lld",&a[i]),tot+=a[i];
	rb(i,1,n) scanf("%lld",&b[i]);
	rb(i,2,n){
		int x,k;
		scanf("%d%d",&x,&k);
		g[x].PB(II(i,k));
	}
	run(1);
	puts(rest[1]>=0? "YES":"NO");
	return 0;
}