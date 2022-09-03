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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[5005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=2e18;
    for(int i = 0;i<n;i++){
        LL sum=0;
        LL last=0;
        for(int j = i+1;j<n;j++){
            sum+=last/a[j]+1;
            last=(last/a[j]+1)*a[j];
        }
        last=0;
        for(int j = i-1;j>=0;j--){
            sum+=last/a[j]+1;
            last=(last/a[j]+1)*a[j];
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/