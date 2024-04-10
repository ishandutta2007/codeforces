#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<int> v[300005];
int vis[300005];
int vis2[300005];
vector<int> ans;
void dfs(int x){
    if(!vis[x]){
        ans.pb(x);
        for(auto it:v[x]){
            vis[it]=1;
        }
    }
    vis2[x]=1;
    for(auto it:v[x]){
        if(!vis2[it]){
            dfs(it);
        }
    }
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        v[i].clear();
        f[i]=i;
        vis[i]=0;
        vis2[i]=0;
    }
    int tot=0;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        x=Find(x);
        y=Find(y);
        if(x!=y){
            f[x]=y;
            tot++;
        }
    }
    if(tot!=n-1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        ans.clear();
        dfs(1);
        printf("%d\n",ans.size());
        for(auto it:ans){
            printf("%d ",it);
        }
        printf("\n");
    }
    return true;
}
int main(){

    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/