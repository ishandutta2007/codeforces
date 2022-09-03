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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
int vis[105][105];
bool solve(){
    int n;
    scanf("%d",&n);
    int a[105];
    int prea[105],preb[105];
    prea[0]=0;
    for(int i= 1;i<=n;i++)scanf("%d",&a[i]),prea[i]=prea[i-1]+a[i];
    int m;
    scanf("%d",&m);
    int b[105];
    preb[0]=0;
    for(int i = 1;i<=m;i++)scanf("%d",&b[i]),preb[i]=preb[i-1]+b[i];
    int res=0;
    for(int i = 0;i<=n;i++){
        for(int j =0;j<=m;j++){
            res=max(res,prea[i]+preb[j]);
        }
    }
    printf("%d\n",res);
    return true;
}
int main(){
    int t=1;00000;//0000;//00000;//000000;//000000;
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