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
    int n;
    scanf("%d",&n);
    pii p[6005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        int cnt[2][2];
        MEM(cnt);
        for(int j = 0;j<n;j++){
            int a=0,b=0;
            if(i==j)continue;
            if((p[j].x-p[i].x)%4)a=1;
            if((p[j].y-p[i].y)%4)b=1;
            cnt[a][b]++;
        }
        for(int i = 0;i<2;i++){
            for(int j=0;j<2;j++){
           //     printf("%d ",cnt[i][j]);
            }
          //  printf("\n");
        }
        for(int x1=0;x1<2;x1++){
            for(int y1=0;y1<2;y1++){
                for(int x2=x1;x2<2;x2++){
                    for(int y2=y1;y2<2;y2++){
                        int S=0;//(x1*y2+x2*y1)%2;
                        int edge=0;
                        if(x1||x2)edge++;
                        if(y1||y2)edge++;
                        if(x1!=y1||x2!=y2)edge++;
                        edge%=2;
                         int last=ans;
                        if(S==edge){
                           
                            if(x1==x2&&y1==y2){
                                ans+=cnt[x1][y1]*(cnt[x1][y1]-1)/2;
                            }
                            else{
                                ans+=cnt[x1][y1]*cnt[x2][y2];
                            }
                        }
                        if(last!=ans){
                          //  printf("%d %d %d %d\n",x1,y1,x2,y2);
                        }
                    }
                }
            }
        }
    //    printf("%lld\n",ans);
    }
   // printf("%lld\n",ans);
    printf("%lld\n",ans/3);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
*/