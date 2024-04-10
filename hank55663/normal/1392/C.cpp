#include<bits/stdc++.h>
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
using namespace std;
void solve(){
    LL n;
    scanf("%lld",&n);
    int a[200005];
    //int Max=-1e9-7;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        //Max=max(Max,a[i]);
    }
    LL ans=0;
    for(int i = 1;i<n;i++){
        if(a[i]<a[i-1]){
            ans+=a[i-1]-a[i];
        }
    }
    printf("%lld\n",ans);
    /*
    k--;
    for(int i = 0;i<n;i++){
        a[i]=Max-a[i];
    }
    if(k&1){
        Max=-1;
        for(int i = 0;i<n;i++){
            Max=max(Max,a[i]);
        }
        for(int i =0;i<n;i++){
            a[i]=Max-a[i];
        }
    }
    for(int i = 0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
//    }*/
}
int main(){
    int t=1;
    scanf("%d",&t);
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