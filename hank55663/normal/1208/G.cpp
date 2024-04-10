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
#define pdd pair<double,double>
#define cpdd const pdd
int val[2000005];
int main(){
    for(int i = 1;i<2000005;i++)
        val[i]=i;
    for(int i = 1;i<2000005;i++){
        for(int j = i*2;j<2000005;j+=i){
            val[j]-=val[i];
        }
    }
    int n,k;
    scanf("%d %d",&n,&k);
    if(k==1){
        printf("3\n");
        return 0;
    }
    pii p[1000005];
    k+=2;
    for(int i = 1;i<=n;i++){
        p[i-1]=mp(val[i],i);
    }
    sort(p,p+n);
    LL ans=0;
    for(int i = 0;i<k;i++){
        ans+=p[i].x;
    }
    printf("%lld\n",ans);
}