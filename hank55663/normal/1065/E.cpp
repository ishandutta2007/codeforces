#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int mod=998244353;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    int b[200005];
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    LL ans=f_pow(s,n-2*b[m-1]);
    int last=0;
    for(int i=0;i<m;i++){
        int x=b[i]-last;
        //printf("%lld\n",(f_pow(s,2*x)+f_pow(s,x))*f_pow(2,mod-2)%mod);
        ans=ans*(f_pow(s,2*x)+f_pow(s,x))%mod*f_pow(2,mod-2)%mod;
        last=b[i];
    }
    printf("%lld\n",ans);
}