#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[100005];
int dis[100005];
pii dfs(int x,int f){
    pii res=mp(0,x);
    dis[x]=dis[f]+1;
    for(auto it:v[x]){
        if(it!=f){
            pii p=dfs(it,x);
            p.x++;
            if(p>res){
                res=p;
            }
        }
    }
    return res;
}
void solve(){
    int n,a,b,da,db;
    scanf("%d %d %d %d %d",&n,&a,&b,&da,&db);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    pii p=dfs(a,0);
    if(dis[b]-dis[a]<=da||db<=da*2){
        printf("Alice\n");
    }
    else{
        pii p2=dfs(p.y,0);
        if(da*2<p2.x){
            printf("Bob\n");
        }
        else{
            printf("Alice\n");
        }
    }

}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/