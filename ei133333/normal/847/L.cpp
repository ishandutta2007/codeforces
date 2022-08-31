#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N;

char str[1111111];
int itr;
int rd(){
    int ret=0;
    while(isdigit(str[itr]))ret=ret*10+str[itr++]-'0';
    return ret;
}

vector<vint>G[1111];

int sz[1111];

vint g[1111];

void dfs(int v,int p,vint &a){
    a.pb(v);
    for(auto u:g[v]){
        if(u!=p)dfs(u,v,a);
    }
}

signed main(){
    scanf("%lld",&N);

    rep(i,N){
        scanf("%s",str);
        itr=0;
        int l=strlen(str);
        str[l]='-';
        l++;
        while(itr<l){
            int k=rd();
            itr++;
            vint v;
            rep(t,k){
                v.pb(rd()-1);
                itr++;
            }
            G[i].pb(v);
        }
    }

    fill_n(sz,N,1);

    vpint lis[1111];
    rep(i,N){
        rep(j,G[i].size()){
            if(G[i][j].size()<=N/2)lis[G[i][j].size()].pb({i,j});
        }
    }

    UnionFindTree uf(N);
    vpint ans;
    for(int i=1;i<(N+1)/2;i++){
        for(auto &w:lis[i]){
            int v=w.fi;
            vint &a=G[v][w.se];
            for(auto &u:a)if(!uf.areSame(a[0],u)){
                cout<<-1<<endl;
                return 0;
            }
            int y=-1;
            for(auto &u:a){
                if(sz[u]==i)y=u;
            }
            if(y==-1||uf.areSame(v,y)){
                cout<<-1<<endl;
                return 0;
            }
            ans.pb({v,y});
            sz[v]+=sz[y];
            uf.unite(v,y);
        }
    }

    if(N%2==0&&lis[N/2].size()==2){
        int x=lis[N/2][0].fi;
        int y=lis[N/2][1].fi;
        if(uf.areSame(x,y)){
            cout<<-1<<endl;
            return 0;
        }
        uf.areSame(x,y);
        ans.pb({x,y});
    }

    if(ans.size()!=N-1){
        cout<<-1<<endl;
        return -1;
    }

    rep(i,N-1)g[ans[i].fi].pb(ans[i].se),g[ans[i].se].pb(ans[i].fi);
    rep(i,N){
        vector<vint>x;
        for(auto &v:g[i]){
            vint a;
            dfs(v,i,a);
            sort(all(a));
            x.pb(a);
        }
        sort(all(x));

        rep(j,G[i].size())sort(all(G[i][j]));
        sort(all(G[i]));
        if(G[i]!=x){
            cout<<-1<<endl;
            return 0;
        }
    }


    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
    return 0;
}