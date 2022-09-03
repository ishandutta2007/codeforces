#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[1000005];
int val[22];
int vis[30000005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL ans=1;
    for(int i = 2;i<=n;i++){
        if(v[i].empty()){
            for(int j = i;j<=n;j+=i)v[j].pb(i);
        }
    }
    for(int i = 1;i<=20;i++){
        for(int j = 1;j<=m;j++){
            if(!vis[j*i]){
                vis[j*i]++;
                val[i]++;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        int tmp=i;
        int gcd=0;
        for(auto it:v[i]){
            int cnt=0;
            while(tmp%it==0){
                cnt++;
                tmp/=it;
            }
            gcd=__gcd(gcd,cnt);
        }
        ans+=val[gcd];
        /*
        if(gcd==1)ans+
        else
        for(int j=2;j<=gcd;j++){
            if(gcd%j==0){
                ans+=m-m/j;
                break;
            }
        }*/
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
//    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}