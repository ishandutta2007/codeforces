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
#define last Last
#define MXN 200005
void solve(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    pii p[4]={{1,1},{1,m},{n,1},{n,m}};
    LL ans=-1;
    int x,y;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            LL dis=abs(p[i].x-p[j].x)+0ll+abs(p[i].y-p[j].y)+abs(p[i].x-a)+abs(p[i].y-b)+abs(p[j].x-a)+abs(p[j].y-b);
            //printf("%lld\n",dis);
            if(dis>ans){
                x=i,y=j,ans=dis;     
            }
        }
    }
    printf("%d %d %d %d\n",p[x].x,p[x].y,p[y].x,p[y].y);
}
int main(){
    int t=1;//00;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/