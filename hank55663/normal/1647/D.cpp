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
#define MXN 2005
void solve(){
    LL x,d;
    scanf("%lld %lld",&x,&d);
    int ok=0;
    int val,tt=0;
    for(int j = 2;j*j<=d;j++){
        if(d%j==0){
            int t=d;
            while(t%j==0)t/=j,tt++;
            if(t!=1)ok=1;
            else val=j;
            break;
        }
    }
    if(tt==0)val=d,tt=1;
   // printf("? %d %d\n",val,ok);
    if(x%(d*d)==0){
        x/=d;
        int cnt=0;
        int tot=2;
        do{
            x/=d;
            for(int i = 1;i*i<=x;i++){
                if(x%i==0){
                    int a=i,b=x/i;
                    if(a%d==0||b%d==0){
                        int need=3;
                        if(ok);
                        else{
                            int tot=0;
                            int tmp=i;
                            while(tmp%val==0)tot++,tmp/=val;
                            tmp=x/i;
                            while(tmp%val==0)tot++,tmp/=val;
                            if(tt!=1){
                                need=(tot+tt-2)/(tt-1);
                            }
                            else{
                                need=1e9;
                            }
                        }
                       // printf("%d %d\n",need,tt);
                        if(need<=tot)cnt++;
                    }

                    else{
                        cnt++;
                    }
                  //  printf("%d %d %d %d\n",x,a,b,cnt);
                  //  printf("YES\n");
                    //return;
                }
            }
            tot++;
        }while(x%d==0);
        if(cnt>=2)printf("YES\n");
        else printf("NO\n");
    }
    else{
        printf("NO\n");
    }
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
*/