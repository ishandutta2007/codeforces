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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define MXN 200005
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL fra[1000005];
LL inv[1000005];
void build(){
    fra[0]=1;
    for(int i = 1 ; i <= 1000000 ; i++)
        fra[i] = fra[i-1] *i% mod;
    inv[1000000]=f_pow(fra[1000000],mod-2);
    for(int i = 999999 ; i >= 0 ; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
LL C(int a,int b){
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
int pool[2][1000005];
int* cal[2];
int l[1000005];
int r[1000005];
int q[1000005];
int main(){
    build();
    cal[0]=pool[0]+1;
    cal[1]=pool[1]+1;
    char c[1000005];
    scanf("%s",c+1);
    int len=strlen(c+1);
    for(int i = 1;c[i]!=0;i++){
        l[i]=l[i-1];
        r[i]=r[i-1];
        q[i]=q[i-1];
        if(c[i]=='(')l[i]++;
        if(c[i]==')')r[i]++;
        if(c[i]=='?')q[i]++;
    }
    int cnt=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='?')cnt++;
    }
    for(int i = 0;i<=cnt;i++){
        cal[0][i]=(cal[0][i-1]+C(cnt,i))%mod;    
    }
    for(int i =0;i<cnt;i++){
        cal[1][i]=(cal[1][i-1]+C(cnt-1,i))%mod;
    }
    LL ans=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]==')')continue;
        int ll=l[i-1];
        int rr=r[len]-r[i];
        int lq=q[i-1],rq=q[len]-q[i];
       // printf("%d %d\n",cnt,rq+rr-ll);
        if(c[i]=='?'){
         //   printf("? %d %d\n",min(rq+rr-ll-1,cnt-1),cal[1][min(rq+rr-ll-1,cnt-1)]);
            if(rq+rr-ll>=0)
            ans+=cal[1][min(rq+rr-ll-1,cnt-1)];
        }
        else{
            if(rq+rr-ll>=0)
            ans+=cal[0][min(rq+rr-ll-1,cnt)];
        }
    }
    printf("%lld\n",ans%mod);
}