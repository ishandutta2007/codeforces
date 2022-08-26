#include<bits/stdc++.h>
#define maxn 500050
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int n,m,a[maxn],b[maxn],x[maxn],y[maxn],v[maxn],t[maxn],vis[maxn],N;
map <int,int> f;
vector <int> h[maxn],d;
ll ans,s;
void add(int x){
    while (x<maxn){
        b[x]++;
        x+=x&(-x);
    }
}
int qry(int x){
    int ret=0;
    while (x){
        ret+=b[x];
        x-=x&(-x);
    }
    return ret;
}
ll C2(int x){
    return 1ll*x*(x+1)/2;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);

    for (int i=1;i<=n;i++) t[i]=x[i]; sort(t+1,t+1+n);
    m=0; for (int i=1;i<=n;i++) if (t[i]!=t[i-1]) v[++m]=t[i];
    f.clear(); for (int i=1;i<=m;i++) f[v[i]]=i;
    for (int i=1;i<=n;i++) x[i]=f[x[i]]; N=m;

    for (int i=1;i<=n;i++) t[i]=y[i]; sort(t+1,t+1+n);
    m=0; for (int i=1;i<=n;i++) if (t[i]!=t[i-1]) v[++m]=t[i];
    f.clear(); for (int i=1;i<=m;i++) f[v[i]]=i;
    for (int i=1;i<=n;i++) y[i]=f[y[i]];

    for (int i=1;i<=n;i++) h[y[i]].pb(x[i]);
    for (int i=m;i;i--){
        for (auto x:h[i]) if (!vis[x]) vis[x]=1,add(x);
        ans+=C2(qry(N)); d.clear();
        d.pb(0); d.pb(qry(N)+1);
        for (auto x:h[i]) d.pb(qry(x));
        sort(d.begin(),d.end());
        for (int i=1;i<d.size();i++) ans-=C2(d[i]-d[i-1]-1);
    }
    cout << ans << endl;
    return 0;
}