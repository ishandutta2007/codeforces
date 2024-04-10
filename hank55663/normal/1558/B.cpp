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
#define MXN 3000000
LL S[4000005];
LL mod;
void add(int x,LL k){
    S[x]=k;
    S[x]+=S[x+1];
    S[x]%=mod;
}
LL query(LL l,LL r){
    if(r>4000000)return S[l];
    return ((S[l]-S[r+1])%mod+mod)%mod;
}
LL S2[4000005];
void solve(){
    int n,p;
    scanf("%d %lld",&n,&mod);
    S2[n]=1;
    S2[n-1]=-1;
    LL sum=0;
    for(int i = n;i>=1;i--){
        sum+=S2[i];
        sum%=mod;
        LL tmp=sum;
       //  printf("%lld ",tmp);
        for(int j=2;j*i<=n;j++){
            tmp+=query(i*j,i*j+j-1);
            tmp%=mod;
        }
        tmp+=mod;
        tmp%=mod;
      //  printf("%lld ",tmp);
        add(i,tmp);
        S2[i-1]+=tmp;
    }
    printf("%lld\n",((S[1]-S[2])%mod+mod)%mod);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
6 4 2 3 5 1
*/