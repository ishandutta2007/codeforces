#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int x,y,x1,y1,x2,y2;
        scanf("%d %d %d %d %d %d",&x,&y,&x1,&y1,&x2,&y2);
        int tx=x+b-a,ty=y+d-c;
        if(tx>=x1&&tx<=x2&&ty>=y1&&ty<=y2){
            if(x1==x2&&a){
                printf("NO\n");
            }
            else if(y1==y2&&c){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
        else{
            printf("NO\n");
        }
    }
}