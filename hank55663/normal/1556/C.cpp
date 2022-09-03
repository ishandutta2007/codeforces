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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    LL c[1005];
    LL ans=0;
    map<int,int> m;
    LL ans2=0;
    m[0]++;
    LL now=0;
    for(int i = 0;i<n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i = 0;i<n;i+=2){
        LL sum=0;
        LL Min=1e9;
        for(int j = i;j<n;j++){
            if(j%2==0)sum+=c[j];
            else{
                sum-=c[j];
                if(sum>0){
                    ans+=max(min(min(c[i]-sum,c[j]),Min+1-sum),0ll);
                }
                else if(sum==0){
                    ans+=min(min(c[j],c[i]),Min+1);
                }
                else if(sum<0){
                    ans+=max(min(min(c[i],c[j]+sum),Min+1),0ll);
                    break;
                }
            }
            Min=min(Min,sum);
             // printf("%lld %lld %lld\n",ans,sum,Min);
        }
      //  printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
*/