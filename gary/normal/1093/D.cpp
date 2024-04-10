//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[300000+10];
int mark[300000+10];
int res=0;
int res_flag=0;
const int MOD=998244353;
int coun_t;
void dfs(int now,int ty){
	// color 1 or 0
	if(res_flag) return;
	if(mark[now]==ty+1){
		return ;
	}
	else{
		if(mark[now]){
			res=0;
			res_flag=1;
			return;
		}
	}
	mark[now]=ty+1;
	if(ty==1) res++;
	coun_t++;
	int SZ=each[now].size();
	rep(i,SZ){
		int nex=each[now][i];
		dfs(nex,ty^1);
	}
}
void solve(){
	res=res_flag=0;
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n) each[i].clear(),mark[i]=0;
	rep(i,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		each[ui].PB(vi);
		each[vi].PB(ui);
	}
	LL final=1;
	rb(i,1,n){
		if(each[i].size()==0){
			final*=3;
			final%=MOD;	
		}
		else{
			if(!mark[i]){
				res=0;
				coun_t=0;
				dfs(i,1);
				if(res_flag){
					puts("0");
					return ;
				}
				int res1,res2;
				res1=res;
				res2=coun_t-res;
				LL tmp1=final;
				LL tmp2=final;
				rb(i,1,res1){
					tmp1<<=1;
					tmp1%=MOD;
				}
				rb(i,1,res2){
					tmp2<<=1;
					tmp2%=MOD;
				}
				final=tmp1+tmp2;
				final%=MOD;
			}
		}
	}
	printf("%I64d\n",final);
}
int main(){
	
//	FREO;
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}