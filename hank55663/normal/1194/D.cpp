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
int dp[100005];
int DP(int x,int k){
    if(x<0)return 1;
    if(dp[x]!=-1)return dp[x];
    if(DP(x-1,k)==0||DP(x-2,k)==0||DP(x-k,k)==0){
        return dp[x]=1;
    }
    else{
        return dp[x]=0;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(k%3!=0){
            if(n%3==0)printf("Bob\n");
            else printf("Alice\n");
        }
        else{
            if(n<k){
                if(n%3==0)printf("Bob\n");
                else printf("Alice\n");
            }
            else{
                if((n)%(k+1)%3==0&&n%(k+1)!=k){
                    printf("Bob\n");
                }
                else{
                    printf("Alice\n");
                }
            }
        }
    }
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */