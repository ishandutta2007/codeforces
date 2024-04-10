#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int mod=1e9+9;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main() {
    int n,a,b,k;
    scanf("%d %d %d %d",&n,&a,&b,&k);
        char c[100005];
        scanf("%s",c);
        LL mul=f_pow(b,k)*f_pow(f_pow(a,k),mod-2)%mod;
        LL ans[100005];
        LL res=0;
        for(int i=0;i<k&&i<=n;i++){
            ans[i]=f_pow(a,n-i)*f_pow(b,i)%mod;
            //printf("%lld ",ans[i]);
        }
       // printf("\n");
        //printf("%d\n",mul);
        for(int i=0;i<k&&i<=n;i++){
            LL l=(n-i)/k;
          //  printf("%d\n",l);
            LL ret=ans[i]*(f_pow(mul,l+1)-1)%mod*f_pow(mul-1,mod-2)%mod;
            if(mul==1)
            ret=(l+1)*ans[i]%mod;
            if(c[i]=='-')
            res-=ret;
            else
            res+=ret;
            res%=mod;
        }
        printf("%lld\n",(res%mod+mod)%mod);
	
}