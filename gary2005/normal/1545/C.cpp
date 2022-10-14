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
const int MAXN=505;
int t,n,a[MAXN<<1][MAXN];
bool era[MAXN<<1],cho[MAXN<<1];
int cnt[MAXN][MAXN];
int fa[MAXN<<1];
int root(int x){
	return fa[x]=(x==fa[x]? x:root(fa[x]));
}
vector<int> g[MAXN<<1];
bool col[MAXN<<1];
bool vis[MAXN<<1];
void dfs(int now){
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it]){
			col[it]=col[now]^1;
			dfs(it);
		}
	}
}
void solve(){
	scanf("%d",&n);
	rb(i,1,n*2) rb(j,1,n) scanf("%d",&a[i][j]);
	memset(era,0,sizeof(era));
	memset(vis,0,sizeof(vis));
	memset(cho,0,sizeof(cho));
	memset(cnt,0,sizeof(cnt));
	memset(col,0,sizeof(col));
	rb(i,1,n*2) rb(j,1,n) cnt[j][a[i][j]]++;
	rb(T,1,n){
		mp Tmp=II(-1,-1);
		rb(j,1,n){
			rb(k,1,n) if(cnt[j][k]==1){
				Tmp=II(j,k);
				break;
			}
			if(Tmp.FIR!=-1) break;
		}
		if(Tmp.FIR==-1) break;
		int x;
		rb(j,1,2*n){
			if(!era[j]&&a[j][Tmp.FIR]==Tmp.SEC){
				x=j;
				break;
			}
		}
		cho[x]=1;
		rb(j,1,2*n) if(!era[j]&&j!=x){
			rb(k,1,n) if(j!=x&&a[j][k]==a[x][k]) era[j]=1;
			if(era[j]){
				rb(k,1,n) cnt[k][a[j][k]]--;
			}
		}
		rb(k,1,n) cnt[k][a[x][k]]--;
	}
	rb(i,1,n*2) g[i].clear(),fa[i]=i;
	rb(i,1,n*2) era[i]|=cho[i];
	rb(i,1,n*2) if(!era[i]) rb(j,i+1,n*2) if(!era[j]) {
		bool E=0;
		rb(k,1,n) if(a[i][k]==a[j][k]){
			E=1;
			break;
		}
		if(E){
			g[i].PB(j);
			g[j].PB(i);
			fa[root(i)]=root(j);
		}
	}
	rb(i,1,n*2) if(!era[i]&&!vis[i]) dfs(i);
	int ans=1;
	vector<int> res;
	rb(i,1,n*2){
		if(!era[i]&&col[i]==0){
			res.PB(i);
		}
	}
	rb(i,1,n*2) if(!era[i]&&root(i)==i) ans=(ans+ans)%998244353;
	rb(i,1,2*n) if(cho[i]) res.PB(i);
	printf("%d\n",ans);
	for(auto it:res){
		printf("%d ",it);
	}
	puts("");
}
int main(){
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}