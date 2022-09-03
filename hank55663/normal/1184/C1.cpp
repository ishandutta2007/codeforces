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
#define MXN 10005
#define less Less
int main(){
    int n;
    scanf("%d",&n);
    pii p[51];
    for(int i = 0;i<4*n+1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int x1=0;x1<=50;x1++){
        for(int x2=x1+1;x2<=50;x2++){
            for(int y1=0;y1<=50;y1++){
                for(int y2=y1+1;y2<=50;y2++){
                    int sum=0;
                    pii ans;
                    for(int i=0;i<4*n+1;i++){
                        if(p[i].x!=x1&&p[i].x!=x2&&p[i].y!=y1&&p[i].y!=y2){
                            sum++;
                            ans=p[i];
                        }
                        else if(p[i].x<x1||p[i].x>x2||p[i].y<y1||p[i].y>y2){
                            sum++;
                            ans=p[i];
                        }
                    }
                   // if(x1==0&&x2==2&&y1==0&&y2==2)
                  //  printf("%d\n",sum);
                    if(sum==1){
                        printf("%d %d\n",ans.x,ans.y);
                        return 0;
                    }
                }
            }
        }
    }

}