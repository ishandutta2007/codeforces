/**
 *    author:  gary
 *    created: 24.11.2021 20:18:56
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+5;
int u[MAXN],v[MAXN],w[MAXN];
map<pair<mp,int> ,int> cnt;
int n,m;
int deg[MAXN][3];
struct edge
{
    int v,ty,id;
};
vector<edge> g[MAXN];
int era[MAXN*10];
bool vis[MAXN];
int tonow[MAXN][4];
vector<int> tour;
mp G[MAXN*10];
void euler_tour(int now,int ty){
    vis[now]=1;
    while(tonow[now][ty]<g[now].size()){
        if((g[now][tonow[now][ty]].ty==ty||ty==3)&&!era[g[now][tonow[now][ty]].id]){
            G[g[now][tonow[now][ty]].id]=II(now,g[now][tonow[now][ty]].v);
            cnt[II(II(now,g[now][tonow[now][ty]].v),g[now][tonow[now][ty]].ty)]++;
            era[g[now][tonow[now][ty]].id]=1;
            tonow[now][ty]++;
            int tmp=g[now][tonow[now][ty]-1].v;
            euler_tour(tmp,ty);
        }
        else{
            tonow[now][ty]++;
        }
    }
    tour.PB(now);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    rb(i,1,n) tonow[i][1]=tonow[i][2]=0;
    rb(i,1,m) cin>>u[i]>>v[i]>>w[i],deg[u[i]][w[i]]++,deg[v[i]][w[i]]++,g[u[i]].PB(edge{v[i],w[i],i}),g[v[i]].PB(edge{u[i],w[i],i});
    int ans=0;
    rb(i,1,n) ans+=deg[i][1]&1;
    cout<<ans<<endl;
    vector<int> A,B;
    rb(i,1,n){
        if(deg[i][1]%2) A.PB(i);
        if(deg[i][2]%2) B.PB(i);
    }
    int cnte=m;
    rep(i,A.size()){
        ++cnte;
        g[n+1].PB(edge{A[i],1,cnte});
        g[A[i]].PB(edge{n+1,1,cnte});
    }
    rep(i,B.size()){
        ++cnte;
        g[n+1].PB(edge{B[i],2,cnte});
        g[B[i]].PB(edge{n+1,2,cnte});
    }
    euler_tour(n+1,1);
    reverse(ALL(tour));
    vector<vector<int> > tours[3];
    if(tour.size())
    for(int i=0;i<tour.size()-1;){
        int j=i+1;
        while(tour[j]!=n+1) ++j;
        if(j>i+1){
            vector<int> temp;
            set<int> app;
            rb(k,i+1,j-1){
                if(app.find(tour[k])!=app.end()){
                    while(true){
                        bool brk=temp.back()==tour[k];
                        app.erase(temp.back());
                        temp.POB();
                        if(brk) break;
                    }
                }
                app.insert(tour[k]);
                temp.PB(tour[k]);
            }
            // cout<<1<<":\n";
            // for(auto it:temp){
            //     cout<<it<<",";
            // }
            // cout<<endl;

            tours[1].PB(temp);
        }
        i=j;
    }
    rb(i,1,n) if(!vis[i]) euler_tour(i,1);
    memset(vis,0,sizeof(vis));
    tour.clear();
    euler_tour(n+1,2);
    reverse(ALL(tour));
    if(tour.size())
    for(int i=0;i<tour.size()-1;){
        int j=i+1;
        while(tour[j]!=n+1) ++j;
        if(j>i+1){
            vector<int> temp;
            set<int> app;
            rb(k,i+1,j-1){
                if(app.find(tour[k])!=app.end()){
                    while(true){
                        bool brk=temp.back()==tour[k];
                        app.erase(temp.back());
                        temp.POB();
                        if(brk) break;
                    }
                }
                app.insert(tour[k]);
                temp.PB(tour[k]);
            }
            // cout<<2<<":\n";
            // for(auto it:temp){
            //     cout<<it<<",";
            // }
            // cout<<endl;

            tours[2].PB(temp);
        }
        i=j;
    }
    rb(i,1,n) if(!vis[i]) euler_tour(i,2);
    memset(era,0,sizeof(era));
    memset(vis,0,sizeof(vis));
    rb(i,1,n+1) g[i].clear();
    cnte=0;
    rb(k,1,2){
        for(auto ve:tours[k]){
            ++cnte;
            g[ve[0]].PB(edge{ve.back(),3,cnte});
            g[ve.back()].PB(edge{ve[0],3,cnte});
        }
    }
    rb(i,1,n) if(g[i].size()&1){
        ++cnte;
        g[n+1].PB(edge{i,3,cnte});
        g[i].PB(edge{n+1,3,cnte});
    }
    rb(i,1,n) if(!vis[i]) euler_tour(i,3);
    cnte=0;
    rb(k,1,2){
        for(auto ve:tours[k]){
            rep(i,ve.size()){
                if(i){
                    cnt[II(II(ve[i-1],ve[i]),k)]--;
                }
            }
            ++cnte;
            if(G[cnte]==II(ve[0],ve.back()));
            else reverse(ALL(ve));
            rep(i,ve.size()){
                if(i){
                    cnt[II(II(ve[i-1],ve[i]),k)]++;
                }
            }
        }
    }
    rb(i,1,m){
        if(!cnt[II(II(u[i],v[i]),w[i])]){
            swap(u[i],v[i]);
            cout<<"2";
        }
        else{
            cout<<"1";
        }
        assert(cnt[II(II(u[i],v[i]),w[i])]);
        cnt[II(II(u[i],v[i]),w[i])]--;
    }
    return 0;
}