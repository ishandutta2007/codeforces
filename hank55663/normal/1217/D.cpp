#include<bits/stdc++.h>
using namespace std;
#pragma optimizer(-Ofast)
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define rank Rank
#define MXN 15000
vector<int> v[5005];
int instk[5005];
int vis[5005];
bool dfs(int x){
    instk[x]=1;
    vis[x]=1;
    for(auto it:v[x]){
        if(instk[it])return false;
        if(!vis[it]){
            if(!dfs(it))return false;
        }
    }
    instk[x]=0;
   // printf("%d\n",x);
    return true;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[5005];
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        p[i]=mp(x,y);
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(!dfs(i)){
                printf("2\n");
                for(int j=0;j<m;j++){
                    if(p[j].x<p[j].y)printf("1 ");
                    else printf("2 ");
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("1\n");
    for(int i = 1;i<=m;i++)
    printf("1 ");
    printf("\n");
    return 0;
}