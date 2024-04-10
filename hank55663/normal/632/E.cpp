#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int vis[1000005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int ok[1005];
    MEM(ok);
    for(int i = 1;i<=n;i++){
        int x=i;
        scanf("%d",&x);
        ok[x]=1;
    }
    int Min=1e9;
    vector<int> v;
    for(int i = 1;i<=1000;i++){
        if(ok[i]){
            Min=min(Min,i);
            v.pb(i-Min);
          //  printf("%d\n",i-Min);
        }
    }
    fill(vis,vis+1000005,-1);
    vis[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(vis[x]==k)continue;
        for(auto it:v){
            if(vis[it+x]==-1){
                vis[it+x]=vis[x]+1;
                q.push(it+x);
            }
        }
    }
    for(int i = 0;i<=1000000;i++){
        if(vis[i]!=-1){
            printf("%d ",Min*k+i);
        }
    }
    printf("\n");
}