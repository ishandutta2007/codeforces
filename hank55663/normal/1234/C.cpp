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
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        char c[2][200005];
        scanf("%s %s",c[0],c[1]);
        int lastx=0,lasty=-1,nowx=0,nowy=0;
        //int ok=1;
        while(nowx>=0&&nowx<2&&nowy>=0&&nowy<n){
            if(lastx==nowx){
                if(c[nowx][nowy]=='1'||c[nowx][nowy]=='2'){
                    lastx=nowx;
                    lasty=nowy;
                    nowy++;
                }
                else{
                    lastx=nowx;
                    lasty=nowy;
                    nowx^=1;
                }
            }
            else{
                if(c[nowx][nowy]=='1'||c[nowx][nowy]=='2'){
                    lastx=nowx;
                    lasty=nowy;
                //    printf("NO\n");
                    break;
                }
                else{
                    lastx=nowx;
                    lasty=nowy;
                    nowy++;
                    //nowx^=1;
                }
            }
        }
        if(nowx==1&&nowy==n){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}