#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
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
    int d[200005];
    LL pre[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&d[i]);
    sort(d+1,d+n+1);
    pre[0]=0;
    for(int i = 1;i<=n;i++)pre[i]=pre[i-1]+d[i];//)%mod;
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        int idx=lower_bound(d+1,d+n+1,b)-d;
        int tot=n-idx+1;
       // printf("%d %d\n",idx,tot);
        if(tot<a){
            printf("0\n");
        }
        else{
            LL pa=pre[idx-1]%mod,pb=(pre[n]-pre[idx-1])%mod;
           // printf("%lld %lld\n",pa,pb);
            printf("%lld\n",(pb*(tot-a)%mod*f_pow(tot,mod-2)%mod+pa*(tot+1-a)%mod*f_pow(tot+1,mod-2)%mod)%mod);
        }
    }

}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}