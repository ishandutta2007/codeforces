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
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int p,f;
    scanf("%d %d",&p,&f);
    int cnts,cntw;
    scanf("%d %d",&cnts,&cntw);
    int s,w;
    scanf("%d %d",&s,&w);
    if(s>w){
        swap(s,w);
        swap(cnts,cntw);
    }
    if(s<w){
        int ans=0;
        for(int i=0;i<=cnts&&i*s<=p;i++){
            int lesss=cnts-i;
            int lessp=p-i*s;
            int res=min(lessp/w,cntw);
            int lessw=cntw-res;
            res+=i;
            int takes=min(lesss,f/s);
            res+=takes;
            int lessf= f-takes*s;
            res+=min(lessf/w,lessw);
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    else{
        int ans=min(cnts+cntw,p/s+f/w);
        printf("%d\n",ans);
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
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/