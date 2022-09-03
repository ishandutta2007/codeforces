#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
LL mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a%mod;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    pll p[200005];
    LL pre[200005];
    pre[0]=1;
    p[0]=mp(0,0);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i].x);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i].y);
    }
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]*(p[i].y-p[i].x+1)%mod;
    }
    LL lans1=1;
    LL ans1=(p[1].y-p[1].x+1);
    LL ans2=(p[1].y-p[1].x+1);
    for(int i=2;i<=n;i++){
        LL tot=(p[i].y-p[i].x+1);
        LL l=max(p[i].x,p[i-1].x);
        LL r=min(p[i].y,p[i-1].y);
        LL sum=max(r-l+1,0ll);
        LL ll=max(max(p[i].x,p[i-1].x),p[i-2].x);
        LL rr=min(min(p[i].y,p[i-1].y),p[i-2].y);
        LL sum2=max(rr-ll+1,0ll);
       // printf("%lld %lld\n",ans2,ans1);
        if(i==2)
            ans2=(ans2+2*ans1+pre[i-1])*tot-2*sum*(lans1)-sum*pre[i-2];
        else
            ans2=(ans2+2*ans1+pre[i-1])*tot-2*(sum*(lans1+pre[i-2])-sum2*pre[i-3])-sum*pre[i-2];
        ans2%=mod;
        ans2+=mod;
        ans2%=mod;
        lans1=ans1;
        ans1=ans1*tot+pre[i]-pre[i-2]*sum;
        ans1%=mod;
        
    }
    printf("%lld\n",ans2*f_pow(pre[n],mod-2)%mod);
}
/*
1 
2 6 
3 5 
4
*/