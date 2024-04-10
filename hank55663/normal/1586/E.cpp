#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
int val[300005];
vector<pii> v[300005];
int res[300005];
int vis[300005];
vector<int> stk;
bool check(int x,int y){
    if(vis[x])return false;
    stk.pb(x);
    vis[x]=1;
    if(x==y)return true;
    for(auto it:v[x]){
        if(val[it.y]){
            if(check(it.x,y)){
                val[it.y]^=1;
                return true;
            }
        }
    }
    stk.pop_back();
    return false;
}
bool go(int x,int y){
    if(vis[x])return false;
    stk.pb(x);
    vis[x]=1;
    if(x==y)return true;
    for(auto it:v[x]){
        if(val[it.y]){
            if(go(it.x,y)){
                val[it.y]^=1;
                return true;
            }
        }
    }
    for(auto it:v[x]){
        if(1){
            if(go(it.x,y)){
                val[it.y]^=1;
                return true;
            }
        }
    }
    stk.pop_back();
    return false;
}
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
    }
    int q;
    scanf("%d",&q);
    vector<vector<int> > ans;
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        res[x]^=1;
        res[y]^=1;
        stk.clear();
        MEM(vis);
        if(check(x,y)){
            ans.pb(stk);
        }
        else{
            MEM(vis);
            stk.clear();
            go(x,y);
            ans.pb(stk);
        }
    }
    int tot=0;
    for(int i = 1;i<=n;i++){
        if(res[i]){
            tot++;
            //printf("NO\n");
        //   return;
        }
    }
    if(tot){
        printf("NO\n%d\n",tot/2);
        return;
    }
    printf("YES\n");
    for(auto it:ans){
        printf("%d\n",it.size());
        for(auto it2:it)printf("%d ",it2);
        printf("\n");
    }
}
int main(){
    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/