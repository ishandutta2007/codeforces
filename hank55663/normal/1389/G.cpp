#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
vector<vector<int> > v;
int vis[300005],lwn[300005];
vector<int> stk;
int f[300005];
int bln[300005];
int Find(int a){
	if(bln[a]==a)return a;
	return bln[a]=Find(bln[a]);
}
int t;
void dfs(int a,int p){
	stk.pb(a);
	bln[a]=a;
	vis[a]=lwn[a]=++t;
	int cnt=0;
	for(int i=0;i<v[a].size();i++){
		int x=v[a][i];
		if(x!=p||cnt==1){
			if(vis[x]==0){
				dfs(x,a);
				if(lwn[x]>vis[a]){
					int fa=Find(x);
					f[x]=Find(a);
					while(stk.back()!=x){
						bln[stk.back()]=fa;
						stk.pop_back();
					}
					bln[stk.back()]=fa;
					stk.pop_back();
				}
				lwn[a]=min(lwn[a],lwn[x]);
			}
			else{
				lwn[a]=min(lwn[a],vis[x]);
			}
		}
		else{
			cnt++;
		}
	}
}

int c[300005];
int w[300005];


vector<pii> v2[300005];
LL val[300005];
LL dp[300005];
int need[300005];
int ori[300005];
int k;
void dfs2(int x,int f){
    dp[x]=val[x];
    ori[x]=need[x];
    for(auto it:v2[x]){
        if(it.x!=f){
            dfs2(it.x,x);
            if(need[it.x]==0)dp[x]+=dp[it.x];
            else if(need[it.x]==k){
                dp[x]+=dp[it.x];
            }
            else{
                dp[x]+=max(dp[it.x]-it.y,0ll);
            }
           // printf("? %d %d\n",it.x,need[it.x]);
        }
    }
    for(auto it:v2[x]){
        if(it.x!=f){
            need[x]+=need[it.x];
        }
    }
  //  printf("%d %d\n",x,dp[x]);
}
void dfs3(int x,int f,LL sum, LL edgeval){
    if(need[x]==0||need[x]==k)dp[x]+=sum;
    else dp[x]+=max(0ll,sum-edgeval);
    for(auto it:v2[x]){
        if(it.x!=f){
            if(need[it.x]==0)dfs3(it.x,x,dp[x]-dp[it.x],it.y);
            else if(need[it.x]==k){
                dfs3(it.x,x,dp[x]-dp[it.x],it.y);
            }
            else{
                dfs3(it.x,x,dp[x]-max(dp[it.x]-it.y,0ll),it.y);
            }
        }
    }
  //  printf("%d %lld %lld\n",x,sum,edgeval);

}
int main(){
    int n,m;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> mark;
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        mark.pb(x);
    }
    for(int i = 1;i<=n;i++)scanf("%d",&c[i]);
    v.resize(n+1);
    for(int i = 0;i<m;i++){
        scanf("%d",&w[i]);
    }
    pii edge[300005];
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        edge[i]=mp(x,y);
    }
    dfs(1,0);
    while(!stk.empty()){
        bln[Find(stk.back())]=1;
        stk.pop_back();
    }
    for(int i = 0;i<m;i++){
        if(Find(edge[i].x)!=Find(edge[i].y)){
            v2[Find(edge[i].x)].pb(mp(Find(edge[i].y),w[i]));
            v2[Find(edge[i].y)].pb(mp(Find(edge[i].x),w[i]));
        }
    }
    for(int i = 1;i<=n;i++){
        val[Find(i)]+=c[i];
    }
    for(auto it:mark){
        need[Find(it)]++;
    }
    dfs2(1,0);
    dfs3(1,0,0,0);
    for(int i = 1;i<=n;i++){
        printf("%lld ",dp[Find(i)]);
    }
    printf("\n");
}