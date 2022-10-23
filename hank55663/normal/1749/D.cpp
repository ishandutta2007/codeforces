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
LL isprime[300005];
void build(){
    fill(isprime,isprime+300005,1);
    for(int i = 2;i<300005;i++){
        for(int j = i*2;j<300005;j+=i){
            isprime[j]=0;
        }
    }
    isprime[1]=0;
}
const int mod=998244353;
void solve(int T){
    build();
    int n;
    LL m;
    scanf("%d %lld",&n,&m);
    LL ans=1;
    LL tres=0;
    LL lcm=1;
    LL res=1;
    LL tot=0;
    for(int i=1;i<=n;i++){
        if(isprime[i]){
           if(lcm<=m)
           lcm*=i;
        }
        ans*=m/lcm%mod;
        ans%=mod;
        tres+=ans;
        tres%=mod;
       res*=m%mod;
       res%=mod;
       tot+=res;
       tot%=mod;
    }
    printf("%lld\n",((tot-tres)%mod+mod)%mod);
}

int main(){
  //  srand(time(NULL));
    int t=1;
    //scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*575855273
1
2 4
3 
5
*/