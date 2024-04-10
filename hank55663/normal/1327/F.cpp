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
//pair<pii,int> p[500005];
vector<pii> v[500005];
//int dp[500005];
LL mod=998244353;
int main(){ 
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    for(int i = 0;i<m;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        //p[i]=mp(mp(r,l),x);
        v[r].pb(mp(l,x));
    }
    LL ans=1;
    for(int i = 0;i<k;i++){
       // dp[0]=1;
        int l=0,r=0,sum=1;
        deque<pii> q;
        q.pb(mp(0,1));
        for(int j =1;j<=n;j++){
            r++;
          //  dp[r]=sum; 
            q.pb(mp(r,sum));
            sum+=sum;
            sum%=mod;
            for(auto it:v[j]){
                if(1<<i&(it.y)){
                    while(!q.empty()&&q.back().x>=it.x){
                        sum-=q.back().y;
                        q.pop_back();
                        sum=(sum%mod+mod)%mod;
                    }
                }
                else{
                    while(!q.empty()&&q.front().x<it.x){
                        sum-=q.front().y;
                        q.pop_front();
                        sum=(sum%mod+mod)%mod;
                    }
                }
            }
        }
        ans*=sum;
        ans%=mod;
    }
    printf("%lld\n",ans);
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