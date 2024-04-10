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
#define MXN 1500
/*LL sum2[10000005];
LL sum[10000005];
LL num[10000005];*/
LL cal2(LL x){
    LL now=x;
    LL res=0;
    LL len=1;
    for(LL i=1;i<=x;i*=10){
        LL Size=min(x+1,i*10)-i;
        res+=Size*len;
        now-=Size;
        len++;
    }
    return res;
}
LL cal(LL x){
    LL now=x;
    LL res=0;
    LL len=1;
    for(LL i=1;i<=x;i*=10){
        LL Size=min(x+1,i*10)-i;
        //printf("%d\n",Size);
        res+=(now+now-Size+1)*Size/2*len;
        now-=Size;
        len++;
    }
    return res;
}
int main(){
   /* int now=1;
    for(int i=1;i<=10000000;i*=10){
        num[i]=now;
        now++;
    }
    for(int i=1;i<=10000000;i++){
        num[i]=max(num[i],num[i-1]);
        sum[i]=sum[i-1]+num[i];
        sum2[i]=sum2[i-1]+sum[i];
        printf("%lld %lld\n",cal(i),sum2[i]);
        assert(cal(i)==sum2[i]);
        assert(cal2(i)==sum[i]);
        //if(i<=10)printf("%lld %lld %lld\n",num[i],sum[i],sum2[i]);
    }*/
   // printf("%lld\n",cal(1000000000));
    int q;
    scanf("%d",&q);
    while(q--){
        LL x;
        scanf("%lld",&x);
        LL Max=1e9,Min=0;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            if(cal(mid)<x){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
        x-=cal(Min);
     //   printf("%lld\n",Min);
        Max=Min+1;Min=0;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            if(cal2(mid)<x){
                Min=mid;
            }
            else{
                Max=mid;
            }
        }
       // printf("%lld\n",Min);
        x-=cal2(Min);
        Min++;
        vector<int> v;
        while(Min){
            v.pb(Min%10);
            Min/=10;
        }
        reverse(v.begin(),v.end());
        printf("%d\n",v[x-1]);
    }
}