#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
static const double INF = 2147483647;
void solve(){
    int h,w;
    scanf("%d %d",&h,&w);
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            if(i==0&&j==0)printf("1");
            else if(i==0&&j==w-1)printf("1");
            else if(i==h-1&&j==0)printf("1");
            else if(i==h-1&&j==w-1)printf("1");
            else if(i==0||i==h-1){
                if(j%2==0&&j!=w-2)printf("1");
                else printf("0");
            }
            else if(j==0||j==w-1){
                if(i%2==0&&i!=h-2)printf("1");
                else printf("0");
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}