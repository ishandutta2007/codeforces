#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    pii p[4],p1[4];
    for(int i=0;i<4;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=mp(a,b);
    }
    for(int i=0;i<4;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p1[i]=mp(a,b);
    }
    int ok=0;
    int Maxx=-100,Minx=100,Maxy=-100,Miny=100;
    for(int i=0;i<4;i++){
        Maxx=max(p[i].x,Maxx);
        Maxy=max(p[i].y,Maxy);
        Minx=min(p[i].x,Minx);
        Miny=min(p[i].y,Miny);
    }
    int ans[300][300];
    MEM(ans);
    for(int i=Minx+100;i<=Maxx+100;i++)
        for(int j=Miny+100;j<=Maxy+100;j++){
            ans[i][j]=1;
           // printf("%d %d %d\n",i-100,j-100,Maxy);
        }
    sort(p1,p1+4);
    int x1=p1[0].x,x2=p1[1].x,x3=p1[3].x;
    int now=0,add=1;
    for(int i=x1;i<=x3;i++){
        for(int j=p1[0].y-now;j<=p1[0].y+now;j++){
            if(ans[i+100][j+100]){
                ok=1;
            }
          //  printf("%d %d\n",i,j);
        }
        if(i==x2)
        add=-1;
        now+=add;
    }
    if(ok)
    printf("YES\n");
    else
    printf("NO\n");
}