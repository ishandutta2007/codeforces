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
int a[200005];
int cal(int x,int y,int n){
    int ans=0;
   // printf("%d %d\n",x,y);
    for(int i = 1;i<=n;i++){
        if(a[i]<=x){
            ans++;
            swap(x,y);
        }
    }
  //  printf("%d\n",ans);
    return ans;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int Max=1e9,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        if(cal(mid,1e9,n)>=k||cal(1e9,mid,n)>=k)Max=mid;
        else Min=mid;
    }
    printf("%d\n",Max);
}
int main(){
    int t=1;
   // scanf("%d",&t);
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