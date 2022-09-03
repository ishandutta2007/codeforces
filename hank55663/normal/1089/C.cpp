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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
int g[505][505];
bitset<501> dis[505][505];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++)g[i][j]=600;
        g[i][i]=0;
    }
    for(int i = 0;i<m;i++){
        int k;
        scanf("%d",&k);
        int last;
        scanf("%d",&last);
        for(int j = 1;j<k;j++){
            int x;
            scanf("%d",&x);
            g[last][x]=g[x][last]=1;
            last=x;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++){
                g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
            }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]==1){
                for(int k=1;k<=n;k++){
                    if(g[i][k]>g[j][k]){
                        dis[i][j][k]=1;
                    }
                }
            }
        }
    }
    bitset<501> tmp;
    for(int t=0;t<n;t++){
        for(int i = 1;i<=n;i++)
            tmp[i]=1;
       // cout<<tmp<<endl;
       // printf("%d\n",n);
        int tot=n;
        while(true){
            int qu=-1;
            for(int i = 1;i<=n;i++){
                int ok=1;
                if(tmp[i]){
                    for(int j = 1;j<=n;j++){
                        if(g[i][j]==1&&tmp[j]){
                            if((dis[i][j]&tmp).count()>tot/2){
                                ok=0;
                            }
                        }
                    }
                    if(ok){
                        qu=i;
                        break;
                    }
                }
                
            }
            if(qu==-1)return -1;
            printf("%d\n",qu);
            fflush(stdout);
            char c[50];
            scanf("%s",c);
            if(c[0]=='F'){
                break;
            }
            else{
                int y;
                scanf("%d",&y);
                //cout<<tmp<<endl;
                tmp&=dis[qu][y];
                //cout<<tmp<<endl;
            }
            tot=tmp.count();
        }
    }
}