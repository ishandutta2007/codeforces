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
using namespace std;
vector<pii> v[205];
int Min[205];
int Max[205];
int inq[205];
int vis[205];
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<pii,int> > edge;
    for(int i = 0;i<m;i++){
        int x,y,b;
        scanf("%d %d %d",&x,&y,&b);
        v[x].pb(mp(y,b));
        v[y].pb(mp(x,-b));
        edge.pb(mp(mp(x,y),b));
    }
   /* for(int i = 1;i<=n;i++){
        Min[i]=-1e9;
    }
    Min[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        vis[x]++;
        if(vis[x]>2*n){
            printf("NO\n");
            return true;
        }
        q.pop();
        inq[x]=0;
        for(auto it:v[x]){
            if(it.y==0){
                if(Min[it.x]<Min[x]-1){
                    Min[it.x]=Min[x]-1;
                    if(!inq[it.x]){
                        q.push(it.x);
                        inq[it.x]=1;
                    }
                }
            }
            else{
                if(Min[it.x]<Min[x]+it.y){
                    Min[it.x]=Min[x]+it.y;
                    if(!inq[it.x]){
                        q.push(it.x);
                        inq[it.x]=1;
                    }
                }
            } 
        }
    }
    fill(vis,vis+n+1,0);
    int Mi=0,Mini=1;
    for(int i = 1;i<=n;i++){
        if(Mi>Min[i]){
            Mi=Min[i];
            Mini=i;
        }
     //   printf("%d ",Min[i]);
        Max[i]=1e9;
    }*/
   // printf("%d?\n",Mini);
   int ans=0;
   int ansi[1005];
   for(int Mini=1;Mini<=n;Mini++){
        for(int i = 1;i<=n;i++){

     //   printf("%d ",Min[i]);
        Max[i]=1e9;
    }
       queue<int> q;
        q.push(Mini);
        Max[Mini]=0;
        fill(vis,vis+n+1,0);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            inq[x]=0;
            vis[x]++;
            if(vis[x]>2*n){
                printf("NO\n");
                return true;
            }
            for(auto it:v[x]){
                if(it.y==0){
                    if(Max[it.x]>Max[x]+1){
                        Max[it.x]=Max[x]+1;
                        if(!inq[it.x]){
                            q.push(it.x);
                            inq[it.x]=1;
                        }
                    }
                }
                else{
                    if(Max[it.x]>Max[x]+it.y){
                        Max[it.x]=Max[x]+it.y;
                        if(!inq[it.x]){
                            q.push(it.x);
                            inq[it.x]=1;
                        }
                    }
                }
            }
        }
        for(auto it:edge){
            if(it.y==1){
                if(Max[it.x.x]+1!=Max[it.x.y]){
                    printf("NO\n");
                    return true;
                }
            }
            else{
                if(abs(Max[it.x.x]-Max[it.x.y])!=1){
                    printf("NO\n");
                    return true;
                }
            }
        }
        int res=0;
        for(int i = 1;i<=n;i++)res=max(res,Max[i]);
        if(res>ans){
            for(int i = 1;i<=n;i++){
                ansi[i]=Max[i];
            }
            ans=res;
        }
   }
    printf("YES\n%d\n",ans);
    for(int i = 1;i<=n;i++){
        printf("%d ",ansi[i]);
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;  // scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/