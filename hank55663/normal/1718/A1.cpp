#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int dp[500005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[500005];
    int cnt=0;
    int tot=0;
    int now=0;
    map<int,int> m;
    m[0]=0;
    vector<pii> v;
    dp[0]=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        now^=a[i];
        dp[i]=dp[i-1];
        if(m.find(now)!=m.end()){
            dp[i]=max(dp[i],dp[m[now]]+1);
        }
        m[now]=i;
        //cnt++;
        //if(now==0)tot+=cnt-1,cnt=0;
    }
    printf("%d\n",n-dp[n]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}

/*
*/