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
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 1000005
int mod=1e9+7;
void solve(){
    int n,x,pos;
    scanf("%d %d %d",&n,&x,&pos);
    int l = 0,r=n;
    LL a1=x-1,a2=n-x;
    LL ans=1;
    while(l<r){
        int mid=(l+r)/2;
        if(mid<pos){
            ans*=a1;
            a1--;
            ans%=mod;
            l=mid+1;
        }
        else if(mid==pos){
            l=mid+1;
        }
        else{
            ans*=a2;
            a2--;
            ans%=mod;
            r=mid;
        }
      //  printf("%lld %lld %lld\n",a1,a2,ans);
    }
    for(int i = 1;i<=a1+a2;i++){
        ans*=i;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/