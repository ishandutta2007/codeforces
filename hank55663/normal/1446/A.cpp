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
    int n;
    LL w;
    scanf("%d %lld",&n,&w);
    pii p[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i].x);
        p[i].y=i+1;
    }
    sort(p,p+n);
    reverse(p,p+n);
    LL sum=0;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(sum+p[i].x<=w){
            sum+=p[i].x;
            ans.pb(p[i].y);
        }
    }
    if(sum*2<w){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans.size());
        for(auto it:ans)printf("%d ",it);
        printf("\n");
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}