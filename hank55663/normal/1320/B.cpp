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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
vector<int> v[200005],rv[200005],tv[200005];
int dis[200005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        rv[y].pb(x);
        v[x].pb(y);
    }
    int k;
    scanf("%d",&k);
    int p[200005];
    for(int i = 0;i<k;i++){
        scanf("%d",&p[i]);
    }
    queue<int> q;
    q.push(p[k-1]);
    fill(dis,dis+n+1,1e9);
    dis[p[k-1]]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:rv[x]){
            if(dis[it]>dis[x]+1){
                dis[it]=dis[x]+1;
                q.push(it);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            // printf("%d %d %d %d\n",i,it);
            if(dis[it]==dis[i]-1){
                tv[i].pb(it);
             //   printf("%d %d\n",i,it);
            }
        }
    }
    int Max=0,Min=0;
    for(int i = 0;i<k-1;i++){
        if(tv[p[i]].size()!=1||tv[p[i]][0]!=p[i+1])Max++;
        int ok=0;
        for(auto it:tv[p[i]]){
            if(it==p[i+1]){
                ok=1;
            }
        }
        if(!ok)Min++;
    }
    printf("%d %d\n",Min,Max);
}