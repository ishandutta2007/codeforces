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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int cnt[1000005];
vector<int> v[200005];
void solve(){
    int n,e;
    scanf("%d %d",&n,&e);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v[i%e].pb(cnt[a[i]]);
    }
    LL ans=0;
    for(int i = 0;i<e&&i<n;i++){
        int l=0;
        int sum=0;
        for(int j = 0;j<v[i].size();j++){
            sum+=v[i][j];
            while(sum>1){
                sum-=v[i][l];
                l++;
            }
            ans+=max(j-l,0);
        }
    }
    for(int i = 0;i<e&&i<n;i++){
        int l=0;
        int sum=0;
        for(int j = 0;j<v[i].size();j++){
            sum+=v[i][j];
            while(sum>=1){
                sum-=v[i][l];
                l++;
            }
            ans-=max(j-l,0);
        }
    }
    printf("%lld\n",ans);
    for(int i=0;i<e&&i<n;i++)v[i].clear();
}
int main(){
    for(int i = 2;i<=1000000;i++){
        for(int j = i;j<=1000000;j+=i)cnt[j]++;
    }
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/