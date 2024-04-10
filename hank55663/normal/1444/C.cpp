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
vector<int> v[500005];
int bln[500005];
int col[500005];
vector<int> g[500005];
int now[500005];
bool dfs(int x,int color){
    col[x]=color;
    for(auto it:v[x]){
        if(bln[it]==bln[x]){
            if(col[it]!=-1){
                if(col[it]==color){
                    return false;
                }
            }
            else{
                if(!dfs(it,color^1))return false;
            }
        }
    }
    return true;
}
int ok[500005];

vector<int> tmp[1000005];
int col2[1000005];
bool dfs2(int x,int color){
    col2[x]=color;
    for(auto it:tmp[x]){
        if(col2[it]!=-1){
            if(col2[it]==color)return false;
        }
        else{
            if(!dfs2(it,color^1))return false;
        }
    }
    return true;
}
void solve(){   
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        scanf("%d",&bln[i]);
        g[bln[i]].pb(i);
    }
    for(int i = 1;i<=k;i++){
        ok[i]=1;
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    MEMS(col);
    MEMS(col2);
    for(int i = 1;i<=n;i++){
        if(col[i]==-1){
            if(!dfs(i,now[bln[i]])){
                ok[bln[i]]=0;
            }
            now[bln[i]]+=2;
        }
    }
    int tot=0;
    for(int i=  1;i<=k;i++){
        if(ok[i])tot++;
    }
    LL ans=0;
    for(int i = 1;i<=k;i++){
        if(ok[i]){
            LL sum =tot-1;
            map<int,set<pii> > m;
            for(auto it:g[i]){
                for(auto it2:v[it]){
                    if(bln[it2]!=i&&ok[bln[it2]]){
                        m[bln[it2]].insert(mp(col[it],col[it2]));
                      //  printf("%d %d\n",col[it],col[it2]);
                    }
                }
            }
           // printf("\n");
            
            for(auto it:m){
               // printf("?%d %d %d %d\n",i,it.x,now[i],now[it.x]);
                for(auto it2:it.y){
                    tmp[it2.x].pb(it2.y+now[i]);
                    tmp[it2.y+now[i]].pb(it2.x);
                  //  printf("%d %d\n",it2.x,it2.y+now[i]);
                }
                for(auto it2:it.y){
                    tmp[it2.x].pb(it2.x^1);
                    tmp[it2.x^1].pb(it2.x);
                    tmp[(it2.y+now[i])^1].pb(it2.y+now[i]);
                    tmp[it2.y+now[i]].pb((it2.y+now[i]^1));
                }
                int ok=1;
                for(auto it2:it.y){
                    if(col2[it2.x]==-1){
                        if(!dfs2(it2.x,0)){
                            ok=0;
                            break;
                        }
                    }
                }
                for(auto it2:it.y){
                    tmp[it2.x].clear();//pb(it2.x^1);
                    tmp[it2.x^1].clear();//pb(it2.x);
                    tmp[(it2.y+now[i])^1].clear();//pb(it2.y+now[i]);
                    tmp[it2.y+now[i]].clear();//pb((it2.y+now[i]^1));
                    col2[it2.x]=col2[it2.x^1]=col2[it2.y+now[i]]=col2[(it2.y+now[i])^1]=-1;
                }
                if(!ok)sum--;
                else{
                 //   printf("%d %d\n",i,it.x);
                }
            }
            ans+=sum;
        }
    }
   // printf("%lld\n",ans);
   // assert(ans%2==0);
    printf("%lld\n",ans/2);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/