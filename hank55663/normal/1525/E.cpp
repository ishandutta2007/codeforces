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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[20][50005];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    LL sum=0;
    LL tot=1;
    for(int i = 1;i<=n;i++)tot=tot*i%mod;
    for(int j = 0;j<m;j++){
        int cnt[55];
        fill(cnt,cnt+55,0);
        for(int i = 0;i<n;i++){
            cnt[a[i][j]]++;
        }
        LL res=1,ttot=0;
        for(int j = n+1;j>=2;j--){
            ttot+=cnt[j];
            res*=ttot;
            res%=mod;
            ttot--;
        }
        sum+=((tot-res)%mod+mod)%mod;
      //  printf("%d\n",tot,res);
        sum%=mod;
    }
    printf("%lld\n",sum*f_pow(tot,mod-2)%mod);
}
int main(){
    int t=1;
 //   scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
a b
b a
b a a
a a b
a a b b
a b b a
a b b a a
a b a a b
a b a b a

*/