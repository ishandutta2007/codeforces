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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
vector<int> v[300005];
vector<int> prime[300005];
int mobi[300005];
int cnt[300005];
int ok[64];
int dp[64];
int DP(int x){
    if(x==0)return 0;
    if(dp[x]!=-1)return dp[x];
    dp[x]=10;
    for(int j=x;j>0;j=(j-1)&x){
        if(ok[j]){
            dp[x]=min(dp[x],DP(x-j)+1);
        }
    }
    return dp[x];
}
int main(){
    fill(mobi,mobi+300005,1);
    for(int i = 1;i<=300000;i++){
        for(int j = i;j<=300000;j+=i){
            v[j].pb(i);
        }
        if(prime[i].empty()&&i!=1){
            for(int j=i;j<=300000;j+=i){
                prime[j].pb(i);
                mobi[j]=-mobi[j];
            }
        }
    }
    int n;
    scanf("%d",&n);
    int a[300005];
    int gcd=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]),gcd=__gcd(gcd,a[i]);
        for(auto it:v[a[i]]){
            cnt[it]++;
        }
    }
    if(gcd!=1){
        printf("-1\n");
    }
    else{
        for(int i = 0;i<n;i++){
            if(a[i]==1){
                printf("1\n");
                return 0;
            }
        }
        int ans=10;
        int res[300005];
        for(int i = 2;i<=300000;i++){
            int tmp=1;
            int val=(1<<prime[i].size())-1;
            for(auto it:prime[i])
                tmp*=it;
            MEMS(dp);
            MEM(ok);
            //for(auto it:v[a[i]])cnt[it]--;
            for(int j = 1;j<=val;j++){
                int sum=0;
                int tmp2=1;
                for(int k=0;k<prime[i].size();k++){
                    if(j&(1<<k)){
                        tmp2*=prime[i][k];
                    }
                }
                for(auto it:v[tmp2]){
                    sum+=mobi[it]*cnt[it];
                }
                //if(i==255255)printf("%d %d\n",tmp2,sum);
               // printf("%d %d %d\n",a[i],tmp2,sum);
                if(sum)ok[j]=1;
            }
          //  for(auto it:v[a[i]])cnt[it]++;
            res[i]=DP(val);
            //ans=min(ans,DP(val)+1);
        }
        for(int i = 0;i<n;i++){
           // printf("%d ",res[a[i]]);
            ans=min(ans,res[a[i]]+1);
        }
        printf("%d\n",ans);
    }
}
/*
510510

255255
170170
102102
72930
46410
39270
30030

5 3
3 -1 
4 2 
1 1 
5 3 
2 2 
4 1 
3 2 
5 3 

*/