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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=1e9+7;
void solve(){
    int n=rand()%500+1,k=rand()%n+1;
    scanf("%d %d",&n,&k);
  // printf("%d %d\n",n,k);
    if(n%2==1&&k%2==0){
        printf("-1\n");
        fflush(stdout);
        return;
    }
    pii cnt[505];
    for(int i = 1;i<=n;i++)cnt[i]=mp(1,i);
    int tot=n;
    for(int i = 1;i<=n;i++){
        if(tot%k!=0){
            cnt[i].x+=2;
            tot+=2;
        }
    }
    int ans=0;
    while(tot){
        int t=k;
        int cnt2=0;
        for(int i = 1;i<=n;i++){
            if(cnt[i].x){
                cnt2++;
            }
        }
      //  printf("%d\n",cnt2);
        while(cnt2<k){
            sort(cnt+1,cnt+n+1);
            reverse(cnt+1,cnt+n+1);
            cnt[n].x+=2;
            tot+=2;
            for(int i = n-1;i>=1;i--){
                if(tot%k!=0){
                    cnt[i].x+=2;
                    tot+=2;
                }
            }  
            cnt2=0;
            for(int i = 1;i<=n;i++){
                if(cnt[i].x){
                    cnt2++;
                }
            }
          //  printf("%d\n",cnt2);
        }
          // printf(" 5:%d\n",t);
        sort(cnt+1,cnt+n+1);
        reverse(cnt+1,cnt+n+1);
        //for(int i = 1;i<=n;i++){
        //    printf("%d ",cnt[i].x);
       // //}
       // printf("\n");
        printf("?");
        for(int i=1;i<=n;i++){
            if(cnt[i].x){
                printf(" %d",cnt[i].y);
                cnt[i].x--;
                t--;
                tot--;
            }
            if(!t)break;
        }
      //   for(int i = 1;i<=n;i++){
      //      printf("%d ",cnt[i].x);
      //  }
       // printf("\n");
        printf("\n");    
      //  printf("%d\n",t);
      //  assert(t==0);
        //tot-=k;

        fflush(stdout);
        int x=rand()%n+1;
        scanf("%d",&x);
        ans^=x;
       // getchar();
    }
    printf("! %d\n",ans);
      fflush(stdout);
      
}
int main(){
    int t=100;
    //scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/