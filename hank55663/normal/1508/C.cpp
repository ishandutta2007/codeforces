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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<int> vv[200005];
vector<pii> vvv[200005];
int ok[1005][1005];
void dfs(int x,int s,int f,int sum){
    ok[s][x]=sum;
    for(auto it:vvv[x]){
        if(it.x!=f){
            dfs(it.x,s,x,sum|it.y);
        }
    }
}
void solve(){
    LL n,m;
    scanf("%lld %lld",&n,&m);
    if(n*(n-1)/2-m>=n){
        vector<pair<int,pii> > v;
        for(int i = 0;i<m;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            v.pb(mp(w,mp(x,y)));
            //vis[x][y]=vis[y][x]=1;
            vv[x].pb(y);
            vv[y].pb(x);
        }
        set<int> s;
        for(int i = 1;i<=n;i++){
            s.insert(i),f[i]=i;
            sort(vv[i].begin(),vv[i].end());
        }
    
        while(s.size()){
            queue<int> q;
            q.push(*s.begin());
            s.erase(s.begin());
            while(!q.empty()){
                int x=q.front();
                q.pop();
                int now=0;
                vector<int> tmp;
                for(auto it:s){
                    while(now!=vv[x].size()&&vv[x][now]<it){
                        now++;
                    }
                    if(vv[x].size()!=now&&vv[x][now]==it){
                        now++;
                        continue;
                    }
                    q.push(it);
                    int a=Find(it);
                    int b=Find(x);
                    f[a]=b;
                    tmp.pb(it);
                }
                for(auto it:tmp){
                    s.erase(it);
                }
            }
        }
        sort(v.begin(),v.end());
        LL sum=0;
        for(auto it:v){
            int a=Find(it.y.x),b=Find(it.y.y);
            if(a!=b){
                sum+=it.x;
                f[a]=b;
            }
        }
        printf("%lld\n",sum);
    }
    else{
        int vis[1005][1005];
        MEM(vis);
        vector<pair<int,pii> > v;
        LL tot=0;
        for(int i = 0;i<m;i++){
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            v.pb(mp(w,mp(x,y)));
            vis[x][y]=vis[y][x]=1;
            tot^=w;
        }
        sort(v.begin(),v.end());
        for(int i = 1;i<=n;i++)f[i]=i;
        for(int i = 1;i<=n;i++){
            for(int j =i+1;j<=n;j++){
                if(!vis[i][j]){
                    int a=Find(i),b=Find(j);
                    vvv[i].pb(mp(j,1));
                    vvv[j].pb(mp(i,1));
                    if(a==b)tot=0;
                    else{
                        f[a]=b;
                    }
                }
            }
        }
        LL sum=tot;
        for(auto it:v){
            int a=Find(it.y.x),b=Find(it.y.y);
            if(a!=b){
                f[a]=b;
                sum+=it.x;
                vvv[it.y.x].pb(mp(it.y.y,0));
                vvv[it.y.y].pb(mp(it.y.x,0));
            }
        }
        for(int i = 1;i<=n;i++)dfs(i,i,i,0);
        for(auto it:v){
            int a=it.y.x,b=it.y.y;
            if(ok[a][b]&&tot>it.x){
                sum-=tot;
                sum+=it.x;
                break;
            }
        }
        printf("%lld\n",sum);
    }
}
int main(){
    int t=1;

    while(t--){
        solve();
    }
}
/*
000
011
101
*/