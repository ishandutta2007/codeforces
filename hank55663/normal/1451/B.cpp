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
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    char c[105];
    scanf("%s",c+1);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        int ok=0;
        for(int i =r+1;i<=n;i++){
            if(c[i]==c[r])ok=1;
        }
        for(int i=  1;i<l;i++){
            if(c[i]==c[l])ok=1;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}