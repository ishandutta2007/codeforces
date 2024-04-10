#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 505
vector<LL> ans;
map<LL,int> ans2;
LL a[505];
int mod=998244353;
int main(){
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        int ok=0;
        LL Min=1,Max=5e4;
        while(Min+1<Max){
            LL mid=(Min+Max)/2;
            if(mid*mid*mid*mid>a[i]){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        if(Min*Min*Min*Min==a[i]){
            for(int i=0;i<4;i++)
            ans.pb(Min);
            ok=1;
        }
        Min=1,Max=2e6;
        while(Min+1<Max){
            LL mid=(Min+Max)/2;
            if(mid*mid*mid>a[i]){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        if(!ok&&Min*Min*Min==a[i]){
            for(int i=0;i<3;i++)
            ans.pb(Min);
            ok=1;
        }
        Min=1,Max=2e9;
        while(Min+1<Max){
            LL mid=(Min+Max)/2;
            if(mid*mid>a[i]){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        if(!ok&&Min*Min==a[i]){
            for(int i=0;i<2;i++)
            ans.pb(Min);
            ok=1;
        }
        if(!ok){
            ans2[a[i]]++;
        }
    }
    LL ret=1;
    for(auto it:ans2){
        int ok=0;
      //  printf("%lld\n",it.x);
        for(int i=1;i<=n;i++){
            if(a[i]==it.x)
            continue;
            LL gcd=__gcd(a[i],it.x);
           // printf("%d %d\n",gcd,it.x,a[i]);
            if(gcd!=1){
              //  printf("%lld\n",gcd);
                ok=1;
                for(int j=0;j<it.y;j++){
                    ans.pb(gcd);
                    ans.pb(it.x/gcd);
                }
                break;
            }    
        }
        if(!ok){
            ret*=(it.y+1)*(it.y+1);
         //   printf("%d\n",it.y);
            ret%=mod;
        }
    }
    sort(ans.begin(),ans.end());
    int cnt=0;
    LL last=0;
    for(auto it:ans){
       // printf("%d ",it);
        if(it!=last){
            ret*=(cnt+1);
     //       printf("%lld %d\n",it,cnt);
            ret%=mod;
            cnt=0;
            last=it;
        }
        cnt++;
    }
    ret*=(cnt+1);
   // printf("%d\n",cnt);
    ret%=mod;
    printf("%lld\n",ret);
    fflush(stdout);
}
/*
99999909670000297
99999909670000297
99999909670000297
99999909670000297
99999909670000297
999982999989000187
999982999989000187
999982999989000187
999982999989000187
999982999989000187
4999999999945
4999999999945
4999999999945
699999999999999979
699999999999999979
99999909670000297
99999909670000297
99999909670000297
99999909670000297
99999909670000297
999982999989000187
999982999989000187
999982999989000187
999982999989000187
999982999989000187
4999999999945
4999999999945
4999999999945
699999999999999979
699999999999999979



*/