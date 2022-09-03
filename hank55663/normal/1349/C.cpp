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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
LL val[1005][1005];
int color[1005][1005];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int main(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    for(int i = 0 ;i<n;i++){
        for(int j=0;j<m;j++){
            char c=rand()%2+'0';
            scanf(" %c",&c);
            color[i][j]=c-'0';
        }
    }
    queue<pii> q;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            int ok=0;
            for(int k=0;k<4;k++){
                int x=i+X[k],y=j+Y[k];
                if(x>=0&&x<n&&y>=0&&y<m&&color[i][j]==color[x][y]){
                    ok=1;
                }
            }
            if(ok){
                q.push(mp(i,j));
                val[i][j]=0;
            }
            else{
                val[i][j]=1e18+7;
            }
        }
    }
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i = 0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=0&&x<n&&y>=0&&y<m&&color[x][y]!=color[p.x][p.y]&&val[x][y]>val[p.x][p.y]+1){
                val[x][y]=val[p.x][p.y]+1;
                q.push(mp(x,y));
            }
        }
    }
   /* for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%lld ",val[i][j]);
        }
        printf("\n");
    }*/
    while(t--){
        int x,y;
        LL p;
        scanf("%d %d %lld",&x,&y,&p);
        x--;
        y--;
        if(val[x][y]>p){
            printf("%d\n",color[x][y]);
        }
        else{
            LL tot=val[x][y]-p;
            printf("%lld\n",color[x][y]^(tot&1));
        }
    }
}