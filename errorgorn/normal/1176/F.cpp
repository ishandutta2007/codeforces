#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int n,k;
long long memo[10][2];
long long best[3][3];
long long sbest[3];
long long dbest[3];
int main(){
    //freopen("input.txt","r",stdin);
    memset(memo,128,sizeof(memo));
    memo[0][0]=0;
    scanf("%d",&n);
    int a=0,b=1;
    long long c,d;
    while (n--){
        scanf("%d",&k);
        memset(best,128,sizeof(best));
        while (k--){
            scanf("%lld%lld",&c,&d);
            c--;
            for (int x=0;x<3;x++){
                if (best[c][x]<d){
                    for (int y=2;y>x;y--) best[c][y]=best[c][y-1];
                    best[c][x]=d;
                    break;
                }
            }
        }
        for (int x=0;x<3;x++){
            for (int y=0;y<3;y++){
                if (best[x][y]==-9187201950435737472) best[x][y]=-918720195043573747;
                //printf("%lld ",best[x][y]);
            }
            //printf("\n");
        }
        ///wtf is this shit
        sbest[0]=max(best[0][0],max(best[1][0],best[2][0])); // 1 or 2 or 3
        sbest[1]=max(best[0][0]+best[0][1],best[0][0]+best[1][0]); // 1,1 or 1,2
        sbest[2]=best[0][0]+best[0][1]+best[0][2];
        dbest[0]=max(best[0][0]*2,max(best[1][0]*2,best[2][0]*2));
        dbest[1]=max(best[0][0]*2+best[0][1],best[0][0]+best[1][0]+max(best[0][0],best[1][0]));
        dbest[2]=best[0][0]*2+best[0][1]+best[0][2];
        ///dont think too much about whats on top.... you will only hurt yourself
        //for (int x=0;x<10;x++) printf("%lld ",memo[x][a]);
        //printf("\n");
        for (int x=0;x<10;x++){
            if (memo[x][a]<0) continue;
            memo[x][b]=max(memo[x][b],memo[x][a]);
            for (int y=0;y<3;y++){
                if (x+y<9) memo[x+y+1][b]=max(memo[x+y+1][b],memo[x][a]+sbest[y]);
                else memo[x+y-9][b]=max(memo[x+y-9][b],memo[x][a]+dbest[y]);
            }
        }
        //for (int x=0;x<10;x++) printf("%lld ",memo[x][b]);
        //printf("\n\n");
        swap(a,b);
    }
    long long ans=0;
    for (int x=0;x<10;x++){
        ans=max(ans,memo[x][a]);
    }
    printf("%lld\n",ans);
}