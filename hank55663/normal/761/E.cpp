#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
vector<int> v[35];
pll ans[35];
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
void dfs(int a,int f,int st,LL dis,LL x,LL y){
    ans[a]=mp(x,y);
    st=(st+1)%4;
    for(auto it:v[a]){
        if(it!=f){
            dfs(it,a,(st+2)%4,dis>>1,x+X[st]*dis,y+Y[st]*dis);
            st=(st+1)%4;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()>4){
            printf("NO\n");
            return 0;
        }
    }
    dfs(1,0,-1,1ll<<35,0,0);
    printf("YES\n");
    for(int i = 1;i<=n;i++)
        printf("%lld %lld\n",ans[i].x,ans[i].y);
    return 0;
}