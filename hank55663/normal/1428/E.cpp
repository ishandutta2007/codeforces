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
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL cal(int x,int k){
    LL a=x/k,b=x/k+1;
    LL val=k-x%k,val2=x%k;
    return a*a*val+b*b*val2;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL a[100005];
    int now[1000005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    LL ans=0;
    priority_queue<pll> pq;
    for(int i=0;i<n;i++){
        ans+=a[i]*a[i];
        now[i]=1;
        pq.push(mp(cal(a[i],1)-cal(a[i],2),i));
      //  printf("%lld %lld %lld\n",a[i],cal(a[i],1),cal(a[i],2));
    }
    now[n]=1e9;
  
   
    k-=n;
    for(int i = 0;i<k;i++){
        ans-=pq.top().x;
        int x=pq.top().y;
   //     printf("%d %d\n",pq.top().x);
        pq.pop();
        now[x]++;
       // printf("%lld %d %lld\n",a[x],now[x]+1,cal(a[x],now[x]+1));
        pq.push(mp(cal(a[x],now[x])-cal(a[x],now[x]+1),x));
    }
    printf("%lld\n",ans);
}



int main(){
    int t=1;
  //  scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/