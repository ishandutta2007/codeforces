/**
 *    author:  gary
 *    created: 17.10.2021 19:02:45
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=3e5+1;
int n,m;
vector<int> g[MAXN];
vector<int> tree[MAXN];
int a[MAXN],b[MAXN];
bool vis[MAXN];
void addedge(int u,int v){
    tree[u].PB(v);
    tree[v].PB(u);
}
void dfs(int now){
    vis[now]=1;
    for(auto it:g[now]) if(!vis[it]) addedge(it,now),dfs(it);
}
int col[MAXN];
void dfs2(int now,int pre){
    for(auto it:tree[now]){
        if(it!=pre){
            dfs2(it,now);
            col[now]^=col[it];
        }
    }
}
vector<int> path;
bool dfs3(int now,int pre,int to){
    path.PB(now);
    if(now==to){
        printf("%d\n",path.size());
        for(auto it:path){
            printf("%d ",it);
        }
        printf("\n");
        return true;
    }
    for(auto it:tree[now]) if(it!=pre){
        if(dfs3(it,now,to)) true;
    }
    path.POB();
    return false;
}
int ans=0;
void dfs4(int now,int pre){
    int Tmp=col[now];
    ans+=Tmp;
    for(auto it:tree[now]){
        if(it!=pre){
            dfs4(it,now);
            if(Tmp==1&&col[it]==1){
                ans--;
            }
            Tmp^=col[it];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1);
    int q;
    scanf("%d",&q);
    rb(i,1,q){
        scanf("%d%d",&a[i],&b[i]);
        col[a[i]]^=1;
        col[b[i]]^=1;
    }
    dfs2(1,0);
    if(*max_element(col+1,col+1+n)==0){
        puts("YES");
        rb(i,1,q){
            path.clear();
            dfs3(a[i],0,b[i]);
        }
        return 0;
    }
    puts("NO");
    dfs4(1,0);
    cout<<ans<<endl;
    return 0;
}