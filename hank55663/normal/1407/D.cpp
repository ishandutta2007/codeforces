#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    vector<int> v[300005];
void solve(){   
    int n;
    scanf("%d",&n);
    int dp[300005];
    int h[300005];
    dp[1]=0;
    vector<pii> Min,Max;
    for(int i = 1;i<=n;i++){
        scanf("%d",&h[i]);
        //Min.pb(mp(h[i],i));
        //Max.pb(mp(h[i],i));
    }
    Min.pb(mp(h[1],1));
    Max.pb(mp(h[1],1));

    for(int i = 2;i<=n;i++){
        dp[i]=1e9;
        while(Min.size()&&Min.back().x>h[i]){
            
            Min.pop_back();
        }
        while(Max.size()&&Max.back().x<h[i])Max.pop_back();

        if(Min.size()){
  //          dp[i]=min(dp[i],dp[Min.back().y]+1);
  //          printf("%d ",Min.back().y);
                v[i].pb(Min.back().y);
        }
        if(Max.size()){
    //        dp[i]=min(dp[i],dp[Max.back().y]+1);
   //         printf("%d ",Max.back().y);
            v[i].pb(Max.back().y);
        }
      //  printf("\n");
        Min.pb(mp(h[i],i));
        Max.pb(mp(h[i],i));
    }
    Min.clear();
    Max.clear();
    Min.pb(mp(h[n],n));
    Max.pb(mp(h[n],n));
    for(int i =n-1;i>=1;i--){
        dp[i]=1e9;
        while(Min.size()&&Min.back().x>h[i]){
            
            Min.pop_back();
        }
        while(Max.size()&&Max.back().x<h[i])Max.pop_back();

        if(Min.size()){
  //          dp[i]=min(dp[i],dp[Min.back().y]+1);
  //          printf("%d ",Min.back().y);
                v[Min.back().y].pb(i);
        }
        if(Max.size()){
    //        dp[i]=min(dp[i],dp[Max.back().y]+1);
   //         printf("%d ",Max.back().y);
            v[Max.back().y].pb(i);
        }
      //  printf("\n");
        Min.pb(mp(h[i],i));
        Max.pb(mp(h[i],i));
    }
    dp[1]=0;
    for(int i = 2;i<=n;i++){
        for(auto it:v[i])dp[i]=min(dp[i],dp[it]+1);
    }
    printf("%d\n",dp[n]);
    
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/