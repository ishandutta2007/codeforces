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
#define N 700005
vector<int> v[300005];
int ans[300005];
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    fill(ans,ans+n+1,1e9);
    for(int i = 1;i<=n;i++){
        int last=0;
        int Max=0;
        for(auto it:v[i]){
            Max=max(Max,it-last);
            last=it;
        }
        Max=max(Max,n+1-last);
        ans[Max]=min(ans[Max],i);
    }
    for(int i = 1;i<=n;i++){
        ans[i]=min(ans[i],ans[i-1]);
        if(ans[i]==1e9)printf("-1 ");
        else printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/