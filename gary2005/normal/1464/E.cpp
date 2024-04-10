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
const int MAXN=1e5+20;
int sg[MAXN];
vector<int> g[MAXN];
int n,m;
bool vis[MAXN];
void dfs(int now){
	vis[now]=1;
	for(auto it:g[now]) if(!vis[it]) dfs(it);
	vector<int> sgg;
	for(auto it:g[now]) sgg.PB(sg[it]);
	sort(ALL(sgg));
	sgg.erase(unique(ALL(sgg)),sgg.end());
	sg[now]=-1;
	rep(i,sgg.size()){
		if(sgg[i]!=i){
			sg[now]=i;
			break;
		}
	}
	if(sg[now]==-1) sg[now]=sgg.size();
}
const int MAQ=511;
const int MOD=998244353 ;
int mat[MAQ+1][MAQ+10];
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
LL pro;
void gauss(){
	rb(i,0,MAQ){
		int is=-1;
		rb(j,i,MAQ){
			if(mat[j][i]){
				is=j;
				break;
			}
		}
		if(is==-1) continue;
		swap(mat[i],mat[is]);
		int inv=quick(mat[i][i],MOD-2);
		rb(j,0,MAQ+1) mat[i][j]=1ll*mat[i][j]*inv%MOD;
		rb(j,0,MAQ){
			if(j!=i)
				if(mat[j][i]){
					rb(k,0,MAQ+1){
						if(k!=i)
							mat[j][k]-=1ll*mat[j][i]*mat[i][k]%MOD,mat[j][k]+=MOD,mat[j][k]%=MOD;
					}
					mat[j][i]=0;
				}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
	}
	pro=quick(n+1,MOD-2);
	rb(i,1,n) if(!vis[i]) dfs(i);
	rb(i,0,MAQ){
		mat[i][i]=1;
		rb(j,1,n){
			mat[i][i^sg[j]]+=(MOD-pro);
			mat[i][i^sg[j]]%=MOD;
		}
		mat[i][MAQ+1]=pro*(i==0);
	}
	gauss();
	int res=1-mat[0][MAQ+1]+MOD;
	res%=MOD;
	printf("%d\n",res);
	return 0;
}