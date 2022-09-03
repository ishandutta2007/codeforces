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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
vector<pii> v[300005];
int vis[300005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=3*n;i++){
            v[i].clear();
            vis[i]=0;
        }
        for(int i = 0 ;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].pb(mp(b,i+1));
            v[b].pb(mp(a,i+1));
        }
        vector<int> inde;
        vector<int> edge;
        for(int i =1;i<=3*n;i++){
            if(vis[i])continue;
            int ok=0;
            for(auto it:v[i]){
                if(!vis[it.x]){
                    edge.pb(it.y);
                 //   printf("%d %d\n",it.x,i);
                    vis[it.x]=1;
                    vis[i]=1;
                    ok=1;
                    break;
                }
            }
            //printf("%d %d\n",i,ok);
            if(!ok){
               // printf("%d\n",i);
                inde.pb(i);
            }
        }
        if(inde.size()>=n){
            printf("IndSet\n");
            for(int i = 0;i<n;i++)
                printf("%d ",inde[i]);
            printf("\n");
        }
        else{
            assert(edge.size()>=n);
            printf("Matching\n");
            for(int i =0;i<n;i++){
                printf("%d ",edge[i]);
            }
            printf("\n");
        }
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */