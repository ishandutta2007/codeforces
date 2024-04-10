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
int n,m;
int lowbit[1048576+10];
int many[1048576+10];
int upp;
LL dp[1048576+10][20];
int eg[20][20];
LL res=0;
int main(){
	scanf("%d %d",&n,&m);
	upp=(1<<(n))-1;
	rep(i,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		eg[ui][vi]=eg[vi][ui]=1;
	}
	rb(i,0,upp){
		int j=0;
		int now=i;
		while(now){
			j++;
			if(now&1){
				lowbit[i]=j;
				break;
			}
			now>>=1;
		}
		now=i;
		j=0;
		while(now){
			if(now&1){
				j++;
			}
			now>>=1;
		}
		many[i]=j;
	}
	rb(i,1,n){
		dp[(1)<<(i-1)][i]=(LL)(1);
	}
	rb(mask,1,upp){
		rb(i,1,n){
			if(dp[mask][i]>0){
				rb(j,lowbit[mask]+1,n){
					if((mask&(1<<(j-1)))==0&&eg[i][j]){
						dp[mask|(1<<(j-1))][j]+=dp[mask][i];
					}
				}
			}
		}
	}
	rb(mask,1,upp){
		rb(i,1,n){
				if(many[mask]>=3)
				if(eg[lowbit[mask]][i]){ 
					res+=dp[mask][i];
				}
		}
	}
	printf("%I64d\n",res>>1);
	return 0;
}