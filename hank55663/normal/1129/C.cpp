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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
LL dp[3005][3005];
int mod=1e9+7;
LL hash_mod;
unordered_set<LL> myhash[3005];
int main(){
    srand(time(NULL));
    hash_mod=((((LL)rand())<<30)+(((LL)rand())<<15)+rand());
    while(true){
        int ok=1;
        for(LL i=2;i*i<=hash_mod;i++)
            if(hash_mod%i==0){
                ok=0;
                break;
            }
        if(!ok)
        hash_mod++;
        else
        break;
    }
    LL last[3005];
    last[0]=0;
    LL ans=0;
    int m;
    scanf("%d",&m);
    int a[3005];
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            dp[j][0]=1;
           // printf("%d %d\n",i,j);
            dp[j][j-i+1]=0;
            if(j-i+1==1)dp[j][j-i+1]=1;
            else if(j-i+1==2)dp[j][j-i+1]=2;
            else if(j-i+1==3)dp[j][j-i+1]=4;
            else{
                for(int k=1;k<4;k++)
                dp[j][j-i+1]+=dp[j-k][j-i+1-k];
                if(a[j]==1&&a[j-1]==1&&a[j-2]==0&&a[j-3]==0);
                else if(a[j]==1&&a[j-1]==0&&a[j-2]==1&&a[j-3]==0);
                else if(a[j]==0&&a[j-1]==1&&a[j-2]==1&&a[j-3]==1);
                else if(a[j]==1&&a[j-1]==1&&a[j-2]==1&&a[j-3]==1);
                else
                {
                    if(j==3)
                    dp[j][j-i+1]++;
                    else
                    dp[j][j-i+1]+=dp[j-4][j-i+1-4];
                   // printf("%d %d\n",i,j);
                }
                dp[j][j-i+1]%=mod;
            }
          //  printf("%d ",dp[j][j-i+1]);
        }
    }
    for(int i=0;i<m;i++){
        int x=a[i];
        for(int j=i;j>=0;j--){
            last[j+1]=(last[j]*2+x)%hash_mod;
            if(myhash[j+1].find(last[j+1])==myhash[j+1].end()){
                myhash[j+1].insert(last[j+1]);
                ans+=dp[i][j+1];
               // printf("%d ",j+1);
                ans%=mod;
            }
        }
        printf("%lld\n",ans);
    }
}
/*
10101
0101
0 1 0 1
01 0 1
0 10 1
0 1 01
01 01
010 1
0 101
0101
10101
1 0 1 0 1
10 1 0 1
1 01 0 1
1 0 10 1
1 0 1 01
10 10 1
10 1 01
1 01 01
i f f x f l b
*/