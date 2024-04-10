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
#define pdd pair<double,double>
#define cpdd const pdd
    int l[200005],r[200005];
    int vis[200005];
    LL dp[200005][2];
int main(){
    int n,m,k,q;
    scanf("%d %d %d %d",&n,&m,&k,&q);

    fill(l,l+n+1,1e9);
    fill(r,r+n+1,0);
    fill(vis,vis+n+1,0);
    l[1]=r[1]=1;
    vis[1]=1;
    l[0]=r[0]=1;
    dp[0][0]=dp[0][1]=-1;
    int Max=0;
    for(int i = 0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        l[a]=min(l[a],b);
        r[a]=max(r[a],b);
        vis[a]++;
        Max=max(Max,a);
    }
    vector<int> safe;
    for(int i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        safe.pb(x);
    }
    sort(safe.begin(),safe.end());
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            l[i]=l[i-1];
            r[i]=r[i-1];
        }
    }
    for(int i = 1;i<=Max;i++){
        if(vis[i]){
            if(i==1){
                dp[i][0]=r[i]-l[i]+r[i]-1;
                dp[i][1]=r[i]-1;
                continue;
            }
            //dp[i-1][0]->safe+1->r[i]->l[i];
            //dp[i-1][1]->safe+1->r[i]->l[i];
            dp[i][0]=dp[i][1]=1e18;
            auto it=lower_bound(safe.begin(),safe.end(),l[i-1]);
            if(it!=safe.end()){
                dp[i][0]=dp[i-1][0]+*it-l[i-1]+1+abs(r[i]-*it)+r[i]-l[i];
                dp[i][1]=dp[i-1][0]+*it-l[i-1]+1+abs(l[i]-*it)+r[i]-l[i];
            }
            if(it!=safe.begin()){
                it--;
                dp[i][0]=min(dp[i][0],dp[i-1][0]+l[i-1]-*it+1+abs(r[i]-*it)+r[i]-l[i]);
                dp[i][1]=min(dp[i][1],dp[i-1][0]+l[i-1]-*it+1+abs(l[i]-*it)+r[i]-l[i]);
            }
            it=lower_bound(safe.begin(),safe.end(),r[i-1]);
            if(it!=safe.end()){
                dp[i][0]=min(dp[i][0],dp[i-1][1]+*it-r[i-1]+1+abs(r[i]-*it)+r[i]-l[i]);
                dp[i][1]=min(dp[i][1],dp[i-1][1]+*it-r[i-1]+1+abs(l[i]-*it)+r[i]-l[i]);
            }
            if(it!=safe.begin()){
                it--;
                dp[i][0]=min(dp[i][0],dp[i-1][1]+r[i-1]-*it+1+abs(r[i]-*it)+r[i]-l[i]);
                dp[i][1]=min(dp[i][1],dp[i-1][1]+r[i-1]-*it+1+abs(l[i]-*it)+r[i]-l[i]);
            }
        }
        else{
            dp[i][0]=dp[i-1][0]+1;
            dp[i][1]=dp[i-1][1]+1;
        }
    //    printf("%lld %lld\n",dp[i][0],dp[i][1]);
    }
    printf("%lld\n",min(dp[Max][0],dp[Max][1]));
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */