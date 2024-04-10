#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=505050;
int ans[maxn],a[maxn],n,occ,sz[maxn],color[maxn],vis[maxn],c[2];
bool scc;
vector <int> h[maxn];
vector <int> v[50],p;
const int E=6000;
set <int> s;
mt19937_64 gen(time(0));

void solve2(int x){
    if (s.find(x)!=s.end()) return;
    s.insert(x); occ=0;
    for (int i=0;i<n;i++) if (a[i]%x==0) occ++;
    if (occ>=n/2) p.pb(x);
}
void solve(int x){
    int j=2;
    while (j*j<=x){
        if (x%j==0){
            solve2(j);
            while (x%j==0) x/=j;
        }
        ++j;
    }
    if (x>1) solve2(x);
}
void add_edge(int x,int y){
    if (s.find(x)==s.end()) s.insert(x);
    if (s.find(y)==s.end()) s.insert(y);
    h[x].pb(y); h[y].pb(x);
}
void dfs(int x,int o){
    vis[x]=1; color[x]=o;
    for (auto y:h[x]){
        if (vis[y]){
            if (color[x]==color[y]) scc=0;
            continue;
        }
        dfs(y,o^1);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int T=0;T<25;T++){
        int id=gen()%n;
        solve(a[id]);
    }
    int m=p.size();
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++) if (a[j]%p[i]!=0) v[i].pb(j);
        sz[i]=v[i].size();
        if (v[i].size()<=1) {puts("NO");return 0;}
    }

    for (int temp=0;temp<E;temp++){
        s.clear(); scc=1;
        for (int i=0;i<m;i++){
            int x=0,y=0;
            while (x==y){
                x=gen()%sz[i];
                y=gen()%sz[i];
            }
            add_edge(v[i][x],v[i][y]);
        }
        for (auto x:s) if (!vis[x]) dfs(x,0);
        if (scc){
            c[0]=c[1]=0;
            for (auto x:s) c[color[x]]++;
            if (c[0]<=n-n/2&&c[1]<=n-n/2){
                for (int i=0;i<n;i++) if (s.find(i)==s.end()) {
                    if (c[0]<n/2) color[i]=0,c[0]++;
                    else color[i]=1,c[1]++;
                }
                int ans1=0,ans2=0;
                for (int i=0;i<n;i++) if (color[i]) ans1=__gcd(ans1,a[i]); else ans2=__gcd(ans2,a[i]);
                assert(ans1==1&&ans2==1);
                puts("YES");
                for (int i=0;i<n;i++) printf("%d ",color[i]+1); puts("");
                return 0;
            }
        }
        for (auto x:s) h[x].clear(),vis[x]=0;
    }
    puts("NO");
    return 0;
}