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
LL a[200005];
vector<int> v[200005];
/*
LL dfs(int x){
    if(v[x].empty()){
        if(a[x]>mid){
            ok=0;
            return 0;
        }
        else{
            return mid-a[x];
        }
    }
    LL sum=0;
    for(auto it:v[x]){
        sum+=dfs(it);
        if(sum>1e18)sum=1e18;
    }
    if(a[x]>sum){
        ok=0;
        return 0;
    }
    return sum-a[x];

}*/
void solve(){
    int n;
    scanf("%d",&n);
    int p[200005];
    for(int i = 2;i<=n;i++){
        int x=rand()%i;
        scanf("%d",&x);
         p[i]=x;
       v[x].pb(i);
    }
    for(int i = 1;i<=n;i++){
        a[i]=rand();
        scanf("%lld",&a[i]);
    }
    LL Max=1e18,Min=-1;
    LL val[200005];
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL ok=1;
        fill(val,val+n+1,0);
        for(int i=n;i>=1;i--){
            if(v[i].empty()){
                val[i]=mid;
            }
            if(val[i]<a[i])ok=0;
            val[i]-=a[i];
            val[p[i]]+=val[i];
            if(val[p[i]]>1e18)val[p[i]]=1e18;
        }
        if(ok){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    printf("%lld\n",Max);
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