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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
int main() {
    int q;
    scanf("%d",&q);
    while(q--){
        int Maxx=1e5,Minx=-1e5,Maxy=1e5,Miny=-1e5;
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            int x,y;
            int ok[4];
            scanf("%d %d",&x,&y);
            for(int j = 0;j<4;j++){
                scanf("%d",&ok[j]);
            }
            if(!ok[0]){
                Minx=max(Minx,x);
            }
            if(!ok[1]){
                Maxy=min(Maxy,y);
            }
            if(!ok[2]){
                Maxx=min(Maxx,x);
            }
            if(!ok[3]){
                Miny=max(Miny,y);
            }
        }
        if(Maxx>=Minx&&Maxy>=Miny){
            printf("1 %d %d\n",Maxx,Maxy);
        }
        else{
            printf("0\n");
        }
    }
}