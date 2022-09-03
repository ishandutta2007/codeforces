#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
LL cal(LL x){
    char c[25];
    sprintf(c,"%lld",x);
    LL dp[20][5];
    MEM(dp);
    int now=0;
    for(int i=0;c[i]!=0;i++){
        for(int j=0;j<c[i]-'0';j++){
            if(i==0&&j==0)continue;
            if(j==0){
                dp[i][min(now,4)]++;
            }
            else{
                dp[i][min(now+1,4)]++;
            }
        }
        if(c[i]!='0')
        now++;
    }
    for(int i=1;c[i]!=0;i++){
        dp[i][1]+=9;
    }
    for(int i=0;c[i]!=0;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<10;k++){
                if(k==0)
                    dp[i+1][j]+=dp[i][j];
                else{
                    dp[i+1][min(j+1,4)]+=dp[i][j];
                }
            }
        }
    }
    int len=strlen(c)-1;
  //  printf("%lld\n",dp[len][4]);
    return dp[len][1]+dp[len][2]+dp[len][3];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL l,r;
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",cal(r+1)-cal(l));
    }
    return 0;
}