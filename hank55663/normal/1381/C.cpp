#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
//#define ll long long
vector<int> v[100005];
vector<int> resq[100005];
void solve(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    for(int i = 1;i<=n+1;i++){
        v[i].clear();
        resq[i].clear();
    }
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    int goodnum;
    for(int i = 1;i<=n+1;i++){
        if(v[i].empty())goodnum=i;
    }
    map<int,vector<int> > m;
    for(int i = 1;i<=n+1;i++){
        m[v[i].size()].pb(i);
    }
    int ans[100005];
    int vis[100005];
    fill(vis,vis+n+1,0);
    for(int i = 1;i<=x;i++){
        int x=m.rbegin()->y.back();
        int val=v[x].size();
        vis[v[x].back()]=1;
        ans[v[x].back()]=x;
        v[x].pop_back();
        m[val].pop_back();
        m[val-1].pb(x);
        if(m[val].empty())m.erase(val);
    }
    int cnt[100005];
    fill(cnt,cnt+n+2,0);
    for(int i = 1;i<=n;i++){
        if(!vis[i])cnt[a[i]]++;
    }
    int Max=0;
    vector<int> q;
    for(int i = 1;i<=n+1;i++){
        Max=max(Max,cnt[i]);
        for(int j=0;j<cnt[i];j++)q.pb(i);
    }
    if(Max*2>n-x&&(n-x-Max)*2<y-x){
        printf("NO\n");
    }
    else{
        int half=q.size()/2;
        for(int i = 0;i<q.size();i++){
            if(q[i]!=q[(i+half)%q.size()])
            resq[q[i]].pb(q[(i+half)%q.size()]);
        }
        printf("YES\n");
        for(int i = 1;i<=n;i++){
              if(y==x)break;
            if(!vis[i]&&resq[a[i]].size()){
                ans[i]=resq[a[i]].back();
                resq[a[i]].pop_back();
                vis[i]=1;
                y--;
            }
          
        }
        assert(y==x);
        for(int i = 1;i<=n;i++){
            if(vis[i])printf("%d ",ans[i]);
            else printf("%d ",goodnum);
        }
        printf("\n");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}