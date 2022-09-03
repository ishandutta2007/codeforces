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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
#define XXX 2520
vector<int> v[1005];
int k[1005];
int degree[1005][XXX];
int mod=XXX;
int vis[1005][XXX];
int ans[1005][XXX];
vector<pii> stk;
set<int> tmp;
int instk[1005][XXX];
int go(int x,int y){
  //  printf("%d %d\n",x,y);
    if(vis[x][y]){
        //pii pp=Find(mp(x,y));
        //tmp=s[pp.x][pp.y];
        return ans[x][y];
    }
  //  printf("%d %d\n",x,y);
    if(instk[x][y]){
        while(stk.back()!=mp(x,y)){
            tmp.insert(stk.back().x);
            stk.pop_back();
        }
        tmp.insert(stk.back().x);
        return tmp.size();
    }
   // printf("%d %d\n",x,y);
    instk[x][y]=1;
    stk.pb(mp(x,y));
    ans[x][y]=go(v[x][(y+k[x])%(v[x].size())],(y+k[x])%mod);
    vis[x][y]=1;
    return ans[x][y];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&k[i]);
        k[i]=(k[i]%mod+mod)%mod;
    }
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int _ = 0;_<x;_++){
            int a;
            scanf("%d",&a);
            v[i].pb(a);
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        y=(y%mod+mod)%mod;
      //  assert(ans[x][y]!=0);
        tmp.clear();
        printf("%d\n",go(x,y));
    }
}