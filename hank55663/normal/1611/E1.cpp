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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int dis[200005];
bool dfs(int x,int f,int d=0){
   // printf("%d %d %d\n",x,dis[x],d);
    if(dis[x]<=d)return false;
    if(v[x].size()==1&&x!=1)return true;
    for(auto it:v[x]){
        if(it!=f){
            if(dfs(it,x,d+1))return true;
        }
    }
    return false;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)v[i].clear();
    fill(dis,dis+n+1,-1);
    queue<int> q;
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        q.push(x);
        dis[x]=0;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(dis[it]==-1){
                q.push(it);
                dis[it]=dis[x]+1;
            }
        }
    }
    if(dfs(1,0)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/