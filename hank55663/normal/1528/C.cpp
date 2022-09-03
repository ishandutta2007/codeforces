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
vector<int> v1[300005],v2[300005];
int in[300005],out[300005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    for(auto it:v2[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
set<pii> s;
int ans;
void dfs2(int x,int f){
    auto it=s.lower_bound(mp(in[x],x));
    vector<int> rm;
   // printf("%d %d\n",it==s.end(),)
    if(it==s.end()||it->x>out[x]){
       
        if(it!=s.begin()){
            it--;
            int q=it->y;
            if(out[q]>=in[x]){
                rm.pb(q);
                s.erase(it);
            }
        }
         s.insert(mp(in[x],x));
    }
    //printf("%d %d\n",x,s.size());
    ans=max(ans,(int)s.size());
    for(auto it:v1[x]){
        if(it!=f)
            dfs2(it,x);
    }
    if(s.find(mp(in[x],x))!=s.end())s.erase(mp(in[x],x));
    for(auto it:rm){
        s.insert(mp(in[it],it));
    }
}
void solve(){
    t=0;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v1[i].clear(),v2[i].clear();
    for(int i = 2;i<=n;i++){
        int a;
        scanf("%d",&a);
        v1[a].pb(i);
    }
    for(int i = 2;i<=n;i++){
        int a;
        scanf("%d",&a);
        v2[a].pb(i);
    }
    ans=0;
    s.clear();
    dfs(1,0);
    dfs2(1,0);
    printf("%d\n",ans);
}
int main(){
    int t=1;//000;
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
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/