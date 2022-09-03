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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
LL cnt[20000007];
int main(){
    int n;
    scanf("%d",&n);
    int a[400005];
    for(int i = 0;i<n;i++){
        int x=rand()%100;
        scanf("%d",&x);
        a[i]=x;
    }
    /*int res=0;
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            res^=a[i]+a[j];
        }
    }
    printf("%d\n",res);*/
    int ans=0;
    for(int t = 0;t<25;t++){
        fill(cnt,cnt+20000007,0);
        int mask=(1<<t)-1;
        for(int i = 0;i<n;i++){
            cnt[mask&a[i]]++;
        //    printf("%d ",mask&a[i]);
        }
        
        for(int i = mask;i>=0;i--){
            cnt[i]+=cnt[i+1];
        }
        LL tot=0;
        for(int i = 0;i<n;i++){
            if(a[i]&(1<<t))tot+=n-1;
        }
     //   printf("%lld\n",tot);
        for(int i = 0;i<(1<<t)/2;i++){
            tot+=(LL)(cnt[i]-cnt[i+1])*cnt[(1<<t)-i];
        }
        if(t!=0){
            LL add=(cnt[(1<<t)/2])*(cnt[(1<<t)/2]-1);
            add/=2;
            tot+=add;
        }

      //  printf("!%d %d\n",t,tot);
        if(tot&1)ans+=(1<<t);
    }
    printf("%d\n",ans);
}