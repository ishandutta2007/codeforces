#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
vector<int> v[200005];
LL Size[200005];
LL ans[200005];
int in[200005];
int out[200005];
int t;
void dfs(int x,int f){
    Size[x]=1;
    in[x]=++t;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    out[x]=t;
}
void solve(){
    t=0;
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0,0);
    for(int i=0;i<=0;i++){
        ans[i]=0;
        LL tot=n-1;
        for(auto it:v[i]){
            if(Size[it]<Size[i]){
                tot-=Size[it];
                ans[i]+=(Size[it]-1)*Size[it]/2;
            }
        }
        ans[i]+=tot*(tot-1)/2;
        ans[1]=n*1ll*(n-1)/2-ans[i];
        printf("%lld ",ans[i]);//-(i==0?0:ans[i-1]));
    }
    pll p1=mp(in[1],out[1]),p2=mp(0,0);
    pll belong;
    LL val=0;
    for(auto it:v[0]){
        if(in[it]<=p1.x&&out[it]>=p1.x){
            val=n-Size[it];belong=mp(in[it],out[it]);
        }
        else{
            
        }
    }
    fill(ans+2,ans+n+4,0);
    for(int i = 2;i<=n;i++){
        if(p2.x==0){
            ans[i]=(p1.y-p1.x+1)*val;
        }
        else{
            ans[i]=(p1.y-p1.x+1)*(p2.y-p2.x+1);
        }
        //printf("%d %d %d %d %d %d\n",p1.x,p1.y,p2.x,p2.y,val,ans[i]);
        if(in[i]<=p1.x&&out[i]>=p1.x);
        else if(in[i]<=p2.x&&out[i]>=p2.x);
        else if(in[i]>=p1.x&&in[i]<=p1.y){
            p1=mp(in[i],out[i]);
        }
        else if(in[i]>=p2.x&&in[i]<=p2.y){
            p2=mp(in[i],out[i]);
        }
        else if(p2.x==0){
            if(in[i]>=belong.x&&out[i]<=belong.y)break;
            p2=mp(in[i],out[i]);
        }
        else{
            break;
        }
        //printf("%lld ",ans[i]);
    }

    for(int i = 1;i<=n;i++){
        printf("%lld ",ans[i]-ans[i+1]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*

*/