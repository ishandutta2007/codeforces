#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[3005];
pll p[3005];
vector<vector<int> > v;
int k;
LL ans=0;
void dc(int l,int r){
    if(l==r){
        LL sum=0;
        for(int i = 0;i<=v[l].size()&&i<=k;i++){
            ans=max(ans,sum+dp[k-i]);
            if(v[l].size()!=i)
            sum+=v[l][i];
        }
        return;
    }
    else{
        LL tmp[3005];
        for(int i = 0;i<k;i++)tmp[i]=dp[i];
        int mid=(l+r)/2;
        for(int i = l;i<=mid;i++){
            for(int j = k;j>=p[i].y;j--){
                dp[j]=max(dp[j],dp[j-p[i].y]+p[i].x);
            }
        }
        dc(mid+1,r);
        for(int i = 0;i<k;i++)dp[i]=tmp[i];
        for(int i = mid+1;i<=r;i++){
            for(int j = k;j>=p[i].y;j--){
                dp[j]=max(dp[j],dp[j-p[i].y]+p[i].x);
            }
        }
        dc(l,mid);
        for(int i = 0;i<k;i++)dp[i]=tmp[i];
    }
}
void solve(){   
    int n;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        vector<int> tmp;
        LL sum=0;
        for(int j = 0;j<x;j++){
            int y;
            scanf("%d",&y);
            tmp.pb(y);
            sum+=y;
        }
        p[i]=mp(sum,x);
        v.pb(tmp);
    }
    dc(0,n-1);
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/