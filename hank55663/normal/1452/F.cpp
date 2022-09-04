#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int cnt[50];
    for(int i = 0;i<n;i++)scanf("%d",&cnt[i]);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int p,v;
            scanf("%d %d",&p,&v);
            cnt[p]=v;
        }
        else{
           // for(int i = 0;i<n;i++){
            //    printf("%d ",cnt[i]);
           // }
           // printf("\n");
            LL x,k;
            scanf("%lld %lld",&x,&k);
            LL tmp=0;
            for(int i = 0;i<=x;i++)tmp+=cnt[i];
            if(tmp>=k){
                printf("0\n");
                continue;
            }
            LL ans=0;
            LL sum=0;
            for(int i = 0;i<n;i++){
                sum+=(1ll<<i)*cnt[i];
            }
            if(k>sum){
                printf("-1\n");
                continue;
            }
            sum=0;
            for(int i =0;i<=x;i++){
                sum+=(1ll<<i)*cnt[i];
            }
            LL need=max((k-sum+(1ll<<x)-1)/(1ll<<x),0ll);
            sum=0;
            if(need&1)need++;
            LL cnt2[30];
            MEM(cnt2);
            for(int i = x+1;i<n;i++){
                LL val=cnt[i]*(1ll<<(i-x));
                if(val<=need){
                    need-=val;
                    tmp+=val;
                    sum+=cnt[i]*((1ll<<(i-x))-1);
                }
                else{
                  
                    //for(int j = n-1;j>i;j++)cnt2[j]=1;
                    int can=0;
                    cnt2[i]=cnt[i]-(need+(1ll<<(i-x))-1)/(1ll<<(i-x));
                    for(int j = i-1;j>=x;j--){
                        sum+=((need+(1ll<<(j-x))-1)/(1ll<<(j-x))+1)/2;
                      //   printf("%lld %lld\n",sum,(need+(1ll<<(j-x))-1)/(1ll<<(j-x)));
                        if(((need+(1ll<<(j-x))-1)/(1ll<<(j-x)))%2==1)cnt2[j]=1;
                        else cnt2[j]=0;
                    }
                    //printf("%lld\n",sum);
                    tmp+=need;
                    need=0;
                }
                if(need==0){
                 //   printf("%d\n",i);
                    for(int j =n-1;j>i;j--)cnt2[j]=cnt[j];
                    break;
                }
            }
          //  printf("%lld %lld\n",tmp,sum);
            for(int j = x+1;j<n;j++){
              //  printf("%lld ",cnt2[j]);
                if(tmp+(1ll<<(j-x))<=k){
                    LL use=min((k-tmp)/(1ll<<(j-x)),cnt2[j]);
                  //  printf("use:%lld %d\n",use,k-tmp);
                    tmp+=(1ll<<(j-x))*use;
                    sum+=use*(1ll<<(j-x))-use;
                }
            }
          //  printf("%lld\n%lld\n%lld\n",k,tmp,sum);
            printf("%lld\n",sum+max(k-tmp,0ll));
        }
    }
}

int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}