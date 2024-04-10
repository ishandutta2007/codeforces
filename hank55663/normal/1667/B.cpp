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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
    LL dp[500005];
    LL dp2[500005];
void solve(){
    int n=10;
    scanf("%d",&n);
    int a[500005];
    map<LL,LL> m,m2;
    LL sum=0;
    m[0]=0;
    m2[0]=0;

    dp2[0]=0;
    dp[0]=0;
    LL ans=-2e18;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        //a[i]=rand()%10-5;
        //printf("%d ",a[i]);
        sum+=a[i];
       // for(auto it:m)printf("%d %d\n",it.x,it.y);
        if(m.lower_bound(sum)==m.begin()){
            if(a[i]==0)
            dp[i]=dp[i-1];
            else 
            dp[i]=dp[i-1]-1;
            if(m2.find(sum)!=m2.end())dp[i]=max(dp[i],m2[sum]);
        }
        else{
            if(a[i]==0)dp[i]=dp[i-1];
            else if(a[i]>0)dp[i]=dp[i-1]+1;
            else dp[i]=dp[i-1]-1;
          //  printf("%d ",dp[i]);
            auto it=prev(m.lower_bound(sum));
            int val=it->y;
            dp[i]=max(it->y+i,dp[i]);
            if(m2.find(sum)!=m2.end())dp[i]=max(dp[i],m2[sum]);
        }
        if(m2.find(sum)!=m2.end())
        m2[sum]=max(m2[sum],dp[i]);
        else
        m2[sum]=dp[i];
        if(m.find(sum)!=m.end())m[sum]=max(m[sum],dp[i]-i);
        else m[sum]=dp[i]-i;
        auto it=m.find(sum);
        if(it!=m.begin()&&prev(it)->y>=m[sum])m.erase(sum);
        else{
            it=next(it);
            while(it!=m.end()){
                if(it->y<=m[sum]){
                    LL x=it->x;
                    it=next(it);
                    m.erase(x);
                }
                else{
                    break;
                }
            }
        }
    }
   /* printf("\n");
    for(int i = 1;i<=n;i++){
        LL sum=0;
        dp2[i]=-1e18;
        for(int j = i;j>=1;j--){
            sum+=a[j];
            if(sum<0)dp2[i]=max(dp2[i],dp2[j-1]-(i-j+1));
            else if(sum==0)dp2[i]=max(dp2[i],dp2[j-1]);
            else dp2[i]=max(dp2[i],dp2[j-1]+(i-j+1));
        }
        printf("%lld %d\n",dp[i],dp2[i]);
        assert(dp[i]==dp2[i]);
    }*/
    printf("%lld\n",dp[n]);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/