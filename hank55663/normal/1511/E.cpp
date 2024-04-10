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
const int mod=998244353;;
LL p2[300005];
void solve(){
    p2[0]=1;
    for(int i = 1;i<300005;i++)p2[i]=p2[i-1]*2%mod;
    vector<string> v;
    int n,m;
    scanf("%d %d",&n,&m);
    int tot=0;
    for(int i = 0;i<n;i++){
        char c[300005];
        scanf("%s",c);
        v.pb(string(c));
        for(int j = 0;j<m;j++){
            if(c[j]=='o')tot++;
        }
    }
    LL ans=0;
    for(int i = 0;i<n;i++){
        int cnt=0;
        LL sum=0;
        for(int j = 0;j<m;j++){
            if(v[i][j]=='o')cnt++;
            else cnt=0,sum=0;
            if(cnt%2&&cnt>=3){
                sum+=p2[tot-cnt];
                sum%=mod;
            }
            if(cnt%2)ans+=sum;
            else if(cnt>=2) ans+=sum,ans+=p2[tot-cnt];
          //  printf("%lld\n",ans);
        }
    }
     for(int i = 0;i<m;i++){
        int cnt=0;
        LL sum=0;
        for(int j = 0;j<n;j++){
            if(v[j][i]=='o')cnt++;
            else cnt=0,sum=0;
            if(cnt%2&&cnt>=3){
                sum+=p2[tot-cnt];
                sum%=mod;
            }
            if(cnt%2)ans+=sum;
            else if(cnt>=2)ans+=sum,ans+=p2[tot-cnt];
        }
    }
    printf("%lld\n",ans%mod);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}