#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 3005
#define next Next
vector<int> v[200005];
int p[200005];
int Size[200005];
int dep[200005];
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    p[x]=f;
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dep[0]=-1;
    dfs(1,0);
    printf("d 1\n");
    fflush(stdout);
    int td;
    scanf("%d",&td);
    int now=1;
    while(true){
        int ok=0;
        for(auto it:v[now]){
            if(it!=p[now]&&Size[it]*2>Size[now]-1){
                now=it;
                ok=1;
                break;
            }
        }
        if(!ok){
            printf("d %d\n",now);
            fflush(stdout);
            int x;
            scanf("%d",&x);
            while(dep[now]+x!=td){
                now=p[now];
                x--;
            }
            if(x==0){
                printf("! %d\n",now);
                fflush(stdout);
                break;
            }
            printf("s %d\n",now);
            fflush(stdout);
            scanf("%d",&now);
        }
    }
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/