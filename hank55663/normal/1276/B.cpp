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
#define MXN 100005
vector<int> v[200005];
int vis[200005];
int va,vb;
int dfs(int x,int a,int b){
    int Size=1;
    vis[x]=1;
    for(auto it:v[x]){
        if(!vis[it]){
            if(it==a)va=1;
            else if(it==b)vb=1;
            else{
                Size+=dfs(it,a,b);
            }
        }
    }
    return Size;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b;
        scanf("%d %d %d %d",&n,&m,&a,&b);
        for(int i = 1 ; i <= n ; i++)v[i].clear();
        fill(vis,vis+n+1,0);
        for(int i = 0 ; i < m ; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        LL cnta=0,cntb=0;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]&&i!=a&&i!=b){
                va=vb=0;
                int S=dfs(i,a,b);
                
                if(va&&!vb)cnta+=S;
                if(!va&&vb)cntb+=S;
            }
        }
        printf("%lld\n",cnta*cntb);
    }
}
/*
7 8
1 3 1
2 3 9
2 4 3
2 5 4
4 5 7
3 6 6
3 7 7
6 7 8

*/