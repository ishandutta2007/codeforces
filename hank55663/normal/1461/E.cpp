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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL dp[1000005];
LL ll[1000005];
LL rr[1000005];
void solve(){
    LL l=rand()%100000+1,r=rand()%100000+1,t=rand()%100000+1,x=rand()%100000+1,y=rand()%100000+1;
   // if(l>r)swap(l,r);
    LL k=rand()%(r-l+1)+l;
    scanf("%lld %lld %lld %lld %lld %lld",&k,&l,&r,&t,&x,&y);
    //printf("%lld %lld %lld %lld %lld %lld\n",k,l,r,t,x,y);
   /* int ok=1;
    LL tmp=k;
    for(int i  = 0;i<t;i++){
        if(tmp+y<=r)tmp+=y;
        tmp-=x;
        if(tmp<l){
            ok=0;
            break;
        }
    }*/
    if(y<=x){
        if(k+y<=r){
            k+=y;
        }
        else{
            if(k-(__int128)t*x>=l){
                printf("Yes\n");
              //  assert(ok==1);
                return;
            }
            LL need=(k-(r-y)+x-1)/x;
            if(k-need*x<l){
              //  printf("%lld %lld\n",k-need*x,need);
                printf("No\n");
              //   assert(ok==0);
                return;
            }
            if(r-l<y){
                printf("No\n");
               // assert(ok==0);
                return;
            }
           // printf("%d\n",need);
            k-=need*x;
            k+=y;
            t-=need;
           // printf("%lld %lld\n",k,t);
        }
        __int128 val=(__int128)k-(__int128)x*t+(__int128)y*(t-1);
        if(val<l){
            printf("No\n");
          //  assert(ok==0);
        }
        else{
            printf("Yes\n");
          //  assert(ok==1);
        }
    }
    else{
        for(int i =0;i<x;i++){
            ll[i]=(l-i+x-1)/x;
            if(l-i<=0)ll[i]=0;
            rr[i]=(r-i)/x;
            if(r-i<0)rr[i]=-1;
        }
        LL tot=0;
        fill(dp,dp+x+1,-1);
        //dp[k%x]=1;
        tot+=k/x-ll[k%x];
        LL now=k%x;
        while(dp[now]==-1){
//printf("%lld ",tot);
            
            LL Next=ll[now]*x+now+y;
         ///   printf("%lld %lld\n",ll[now]*x+now,Next);
            if(Next>r)break;
            tot+=Next/x-ll[Next%x];
            if(tot>=t)break;
            dp[now]=1;
            now=Next%x;
            
        }
        if(tot>=t||dp[now]!=-1){
            printf("Yes\n");
          //  assert(ok==1);
        }
        else{
            printf("No\n");
          //  assert(ok==0);
        }
    }
}
int main(){
    int t=1;//00000;  
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}