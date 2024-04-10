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
const int mod=998244353;
LL cal[100005];
LL val[100005];
vector<int> prime;
LL dp[25][100005];
LL cal2(int l,int r){
    if(l>r)return 0;
    LL tot=0;
    LL last=r;
    for(int i = 1;;){
        int Next=(r)/(i+1);
        //printf("%d %d %d\n",Next,last,i);
        if(Next<l){
            tot+=cal[i]*(last-l+1);
            break;
        }
        tot+=cal[i]*(last-Next);
        last=Next;
        i=r/Next;
    }
    return tot;
}
void dc(int k,int l,int r,int optl,int optr){
    if(l>r)return;
    int mid=(l+r)/2;
    int opt=0;
    dp[k][mid]=1e18;
    LL now=cal2(optr+1,mid);
  // if(k==2&&mid==2){
   //    printf("!%d %d %lld\n",optr+1,mid,now);
  // }
    for(int i = min(optr,mid);i>=optl;i--){
        now+=cal[mid/i];
        LL val=dp[k-1][i-1]+now;
      //  printf("%d %d %lld %lld\n",i,mid,now,cal2(i,mid));
        //assert(now==cal2(i,mid));
      //  if(k==2&&mid==2){
       //     printf("%d %d %d\n",dp[k-1][i-1],now,i);
      //  }
        if(val<dp[k][mid]){
            dp[k][mid]=val;
            opt=i;
        }
    }
    dc(k,l,mid-1,optl,opt);
    dc(k,mid+1,r,opt,optr);
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>=20)printf("%d\n",n);
    else{
        printf("%lld\n",dp[k][n]);
    }
}
int main(){
    for(int i = 1;i<=100000;i++)val[i]=i;
    for(int i = 2;i<=100000;i++){
        if(val[i]==i){
            for(int j = i;j<=100000;j+=i)val[j]=val[j]/i*(i-1);
        }
    }
    cal[1]=1;
    for(int i = 2;i<=100000;i++)cal[i]=cal[i-1]+val[i];
    for(int i = 1;i<=100000;i++){
        dp[1][i]=i*1ll*(i+1)/2;
    }
    //printf("%lld\n",cal2(2,4));
    for(int i =2;i<=20;i++){
        dc(i,1,100000,1,100000);
    }
    int t=1;//00;//00;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
(k_1x+b)k_2+b=y
*/