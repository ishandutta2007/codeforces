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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
pii pp[1005][1005];
char ans[1005][1005];
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
char c[10]="LRUD";
int main(){
    int n;
    scanf("%d",&n);
    queue<pii> q;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            pp[i][j]=mp(x,y);
            if(x==i&&y==j){
                ans[i][j]='X';
                q.push(mp(i,j));
            }
        }
    }
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(pp[x][y]==pp[p.x][p.y]&&ans[x][y]==0){
                ans[x][y]=c[i];
                q.push(mp(x,y));
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pp[i][j]==mp(-1,-1)){
                int ok=0;
                for(int k = 0;k<4;k++){
                    int x=i+X[k],y=j+Y[k];
                    if(pp[x][y]==mp(-1,-1)){
                        ok=1;
                        ans[i][j]=c[k^1];
                    }
                }
                if(!ok){
                    printf("INVALID\n");
                    return 0;
                }
            }
            else{
                if(ans[i][j]==0){
                    printf("INVALID\n");
                    return 0;
                }
            }
        }
    }
    printf("VALID\n");
    for(int i=  1;i<=n;i++)
        printf("%s\n",ans[i]+1);
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/