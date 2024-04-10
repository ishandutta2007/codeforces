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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
vector<pii> v[605];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb(mp(b,c));
    }
    for(int i = 0;i<n;i++){
        sort(v[i].begin(),v[i].end());
        int Min=1e9+7;
        for(auto it:v[i])Min=min(Min,it.y);
        vector<pii> tmp;
        for(int j = 0;j<v[i].size();j++){
            if(v[i][j].y==Min){
                for(int k = j;k<v[i].size()+j;k++){
                    tmp.pb(v[i][k%v[i].size()]);
                }
                break;
            }
        }
        swap(v[i],tmp);
        tmp.clear();
        tmp.pb(v[i][0]);
        for(int j = 1;j<v[i].size();j++){
            if((v[i][j].x-tmp.back().x+n)%n+tmp.back().y>v[i][j].y){
                tmp.pb(v[i][j]);
            }
        }
        v[i]=tmp;
        sort(v[i].begin(),v[i].end());
    }
    for(int ii = 0;ii<n;ii++){
        LL dis[605];
        LL vis[605];
        fill(dis,dis+605,2e9);
        fill(vis,vis+605,0);
        dis[ii]=0;
        for(int j=1;j<=n;j++){
            int Min=2e9+7,Mini;
            for(int k=0;k<n;k++){
                if(!vis[k]&&dis[k]<Min){
                    Min=dis[k];
                    Mini=k;
                }
            }
            int x=Mini;
            vis[x]=1;
            for(int i = 0;i<v[x].size();i++){
                int now=(v[x][i].x+dis[x])%n;
                int end=(v[x][(i+1)%v[x].size()].x+dis[x])%n;
              //  printf("%d %d %d %d %d\n",ii,now,end,i);
                int cnt=0;
                do{
                    pii p=v[x][i];
                    dis[now]=min(dis[now],dis[x]+cnt+p.y);
                    cnt++;
                    now++;
                    if(now>=n)now-=n;
                }while(now!=end);
            }
        }
        for(int j = 0;j<n;j++){
            printf("%lld ",dis[j]);
        }
        printf("\n");
    }
}
int main(){
    int t=1;//000;
    //scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/