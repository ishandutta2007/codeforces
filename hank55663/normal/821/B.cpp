#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define rank Rank
#define index Index
int main(){
    int m,b;
    scanf("%d %d",&m,&b);
    LL ans=0;
    for(LL x=0;x<=m*b;x++){
        LL y=(m*b-x)/m;
        ans = max((1+x)*x*(y+1)/2+(1+y)*y*(x+1)/2,ans);
     //   printf("%lld %lld %lld\n",x,y,(1+x)*x*y/2+(1+y)*y*x/2);
    }
    printf("%lld\n",ans);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
11010101
*/