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
 
int main(){
    LL x,y,ax,ay,bx,by;
    scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&ax,&ay,&bx,&by);
    vector<pll> v;
    while(x<3e16&&y<3e16){
        v.pb(mp(x,y));
        x=ax*x+bx;
        y=ay*y+by;
    }
    LL sx,sy,t;
    scanf("%lld %lld %lld",&sx,&sy,&t);
    int ans=0;
    for(int i = 0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            LL tot=abs(sx-v[i].x)+abs(sy-v[i].y)+v[j].x-v[i].x+v[j].y-v[i].y;
            tot=min(tot,abs(sx-v[j].x)+abs(sy-v[j].y)+v[j].x-v[i].x+v[j].y-v[i].y);
            if(tot<=t)ans=max(ans,j-i+1);
        }
    }
    printf("%d\n",ans);
}
/*
2 6
5 7
7 5
4 3
6 4
7 3
6 5
5 7
3 6
4 7
*/
//a+a+1=10a+1
//3a+2=10a+2