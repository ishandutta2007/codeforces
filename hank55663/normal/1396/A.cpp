#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    LL a[100005];
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    if(n==1){
        printf("1 1\n%lld\n1 1\n0\n1 1\n0\n",-a[1]);
        return ;
    }
    printf("1 %d\n",n-1);
    for(int i = 1;i<n;i++){
        LL ans=(a[i]%n+n)%n*(n-1);
        printf("%lld ",ans);
        a[i]+=ans;
    }
    printf("\n");
    printf("2 %d\n",n);
    for(int i = 2;i<n;i++)printf("0 ");
    LL ans=(a[n]%n+n)%n*(n-1);
    printf("%lld\n",ans);
    a[n]+=ans;
    printf("1 %d\n",n);
    for(int i = 1;i<=n;i++){
        printf("%lld ",-a[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/