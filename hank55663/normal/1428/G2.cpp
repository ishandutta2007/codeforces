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
LL dp[6][1000005];
LL cal(int x,int f,int k){
    int a=x%3;
    int b=(x-a)/3;
    if(9*k<x)return -1000000000000000000;
    LL Max=0;
    for(int j = a;j<=9;j+=3){
        int need=0;
        if(j)need=1;
        need+=((x-j)/3+3-1)/3;
        if(need<=k)Max=max(Max,f*1ll*(x-j)/3);
    }
    //printf("%d %d %d %lld\n",x,f,k,Max);
    return Max;
}
void solve(){
    int k;
    scanf("%d",&k);
    LL f[10];
    vector<pll> v;
    int now=1;
    for(int i = 0;i<6;i++){
        scanf("%lld",&f[i]);
    }
    for(int j = 0;j<=9;j++){
        if(j%3==0){
            dp[5][j]=f[5]*j/3;
        }
        else{
            if(k>=2){
                dp[5][j]=f[5]*(j/3);
            }
            else{
                dp[5][j]=0;
            }
        }
    //     printf("%d %d %lld\n",5,j,dp[5][j]);
    }

    for(int i = 4;i>=0;i--){

        for(int t=0;t<3;t++){
                    deque<pll> v[3];
        multiset<LL> s[3];
        LL add=0;
        LL r=-1;
        for(int j=t;j<=999999;j+=3){
            int l=max((j-k*9+9)/10,0);
        //    printf("%d\n",l);
            for(int a=l;a<=l+3&&a*10<=j;a++){
                 dp[i][j]=max(dp[i][j],dp[i+1][a]+cal(j-a*10,f[i],k));
            }

           
            if((r+1)*10<=j){
                v[(r+1)*10%3].pb(mp(dp[i+1][r+1]-add,r+1));
                s[(r+1)*10%3].insert(dp[i+1][r+1]-add);
                r++;
            }
             for(int i = 0;i<3;i++){
                if(v[i].size()&&v[i].front().y<=l+3){
                    s[i].erase(s[i].find(v[i].front().x));
                    v[i].pop_front();
                }
            }
            for(int k=0;k<3;k++){
                if(j%3==k){
                    if(s[k].size())
                    dp[i][j]=max(dp[i][j],*s[k].rbegin()+add);
                }
                else{
                    if(s[k].size())
                    dp[i][j]=max(dp[i][j],*s[k].rbegin()+add);
                }
            }
            add+=f[i];
         //   printf("%d %d %lld\n",i,j,dp[i][j]);
        }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",dp[0][x]);
    }

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