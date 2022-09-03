
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll

typedef long long LL;
LL dp[100005][105];
LL tot[100005];
int mod=998244353;
int main(){
    int n,k,len;
    int num[100005];
    scanf("%d %d %d",&n,&k,&len);
    for(int i=1;i<=n;i++)
    scanf("%d",&num[i]);
    if(len==1){
        printf("0\n");
        return 0;
    }
    queue<LL> q[105];
    LL sum[105];
    MEM(sum);
    for(int i=1;i<=k;i++){
        q[i].push(1);
        sum[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(num[i]==-1){
            for(int j=1;j<=k;j++)
            dp[i][j]=sum[j];
        }
        else{
            dp[i][num[i]]=sum[num[i]];
            for(int j=1;j<=k;j++){
                if(j!=num[i]){
                    while(!q[j].empty())q[j].pop();
                    sum[j]=0;
                }
            }
        }
        tot[i]=0;
        for(int j=1;j<=k;j++)
        tot[i]+=dp[i][j];
        tot[i]%=mod;
        for(int j=1;j<=k;j++){
            sum[j]+=tot[i]-dp[i][j];
            sum[j]=(sum[j]%mod+mod)%mod;
            q[j].push(tot[i]-dp[i][j]);
            if(q[j].size()>=len){
              //  printf("%d ",q[j].front());
                sum[j]=((sum[j]-q[j].front())%mod+mod)%mod;
                q[j].pop();
            }
        }
       // printf("\n");
    }
    LL res=0;
    for(int i=1;i<=k;i++)
    res+=dp[n][i];
    printf("%lld\n",res%mod);
}