#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

vector<int> adj[200005];
vector<int> comp[200005];
vector<int> message[2000005];
int parent[200005];
bool vis[200005];
int jump[200005][25];
int d[200005];
int treeind[200005];
int curtreeind;
int send[200005], receive[200005];
vector<int> v;
vector<int> children[200005];

struct UF{
    int a[200005];

    int find(int x){
        if(a[x] == -1)
            return x;
        return a[x]=find(a[x]);
    }

    void join(int x, int y){
        x=find(x);
        y=find(y);
        if(x == y)
            return;
        a[x]=y;
    }
}uf;

void dfs(int node){
    treeind[node]=curtreeind;
    v.push_back(node);
    vis[node]=1;
    bool seenParent=0;
    rep(i,0,adj[node].size()){
        int to=adj[node][i];
        if(to == parent[node] && !seenParent){
            seenParent=1;
            continue;
        }
        if(vis[to]){
            if(uf.find(node) == uf.find(to))
                continue;
            int cur=node;
            while(cur != to){
                uf.join(cur, to);
                cur=parent[cur];
            }
        }
        else{
            parent[to]=node;
            dfs(to);
        }
    }
}

void treedfs(int c){
    rep(i,0,comp[c].size()){
        int node=comp[c][i];
        rep(j,0,adj[node].size()){
            int to=adj[node][j];
            int cto=uf.find(to);
            if(d[cto] >= 0)
                continue;
            d[cto]=d[c]+1;
            jump[cto][0]=c;
            children[c].push_back(cto);
            for(int k=1; (1<<k) <= d[cto]; ++k){
                jump[cto][k]=jump[jump[cto][k-1]][k-1];
            }
            treedfs(cto);
        }
    }
}

int getPar(int c, int D){
    int j=d[c]-D;
    for(int k=20; k >= 0; --k){
        if((1<<k) > j)
            continue;
        j -= (1<<k);
        c=jump[c][k];
    }
    return c;
}

int lca(int c1, int c2){
    if(d[c1] > d[c2])
        swap(c1, c2);
    c2=getPar(c2, d[c1]);
    for(int k=20; k >= 0; --k){
        if((1<<k) > d[c1])
            continue;
        if(jump[c1][k] == jump[c2][k])
            continue;
        c1=jump[c1][k];
        c2=jump[c2][k];
    }
    return d[c1]-(c1!=c2);
}

pair<int, int> check(int c){
    int S=send[c], R=receive[c];
    rep(i,0,children[c].size()){
        int to=children[c][i];
        pair<int, int> res=check(to);
        S=min(S,res.first);
        R=min(R,res.second);
    }
    if(S < d[c] && R < d[c]){
        puts("No");
        exit(0);
    }
    return make_pair(S,R);
}

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    rep(i,0,n){
        d[i]=-1;
        uf.a[i]=-1;
        send[i]=1000000;
        receive[i]=1000000;
    }
    rep(i,0,m){
        int v, u;
        scanf("%d%d", &v, &u);
        --v;--u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    rep(i,0,q){
        int S, D;
        scanf("%d%d", &S, &D);
        --S;--D;
        message[S].push_back(D);
    }
    rep(i,0,n){
        if(vis[i])
            continue;
        curtreeind=i+1;
        v.clear();
        parent[i]=-1;
        dfs(i);
        int root=uf.find(i);
        //set<int> comps;
        rep(j,0,v.size()){
            //comps.insert(uf.find(v[j]));
            comp[uf.find(v[j])].push_back(v[j]);
        }
        d[root]=0;
        treedfs(root);
        rep(j,0,v.size()){
            int S=v[j];
            rep(k,0,message[S].size()){
                int D=message[S][k];
                if(treeind[S] != treeind[D]){
                    puts("No");
                    return 0;
                }
                S=uf.find(S);
                D=uf.find(D);
                int LCA=lca(S, D);
                send[S]=min(send[S], LCA);
                receive[D]=min(receive[D], LCA);
            }
        }
        check(root);
    }
    puts("Yes");
}