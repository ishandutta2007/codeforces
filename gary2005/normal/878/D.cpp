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
int n,k,q;
pair<int,mp> ope[100000+233];
int cnt=0;
bitset< 1<<12 > is[100000+233];
bitset< 1<<12 > ans[100001];
int p[13][100000+2333];
int belong[100000+23];
void solve(){
	rb(i,1,k) rep(mask,1<<k) is[i][mask]=(mask>>(i-1))&1;
	rb(i,1,q){
		if(ope[i].FIR==1){
			is[belong[i]]=is[ope[i].SEC.FIR]|is[ope[i].SEC.SEC];	
		}
		if(ope[i].FIR==2){
			is[belong[i]]=is[ope[i].SEC.FIR]&is[ope[i].SEC.SEC];
		}
		if(ope[i].FIR==3){
			ans[i]=is[ope[i].SEC.FIR];
		}
	}
}
int rnk[100000+233][13];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	rb(i,1,k)
	rb(j,1,n) scanf("%d",&p[i][j]);
	rb(i,1,n){
		vector<mp> v;
		rb(j,1,k){
			v.PB({p[j][i],j});
		}
		sort(ALL(v));
		rb(j,1,k){
			rnk[i][j]=v[j-1].SEC;
		}
	}
	cnt=k;
	rb(i,1,q){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a<=2) belong[i]=++cnt;
		ope[i]=(II(a,II(b,c)));
	} 
	solve();
	cnt=0;
	rb(i,1,q){
		if(ope[i].FIR==3){
			int pre=-1;
			int mask=0;
			rl(j,k,0){
				if(ans[i][mask]){
					printf("%d\n",pre);
					break;
				}
				pre=p[rnk[ope[i].SEC.SEC][j]][ope[i].SEC.SEC];
				mask^=1<<(rnk[ope[i].SEC.SEC][j]-1);
			}
		}
	}
	return 0;
}