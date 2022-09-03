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
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[1005][1005];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
            a[i][j]--;
        }
    }
    pii aa[3];
    aa[0]=mp(0,0);
    aa[1]=mp(0,1);
    aa[2]=mp(0,2);
    char c[100005];
    scanf("%s",c);
    for(int i = 0;i<m;i++){
        if(c[i]=='L')aa[1].x--;
        if(c[i]=='R')aa[1].x++;
        if(c[i]=='U')aa[0].x--;
        if(c[i]=='D')aa[0].x++;
        if(c[i]=='I')swap(aa[1],aa[2]);
        if(c[i]=='C')swap(aa[0],aa[2]);
    }
   // printf("%d %d %d %d %d %d\n",aa[0].x,aa[0].y,aa[1].x,aa[1].y,aa[2].x,aa[2].y);
    int ans[1005][1005];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x,y,val;
            if(aa[0].y==0)x=i;
            if(aa[0].y==1)x=j;
            if(aa[0].y==2)x=a[i][j];
            if(aa[1].y==0)y=i;
            if(aa[1].y==1)y=j;
            if(aa[1].y==2)y=a[i][j];
            val=i+j+a[i][j]-x-y;
            x=((x+aa[0].x)%n+n)%n;
            y=((y+aa[1].x)%n+n)%n;
            val=((val+aa[2].x)%n+n)%n;
            ans[x][y]=val;
    //       printf("%d %d %d\n",x,y,val);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",ans[i][j]+1);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/