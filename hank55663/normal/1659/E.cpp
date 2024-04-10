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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[100005];
int f[100005];
int okf[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int bln[100005][30];
int ok[100005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,pii> > edge;
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        edge.pb(mp(w,mp(x,y)));
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
    }
    for(int i = 0;i<30;i++){
        for(int j = 1;j<=n;j++)f[j]=j;
        for(auto it:edge){
            if(it.x&(1<<i)){
                f[Find(it.y.x)]=Find(it.y.y);
            }
        }
        for(int j = 1;j<=n;j++)bln[j][i]=Find(j);
        if(i!=0){
            for(int j = 1;j<=n;j++){
                okf[j]=0;
            }
            for(int j = 1;j<=n;j++){
                for(auto it:v[j]){
                    
                    if(it.y&1);
                    else okf[Find(j)]=1;
                }
            }
            for(int j = 1;j<=n;j++){
                if(okf[Find(j)]){
                    ok[j]=1;
                  //  if(j==1){
                    //    printf("%d ",i);
                  //  }
                }
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        int qok=0;
        for(int j = 0;j<30;j++){
            if(bln[x][j]==bln[y][j])qok=1;//printf("%d\n",j);
        }
        if(qok)printf("0\n");
        else{
            if(ok[x])printf("1\n");
            else printf("2\n");
        }
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
UKOKCUEUKCKPNKPKPDEUFUFJUFBFPDPBFIFP
*/