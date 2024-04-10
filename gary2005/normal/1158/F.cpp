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
const int MOD=998244353;
const int MAXN=6003;
int n,c;
int a[MAXN],dp[MAXN][MAXN/2],pre[MAXN],pre2[MAXN],cnt[MAXN],inv[MAXN],dp2[2][3003][1<<10],vis[2][3003][1<<10],preval[6003][6003];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
void add(int & A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
void solve1(){
	rb(i,1,n) a[i]--;
	dp2[1][0][0]=1;
	vis[1][0][0]=1;
	rb(i,1,n){
		rb(j,0,i/c){
			rep(mask,1<<c){
				if(vis[i&1][j][mask]==i){
					bool nex=(i&1)^1;
					if(vis[nex][j][mask]!=i+1){
						vis[nex][j][mask]=i+1;
						dp2[nex][j][mask]=0;
					}
					int nxmask=mask|(1<<a[i]);
					int nj=0;
					if(nxmask==(1<<c)-1) nxmask=0,nj=1;
					if(vis[nex][j+nj][nxmask]!=i+1){
						vis[nex][j+nj][nxmask]=i+1;
						dp2[nex][j+nj][nxmask]=0;
					}
					add(dp2[nex][j][mask],dp2[i&1][j][mask]);
					add(dp2[nex][j+nj][nxmask],dp2[i&1][j][mask]);
				}
			}
		}
	}
	rb(i,0,n){
		int rest=0;
		rep(mask,1<<c){
			add(rest,dp2[(n&1)^1][i][mask]);
		}
		if(i==0) add(rest,MOD-1);
		printf("%d ",rest);
	}
}
int main(){
//	cerr<<(sizeof(dp)+sizeof(pre)+sizeof(dp2)+sizeof(vis)+sizeof(preval))/1024/1024<<endl;
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout); 
	scanf("%d%d",&n,&c);
	rb(i,0,n+c) pre[i]=quick(2,i)-1,pre2[i]=quick(2,i),inv[i]=quick(pre[i],MOD-2);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,c) a[i+n]=i;
	if(c<=10){
		solve1();
		return 0;
	}
	dp[0][0]=1;
	rb(i,1,n+c){
		rb(j,1,c){
			cnt[j]=0;
		}
		int val=0;
		int cnt_zero=c;
		rl(j,i,1){
			cnt[a[j]]++;
				if(cnt[a[j]]==1){
					cnt_zero--;
				}
				if(val){
					if(a[j]!=a[i]){
						if(i>=n+a[j]){
							if(cnt[a[j]]!=1) val=val<<1;
							if(val>=MOD) val-=MOD;
						}
						else{
							if(cnt[a[j]]!=1) val=1ll*val*inv[cnt[a[j]]-1]%MOD;
							val=1ll*pre[cnt[a[j]]]*val%MOD;
						}
					}
				}
				else{
					if(cnt_zero==0){
						cnt_zero=INF;
						val=1;
						rb(l,1,c){
							if(l==a[i]);
							else{
								if(i>=n+l){
									val=1ll*val*pre2[cnt[l]-1]%MOD;
								}
								else{
									val=1ll*val*pre[cnt[l]]%MOD;
								}
							}
						}
					}
				}
			preval[j][i]=val;
		}
	}
	rb(j,0,n+c-1){
		rb(k,0,j/c){
			if(dp[j][k])
				rb(i,j+1,n+c){
					add(dp[i][k+1],1ll*preval[j+1][i]*dp[j][k]%MOD);
				}
		}
	}
	rb(i,0,n){
		int rest=0;
		rb(j,n+1,n+c){
			add(rest,dp[j][i+1]);
		}
		if(i==0) add(rest,MOD-1);
		printf("%d ",rest);
	}
	return 0;
}
/*

4 4
1 2 3 4 


9 3
1 2 3 1 2 3 1 2 3 


*/