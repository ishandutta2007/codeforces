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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
const int mod=1e9+7;
int f[500005];
int vis[500005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=m;i++){
        f[i]=i;
    }
    vector<int> v;
    vector<pii> tmp;
    for(int i = 1;i<=n;i++){
        int k;
        scanf("%d",&k);
        if(k==1){
            int x;
            scanf("%d",&x);
           // tmp.pb(mp(x,i));
            x=Find(x);
            if(!vis[x])v.pb(i),vis[x]=1;
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            x=Find(x);
            y=Find(y);
            if(x!=y&&(!vis[x]||!vis[y])){
                f[x]=y;
                vis[y]|=vis[x];
                v.pb(i);
            }
        }
    }
    /*for(auto it:tmp){
        int a=Find(it.x);
        if(!vis[a]){
            vis[a]=1;
            v.pb(it.y);
        }
    }*/
    LL ans=1;
    for(int i = 0;i<v.size();i++)ans=ans*2%mod;
    printf("%lld %d\n",ans,v.size());
    sort(v.begin(),v.end());
    for(auto it:v)printf("%d ",it);
    printf("\n");
    return true;
}
int main(){
    int t=1;00000;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/