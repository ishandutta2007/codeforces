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
#define MXN 300000

int main(){
    LL n,K;
    scanf("%lld %lld",&n,&K);
    LL a[100005];
    for(int i = 1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    a[0]=-1;
    a[n+1]=1e9+7;
    int l=a[1],r=a[n];
    int ll=1,rr=n;
    while(K){
        LL lastK=K;
        while(a[ll+1]==l)ll++;
        while(a[rr-1]==r)rr--;
        if(ll>=rr){
            printf("0\n");
            return 0;
        }
        if(ll<n-rr+1){
            LL x=min(a[ll+1]-a[ll],K/ll);
            l+=x;
            K-=ll*x;
        }
        else{
            LL x=min(a[rr]-a[rr-1],K/(n-rr+1));
            r-=x;
            K-=(n-rr+1)*x;
        }
        if(K==lastK)break;
    }
    printf("%d\n",r-l);
}
/*
5 4
8 1 0 3 0
0 0 1 3 8
1
*/