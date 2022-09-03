#include<bits/stdc++.h>
using namespace std;
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
#define cpdd const pdd
#define rank Rank
#define MXN 15000
vector<int> v[200005];
int degree[200005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int degree[200005];
    fill(degree,degree+n+1,0);
    int w[200005];
    for(int i = 1;i<=n;i++)
        scanf("%d",&w[i]);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        degree[x]++;
        degree[y]++;
        v[x].pb(y);
        v[y].pb(x);
    }
    int s;
    scanf("%d",&s);
    LL res=0;
    for(int i = 1;i<=n;i++){
        res+=w[i];
    }
    int vis[200005];
    LL val[200005];
    fill(val,val+n+1,0);
    fill(vis,vis+n+1,0);
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(degree[i]==1&&i!=s){
            q.push(i);
            res-=w[i];
            vis[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(!vis[it]){
                val[it]=max(val[x]+w[x],val[it]);
                if(--degree[it]==1&&it!=s){
                    q.push(it);
                    res-=w[it];
                    vis[it]=1;
                }
            }
        }
    }
    LL Max=0;
    for(int i = 1;i<=n;i++){
        Max=max(Max,val[i]);
       // printf("%d\n",val[i]);
    }
    printf("%lld\n",res+Max);
}