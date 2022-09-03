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
const int mod=998244353;
LL fra[400005];
LL inv[400005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    fra[0]=1;
    for(int i = 1;i<=400000;i++)fra[i]=fra[i-1]*i%mod;
    inv[400000]=f_pow(fra[400000],mod-2);
    for(int i = 399999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int n,k;
    scanf("%d %d",&n,&k);
    int s[200005];
    int ra[200005];
    ra[n]=-1;
    for(int i = 0;i<n;i++){
        scanf("%d",&s[i]);
        ra[s[i]]=i;
    }
    vector<int> v;
    v.pb(0);
    for(int i = 0;i<n-1;i++){
        if(ra[s[i]+1]<ra[s[i+1]+1])v.back()++;
        else v.pb(1);
    }
    k-=v.size()-1;
   // printf("%d\n",k);
    if(k<=0){
        printf("0\n");
    }
    else
    //printf("%d %d\n",k,v.size());
    printf("%lld\n",fra[n+k-1]*inv[k-1]%mod*inv[n]%mod);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--)
        solve();
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/