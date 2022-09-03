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
char c[2005][2005];
int sum[2005][2005];
int n,m;
int cal(int xx,int yy){
    return (__builtin_popcount(xx)+__builtin_popcount(yy))&1;
}
LL dc(LL x,LL y){
    if(x==0||y==0)return 0;
    LL xx=x/n,yy=y/m;
    LL res=0;
    res=(x*y-(x-xx*n)*(y-yy*m))/2;
  // printf("%d %d %d %d %d\n",xx,yy,x,y,res);
    if(cal(xx,yy))
        res+=(x-xx*n)*(y-yy*m)-sum[x-xx*n][y-yy*m]; 
    else
        res+=sum[x-xx*n][y-yy*m];
 //   printf("x:%d y:%d res:%d xx:%d yy:%d x-xx*n:%d y-yy*m:%d %d %d %d\n",x,y,res,xx,yy,x-xx*n,y-yy*m,n*xx*yy*m/2,(x-xx*n)*(y-yy*m),sum[x-xx*n][y-yy*m]);
    //printf("%d %d %d\n",x,y,res);
    return res;
}
int main(){
    int q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    for(int i = 1;i<=2*n;i++){
        for(int j = 1;j<=2*m;j++){
            if(i>n&&j>m){
                c[i][j]=c[i-n][j-m];
            }
            else if(i>n){
                c[i][j]=((c[i-n][j]-'0')^1)+'0';
            }
            else if(j>m){
                c[i][j]=((c[i][j-m]-'0')^1)+'0';
            }
        }
    }
    n*=2,m*=2;
 //   for(int i = 1;i<=n;i++)
    //    printf("%s\n",c[i]+1);
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=m;j++){
            sum[i][j]=c[i][j]-'0';
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--;
        y1--;
        printf("%lld\n",dc(x1,y1)+dc(x2,y2)-dc(x2,y1)-dc(x1,y2));
    }
}