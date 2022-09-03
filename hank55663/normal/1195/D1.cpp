#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define N (1<<20)
int mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    LL ans=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        int tmp=a[i];
        vector<int> v;
        while(tmp){
            v.pb(tmp%10);
            tmp/=10;
        }
        reverse(v.begin(),v.end());
        LL value=0;
        for(auto it:v){
            value*=100;
            value+=it;
            value%=mod;
        }
        ans+=value%mod*n%mod;
        ans%=mod;
        ans+=value*10%mod*n%mod;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/