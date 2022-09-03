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
#define N 100005
#define MXN 2000005
int a[200005];
int instk[200005];
int vis[200005];
int t;
const int mod=1e9+7;
int go(int x){
    if(instk[x]){
        return t-instk[x];
    }
    if(vis[x])return 0;
    vis[x]=instk[x]=t++;
    int res=go(a[x]);
    instk[x]=0;
    return res;
}
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
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

    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL res=1;
    LL tot=n;
    for(int i = 1;i<=n;i++){
        LL sum=go(i);
        tot-=sum;
        if(sum)
        res=res*(f_pow(2,sum)-2)%mod;
    }
    res=res*f_pow(2,tot)%mod;
    printf("%lld\n",res);
    return 0;
}