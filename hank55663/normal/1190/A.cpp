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
#define MXN 10005
#define less Less
#define N (1<<20)
int main(){
    LL n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    LL p[100005];
    for(int i = 0;i<m;i++){
        scanf("%lld",&p[i]);
    }
    LL last=-1,sub=0;
    LL tmpsub=0;
    LL ans=-1;
    for(int i = 0;i<m;i++){
        if((p[i]-sub-1)/k!=last){
            sub+=tmpsub;
            tmpsub=1;
            ans++;
            last=(p[i]-sub-1)/k;
          //  printf("%d\n",i);
        }
        else{
            tmpsub++;
        }
    }
    ans++;
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
*/