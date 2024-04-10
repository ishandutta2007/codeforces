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
void solve(){
    int n;
    scanf("%d",&n);
    LL a[100005];
    for(int i = 1;i<=n;i++)
    scanf("%lld",&a[i]);
    LL b[100005];
    LL sum=0;
    for(int i = 2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(b[i]>0)sum+=b[i];
    }
    LL ans=sum+a[1];
    if(ans%2!=0)ans++;
  //  printf("%lld %d\n",sum,a[1]);
    printf("%lld\n",ans/2);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        if(l==1)a[1]+=x;
        else{
            if(b[l]>0)sum-=b[l];
            b[l]+=x;
            if(b[l]>0)sum+=b[l];
        }
        if(r!=n){
            if(b[r+1]>0)sum-=b[r+1];
            b[r+1]-=x;
            if(b[r+1]>0)sum+=b[r+1];
        }
        LL ans=sum+a[1];
    if(ans%2!=0)ans++;
    printf("%lld\n",ans/2);
    }
}

int main(){
    int t=1;
 //   scanf("%d",&t);
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