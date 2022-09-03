#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> factor[200005];
int main(){ 
    for(int i = 1;i<=200000;i++){
        for(int j  =i;j<=200000;j+=i)factor[j].pb(i);
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int p[200005],c[200005],vis[200005];
        fill(vis,vis+n+1,0);
        for(int i = 1;i<=n;i++)scanf("%d",&p[i]);
        for(int i = 1;i<=n;i++)scanf("%d",&c[i]);
        int ans=n;
        for(int i = 1;i<=n;i++){
            vector<int> v,tmp;
            int now=i;
            while(!vis[now]){
                v.pb(c[now]);
                vis[now]=v.size();
                now=p[now];
            }
            for(int i = vis[now]-1;i<v.size();i++){
                tmp.pb(v[i]);
            }
            for(auto it:factor[tmp.size()]){
                for(int i = 0;i<it;i++){
                    int ok=1;
                    for(int j=i;j<tmp.size();j+=it){
                        if(tmp[j]!=tmp[i])ok=0;
                    }
                    if(ok){
                        ans=min(ans,it);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*

5
AACCMMAA
A
AA
MM
ACA
ACMAA


5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/

/*
 

*/