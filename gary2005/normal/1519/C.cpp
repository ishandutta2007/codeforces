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
const int MAXN=2e5+233;
int n;
vector<int> fac[MAXN];
vector<int> have[MAXN];
int u[MAXN],s[MAXN];
LL rest[MAXN];
LL cf[MAXN];
void solve(){
	scanf("%d",&n);
	rb(i,1,n) rest[i]=0,cf[i]=0,have[i].clear();
	rb(i,1,n) scanf("%d",&u[i]);
	LL sum=0;
	rb(i,1,n) scanf("%d",&s[i]),sum+=s[i];
	rb(i,1,n) have[u[i]].PB(s[i]);
	rb(i,1,n){
		if(have[i].empty()) continue;
		sort(ALL(have[i]));
		LL tmp=0;
		rb(j,1,have[i].size()-1){
			tmp+=have[i][j-1];
			auto ite=upper_bound(ALL(fac[have[i].size()-j]),j);
			while(ite!=fac[have[i].size()-j].end()){
				rest[*ite]+=tmp;
				ite++;
			}
		}
		tmp+=have[i].back();
		cf[have[i].size()+1]+=tmp;
	}
	rb(i,1,n){
		cf[i]+=cf[i-1];
		rest[i]+=cf[i];
		printf("%lld ",sum-rest[i]);
	}
	puts("");
}
int main(){
	rb(i,1,MAXN){
		for(int j=1;j*j<=i;++j){
			if(i%j==0){
				fac[i].PB(j);
				if(i/j!=j)
				fac[i].PB(i/j);
			}
		}
		sort(ALL(fac[i]));
	}
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}