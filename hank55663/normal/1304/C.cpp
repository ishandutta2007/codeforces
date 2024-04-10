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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        pair<int,pii> p[105];
        for(int i = 0;i<n;i++){
            int t,l,h;
            scanf("%d %d %d",&t,&l,&h);
            p[i]=mp(t,mp(l,h));
        }
        sort(p,p+n);
        int l=m,r=m;
        int last=0;
        int ok=1;
        for(int i = 0;i<n;i++){
            l-=p[i].x-last;
            r+=p[i].x-last;
            last=p[i].x;
            l=max(l,p[i].y.x);
            r=min(r,p[i].y.y);
            if(l>r){
                ok=0;
                break;
            }
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
/*
6 10
1 1 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
2 2 3 3 0 0 0 0 0 0 
0 0 3 3 4 4 0 0 0 0 

{1}
{1}
{1000000000}
{1000000000}
1

1000000000 
1000
{1000}
{1000000000}
*/