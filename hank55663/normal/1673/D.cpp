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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    LL b,q,y;
    LL c,r,z;
    scanf("%lld %lld %lld %lld %lld %lld",&b,&q,&y,&c,&r,&z);
    LL lb=b,rb=b+q*(y-1);
    LL lc=c,rc=c+r*(z-1);
    if(lc>=lb&&rc<=rb){
        if(r%q==0){
          
            if((c-b)%q==0){
                  LL lastc=lc-r,nextc=rc+r;
            if(lastc<lb||nextc>rb){
                printf("-1\n");
                return;
            }
                vector<LL> fac;
                for(int j = 1;j*j<=r;j++){
                    if(r%j==0){
                        fac.pb(j);
                        if(j*j!=r)
                        fac.pb(r/j);
                    }
                }
                const int mod=1e9+7;
                LL ans=0;
                for(auto it:fac){
                    LL gcd=__gcd(it,q);
                    if(it*q/gcd!=r)continue;
                    ans+=r/it*r/it;
                    ans%=mod;
                }
                printf("%lld\n",ans);
            }
            else{
                printf("0\n");
            }
        }
        else{
            printf("0\n");
        }
    }
    else{
        printf("0\n");
    }
}
int main(){
    srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/