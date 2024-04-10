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
char c[5005];
int f[5005];
int ok[5005][5005];
void KMP(char *c){
    f[0]=-1;
    int j=-1;
    for(int i=1;c[i]!=0;i++){
        while(j!=-1&&c[i]!=c[j+1])j=f[j];
        if(c[i]==c[j+1])j++;
        f[i]=j;
    }
}
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    scanf("%s",c+1);
    for(int i=1;c[i]!=0;i++){
        KMP(c+i);
        int temp=-1;
        for(int j=i+1;c[j]!=0;j++){
            while(temp!=-1&&c[j]!=c[i+temp+1])temp=f[temp];
            if(c[j]==c[i+temp+1])temp++;
            while(j-i+1<(temp+1)*2)temp=f[temp];
            int k=temp;
            while(!ok[j][k+1]&&k!=-1){
               // printf("%d %d %d\n",i,j,k+1);
                ok[j][k+1]=1;
                k=f[k];
               // if(k==-1)
                //break;
            }
        }
    }
    int dp[5005];
    dp[0]=0;
    for(int i=1;c[i]!=0;i++){
        dp[i]=dp[i-1]+a;
        for(int j=1;j<=i/2;j++){
            if(ok[i][j]){
                dp[i]=min(dp[i-j]+b,dp[i]);
            }
        }
       // printf("%d ",dp[i]);
    }
    printf("%d\n",dp[n]);
}