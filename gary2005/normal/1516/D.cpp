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
const int MAXN=1e5+233;
int n,q;
int jmp[MAXN][17];
vector<int> divd[MAXN];
vector<int> p[MAXN];
vector<int> pos[MAXN];
int main(){
	scanf("%d%d",&n,&q);
	rb(T,1,n){
		int ai;
		scanf("%d",&ai);
		for(int i=1;i*i<=ai;++i){
			if(ai%i==0){
				if(i!=1) divd[T].PB(i);
				if(ai/i!=1) divd[T].PB(ai/i);
			}
		}
		sort(ALL(divd[T]));
		for(auto it:divd[T]){
			if(ai%it==0){
				p[T].PB(it);
				pos[it].PB(T);
				while(ai%it==0){
					ai/=it;
				}
			}
		}
	}
	rb(i,1,100000) pos[i].PB(n+1);
	rb(i,1,n+1) rep(j,17) jmp[i][j]=n;
	rl(i,n,1){
		int R=n+1;
		for(auto it:p[i]){
			check_min(R,*upper_bound(ALL(pos[it]),i));
		}
		--R;
		if(i!=n) check_min(R,jmp[i+1][0]);
		jmp[i][0]=R;
	}
	rb(j,1,16) rb(i,1,n) jmp[i][j]=jmp[jmp[i][j-1]+1][j-1];
	rb(T,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		rl(i,16,0){
			if(jmp[l][i]<r){
				l=jmp[l][i]+1;
				ans|=1<<i;
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}