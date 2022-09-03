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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<char> v[300005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[300005];
    scanf("%s",c);
    for(int i = 0;i<k;i++)v[i].clear();
    for(int i = 0;i<n;i++){
        v[i%k].pb(c[i]);
    }
    int one=0,zero=0,other=0;
    for(int i = 0;i<k;i++){
        int o=0,z=0;
        for(auto it:v[i]){
            if(it=='1')o++;
            if(it=='0')z++;
        }
        if(o&&z){
            printf("NO\n");
            return ;
        }
        if(o)one++;
        else if(z)zero++;
        else other++;
    }
    if(one+other>=zero&&zero+other>=one)printf("YES\n");
    else printf("NO\n");
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