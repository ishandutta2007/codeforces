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
void solve(){
    int n;
    scanf("%d",&n);
    char c[205][205];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
    }
    vector<pii> v1,v2;
    if(c[0][1]=='1')v2.pb(mp(0,1));
    else v1.pb(mp(0,1));
     if(c[1][0]=='1')v2.pb(mp(1,0));
    else v1.pb(mp(1,0));
    if(c[n-1][n-2]=='0')v2.pb(mp(n-1,n-2));
    else v1.pb(mp(n-1,n-2));
    if(c[n-2][n-1]=='0')v2.pb(mp(n-2,n-1));
    else v1.pb(mp(n-2,n-1));
    if(v1.size()<=2){
        printf("%d\n",v1.size());
        for(auto it:v1){
            printf("%d %d\n",it.x+1,it.y+1);
        }
    }
    else{
         printf("%d\n",v2.size());
        for(auto it:v2){
            printf("%d %d\n",it.x+1,it.y+1);
        }
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
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/