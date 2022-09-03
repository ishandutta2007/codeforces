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
void solve(){   
    LL p,q;
    scanf("%lld %lld",&p,&q);
    if(p%q!=0){
        printf("%lld\n",p);
    }
    else{
        map<int,int> m;
        for(int i = 2;i*i<=q;i++){
            while(q%i==0){
                m[i]++;
                q/=i;
            }
        }
        if(q!=1)m[q]++;
        LL ans=1;
        for(auto it:m){
            LL tmp=p;
            while(tmp%it.x==0)tmp/=it.x;
            for(int j = 0;j<it.y-1;j++)tmp*=it.x;
            ans=max(ans,tmp);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
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