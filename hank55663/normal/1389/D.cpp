#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int Next[200005][10];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        LL k;
        scanf("%d %lld",&n,&k);
        int l1,r1,l2,r2;
        scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
        if(l1>l2)swap(l1,l2),swap(r1,r2);
        if(r2<=r1){
            k-=(r2-l2)*1ll*n;
            int x=l2-l1+r1-r2;
            if(k<=0)printf("%d\n",0);
            else if(k<=x*1ll*n)printf("%lld\n",k);
            else printf("%lld\n",k*2-x*1ll*n);
        }
        else if(l2<=r1){
            k-=(r1-l2)*1ll*n;
            //int x=r2-r1+l2-l1;
            int x=l2-l1+r2-r1;
            if(k<=0)printf("%d\n",0);
            else if(k<=x*1ll*n)printf("%lld\n",k);
            else printf("%lld\n",k*2-x*1ll*n);
        }
        else{
            LL ans=1e18;
            for(int i = 1;i<=n;i++){
                LL need=(l2-r1)*1ll*i;
                int x=r2-l1;
                if(k<=x*1ll*i){
                    ans=min(ans,need+k);
                //    printf("%lld\n",need+k);
                }
                else{
                    ans=min(ans,k*2-x*1ll*i+need);
                  //  printf("%lld\n",k*2-x*1ll*i+need);
                }
            }
            printf("%lld\n",ans);
        }
    }
}