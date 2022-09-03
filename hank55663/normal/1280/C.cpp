#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
vector<pii> v[200005];
LL Size[200005];
LL ans1,ans2;
void dfs(int x,int f,int n){
    Size[x]=1;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x,n);
            ans2+=min(Size[it.x],n-Size[it.x])*it.y;
            ans1+=(Size[it.x]&1)*it.y;
            Size[x]+=Size[it.x];
        }
    }
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        n=n*2;
        for(int i = 1;i<=n;i++)v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            v[x].pb(mp(y,w));
            v[y].pb(mp(x,w));
        }
        ans1=0,ans2=0;
        dfs(1,0,n);
        printf("%lld %lld\n",ans1,ans2);
    }
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/