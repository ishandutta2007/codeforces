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
void solve(){
    int n;
    scanf("%d",&n);
    int a[20];
    LL pro=1;
    LL sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        while(a[i]%2==0){
            pro*=2;
            a[i]/=2;
        }
        sum+=a[i];
    }
    LL ans=sum;
    for(int i = 0;i<n;i++){
        ans=max(ans,sum-a[i]+a[i]*pro);
    }
    printf("%lld\n",ans);
}
int main(){
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