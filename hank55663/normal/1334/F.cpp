#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
LL S[500005];
void add(int x,int k){
   // printf("a%d %d\n",x,k);
    if(x==0)return;
    for(int i = x;i<500005;i+=i&-i){
        S[i]+=k;
    }
}
LL query(int x){
    if(x<0)return 0;
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    //printf("q%d %lld\n",x,res);
    return res;
}
LL dp[500005];
vector<int> v[500005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    int p[500005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        add(i,p[i]);
    }
    v[n+1].pb(n+1);
    fill(dp,dp+n+1,1e18);
    int m;
    dp[0]=0;
    scanf("%d",&m);
    v[0].pb(0);
    int last=1;
    for(int i = 0;i<=m;i++){
        int x;
        if(i==m)x=n+1;
        else
        scanf("%d",&x);
        LL Min=1e18;
        int now=0;
        int lasti=0;
        last--;
        for(auto it:v[x]){
            Min+=query(it-1)-query(lasti-1);
            while(now<v[last].size()&&v[last][now]<it){
                Min=min(Min,dp[v[last][now]]+query(it-1)-query(v[last][now]));
          //      printf("qq%d %d %lld\n",last,v[last][now],dp[v[last][now]]);
                now++;
            }
            dp[it]=Min;
            lasti=it;
        //    printf("%lld %d %lld\n",Min,it,dp[it]);
        }
        last++;
       // printf("!\n");
        while(last<=x){
            for(auto it:v[last]){
                add(it,min(-p[it],0));
            }
            last++;
         //   printf("%d %d\n",last,x);
        }
        //printf("?\n");
    }
    if(dp[n+1]>1e16){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    printf("%lld\n",dp[n+1]);
}
/*
1 2 1 3 1 4 1....1 n 2 3 2 4 2 5 2 6....2 n
*/