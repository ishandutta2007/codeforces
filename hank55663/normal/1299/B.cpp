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
    int n;
    scanf("%d",&n);
    if(n&1){
        printf("NO\n");
    }
    else{
        pii p[100005];
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
        }
        p[n]=p[0];
        int now=0,now2=n/2;
        for(;now<n/2;now++){
            pii p1=mp(p[now+1].x-p[now].x,p[now+1].y-p[now].y);
            pii p2=mp(p[now2].x-p[now2+1].x,p[now2].y-p[now2+1].y);
            if(p1!=p2){
                printf("NO\n");
                return 0;
            }
            now2++;
        }
        printf("YES\n");
    }
}