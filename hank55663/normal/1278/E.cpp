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
#define KK 500
#define N 100005
vector<int> v[500005];
int now=0;
pii p[500005];
void dfs(int x,int f){
    reverse(v[x].begin(),v[x].end());
    for(auto it:v[x]){
        if(it!=f)
        p[it].x=++now;
    }
    p[x].y=++now;
    reverse(v[x].begin(),v[x].end());
    for(auto it:v[x]){
        if(it!=f)
        dfs(it,x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
   // printf("\n");
    p[1].x=++now;
    dfs(1,0);
    for(int i = 1;i<=n;i++){
        printf("%d %d\n",p[i].x,p[i].y);
    }
}