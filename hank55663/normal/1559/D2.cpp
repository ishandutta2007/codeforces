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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<int> v[100005];
vector<int> tmp;
int vis[100005];
void dfs(int x,int f){
    tmp.pb(x);
    vis[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
}
void solve(){
    int n,m1,m2;
    scanf("%d %d %d",&n,&m1,&m2);
    for(int i = 1;i<=n;i++)f[i]=i;
    for(int i = 0;i<m1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a=Find(x),b=Find(y);
        f[a]=b;
    }
    for(int i = 0;i<m2;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    priority_queue<pair<int,vector<vector<int> > > ,vector<pair<int,vector<vector<int> > > > ,greater<pair<int,vector<vector<int> > > > > pq;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
            pq.push(mp(tmp.size(),vector<vector<int>>{tmp}));
            tmp.clear();
        }
    }
    vector<pii> ans;
    fill(vis,vis+n+1,0);
    while(pq.size()!=1){
        int a=pq.top().x;
        auto p=pq.top().y;
        pq.pop();
        int b=pq.top().x;
        auto q=pq.top().y;
        pq.pop();
        if(p.size()!=1&&q.size()!=1){
            if(Find(p[0][0])==Find(q[0][0])){
                for(auto it:q)p.pb(it);
                pq.push(mp(a+b,p));
            }
            else{
                ans.pb(mp(p[0][0],q[0][0]));
                f[Find(p[0][0])]=Find(q[0][0]);
                for(auto it:q[0])p[0].pb(it);
                for(int i = 1;i<q.size();i++){
                    p.pb(q[i]);
                    //ans.pb(mp(p[i][0],q[i][0]));
                }
                pq.push(mp(a+b,p));
            }
            continue;
        }
        if(q.size()==1&&p.size()!=1)swap(p,q);
        deque<pii> tmp;
        for(auto it:p[0]){
            if(!vis[Find(it)]){
                vis[Find(it)]=1;
                tmp.pb(mp(Find(it),it));
            }
        }
        for(auto it:p[0])vis[Find(it)]=0;
        for(auto it:q){
            int ok=0;
            for(auto it2:it){
                int x=Find(it2);
                if(tmp.size()&&x!=tmp.front().x){
                    ans.pb(mp(tmp.front().y,it2));
                    f[Find(tmp.front().y)]=Find(it2);
                    ok=1;
                    tmp.pop_front();
                    break;
                }
                else if(tmp.size()&&x!=tmp.back().x){
                    ans.pb(mp(tmp.back().y,it2));
                    f[Find(tmp.back().y)]=Find(it2);
                    ok=1;
                    tmp.pop_back();
                    break;
                }
            }
            if(ok){
                for(auto it2:it)p[0].pb(it2);
            }
            else{
                p.pb(it);
            }
        }
      //  for(auto it:q)p.pb(it);
        pq.push(mp(a+b,p));
    }
    printf("%d\n",ans.size());
    for(auto it:ans)printf("%d %d\n",it.x,it.y);
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/