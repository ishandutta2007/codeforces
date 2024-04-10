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
    int a[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    vector<pii> v;
    int x=-1;
    for(int i = 2;i<=n;i++){
        if(a[i]!=a[1]){
            v.pb(mp(1,i));
            x=i;
        }
    }
    if(x==-1){
        printf("NO\n");
    }
    else{
        for(int i = 2;i<=n;i++){
            if(a[i]==a[1]){
                v.pb(mp(i,x));
            }
        }
        printf("YES\n");
        for(auto it:v){
            printf("%d %d\n",it.x,it.y);
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
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