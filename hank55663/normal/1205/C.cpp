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
#define MXN 1500005
#define XXX 2520
int main(){
    int n;
    scanf("%d",&n);
    int ans[55][55];
    MEMS(ans);
    ans[1][1]=1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==1&&j==1)
                continue;
            if((i+j)%2!=0)continue;
            if(i==1){
                printf("? 1 %d 1 %d\n",j-2,j);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x)
                ans[i][j]=ans[i][j-2];
                else
                ans[i][j]=ans[i][j-2]^1;
            }
            else if(j==1){
                printf("? %d 1 %d 1\n",i-2,i);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x)
                ans[i][j]=ans[i-2][j];
                else
                ans[i][j]=ans[i-2][j]^1;
            }
            else{
                printf("? %d %d %d %d\n",i-1,j-1,i,j);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x)
                ans[i][j]=ans[i-1][j-1];
                else
                ans[i][j]=ans[i-1][j-1]^1;
            }
        }
    }
    queue<pii> q;
    for(int i =1;i<=n-2;i++){
        for(int j = 1;j<=n-2;j++){
            if(ans[i][j]==1&&ans[i+2][j+2]==0){
                if(ans[i+2][j]!=ans[i+1][j+1]){
                    printf("? %d %d %d %d\n",i,j,i+2,j+1);
                    fflush(stdout);
                    int x;
                    scanf("%d",&x);
                    if(x)
                        ans[i+2][j+1]=ans[i][j];
                    else
                        ans[i+2][j+1]=ans[i][j]^1;
                    q.push(mp(i+2,j+1));
                }
                else if(ans[i][j+2]!=ans[i+1][j+1]){
                    printf("? %d %d %d %d\n",i,j,i+1,j+2);
                    fflush(stdout);
                    int x;
                    scanf("%d",&x);
                    if(x)
                        ans[i+1][j+2]=ans[i][j];
                    else
                        ans[i+1][j+2]=ans[i][j]^1;
                    q.push(mp(i+1,j+2));
                }
                else{
                    printf("? %d %d %d %d\n",i,j,i+1,j+2);
                    fflush(stdout);
                    int x;
                    scanf("%d",&x);
                    if(x){
                        ans[i+1][j+2]=ans[i][j];
                        q.push(mp(i+1,j+2));
                    }
                    else{
                        printf("? %d %d %d %d\n",i,j+1,i+2,j+2);
                        fflush(stdout);
                        int x;
                        scanf("%d",&x);
                        if(x){
                            ans[i][j+1]=ans[i+2][j+2];
                            q.push(mp(i,j+1));
                        }
                        else{
                            if(ans[i][j+2]==0){
                                ans[i][j+1]=1;
                                q.push(mp(i,j+1));
                            }
                            else{
                                ans[i+1][j+2]=0;
                                q.push(mp(i+1,j+2));
                            }
                        }
                    }
                }
            goto next;
            }
        }
    }
    next:
    int X[4]={-1,1,2,0};
    int Y[4]={-1,1,0,2};
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=p.x+X[i],y=p.y+Y[i];
            if(x>=1&&x<=n&&y>=1&&y<=n&&ans[x][y]==-1){
                if(i==0)
                printf("? %d %d %d %d\n",x,y,p.x,p.y);
                else
                printf("? %d %d %d %d\n",p.x,p.y,x,y);
                fflush(stdout);
                int a;
                scanf("%d",&a);
                if(a){
                    ans[x][y]=ans[p.x][p.y];
                }
                else{
                    ans[x][y]=ans[p.x][p.y]^1;
                }
                q.push(mp(x,y));
            }
        }
    }
    printf("!\n");
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d",ans[i][j]);
        }
        printf("\n");
    }
}
/*
1 4  2  3

*/