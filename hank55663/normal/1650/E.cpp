#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
const int mod=1e9+7;
#define MXN 2005
void solve(){
    int n,d;
    scanf("%d %d",&n,&d);
    int a[200005];
    a[n]=d+1;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int Max=d,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int cnt=0;
        int ok[200005];
        int now=mid+1;
        fill(ok,ok+n+1,0);
        for(int i = 0;i<n;i++){
            if(a[i]>=now){
                ok[i]=1;
                now=a[i]+mid+1;
                cnt++;
              //  printf("%d %d\n",i,now);
            }
        }
        ok[n]=1;
      //  printf("\n");
       // printf("!%d %d\n",mid,cnt);
        if(cnt<n-1){
            Max=mid;
        }
        else if(cnt==n)Min=mid;
        else {
            int go=0;
            int last=0;
            int x=0;
            for(int i = 0;i<=n;i++){
                if(ok[i]){
                    //printf("!%d\n",a[i]-last);
                    if(a[i]-last-1>mid*2)go=1;
                    if(i==n&&a[i]-last-1>mid)go=1;
                    last=a[i];
                }
                else{
                    x=i;
                }
            }
            if(x!=0){
                ok[x]=1;
                ok[x-1]=0;
                last=0;
                int ook=1;
                for(int i = 0;i<=n;i++){
                    if(ok[i]){
                      //  printf("!%d\n",a[i]-last);
                        if(a[i]-last-1>mid*2)ook++;
                        if(i!=n)
                        if(a[i]-last<=mid)ook--;
                        last=a[i];
                    }
                }
                if(ook==2)go=1;
            }
            if(go)Min=mid;
            else Max=mid;
        }
        

    }
            printf("%d\n",Min);
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/