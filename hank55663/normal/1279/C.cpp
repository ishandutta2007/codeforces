
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
#define KK 500
#define N 100005
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        int num[100005];
        for(int i = 1;i<=n;i++){
            int x;
            scanf("%d",&x);
            num[x]=i;
        }
        LL ans=0;
        LL Max=0;
        for(int i = 1;i<=m;i++){
            int x;
            scanf("%d",&x);
            if(num[x]<Max){
                ans++;
            }
            else{
                ans+=(num[x]-i)*2+1;
                Max=num[x];
            }
        }
        printf("%lld\n",ans);
    }
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/