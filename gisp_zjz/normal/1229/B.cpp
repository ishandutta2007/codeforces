#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int M=1000000007;
const int maxn=1e5+3;
ll v[maxn][43],a[maxn],ans;
int p[maxn][43];
vector <int> h[maxn];
int n,d[maxn],cnt[maxn];
void dfs(int u,int fa){
    if (!fa){
        cnt[u]=1;
        d[u]=1;
        p[u][1]=1;
        v[u][1]=a[u];
    } else {
        cnt[u]=cnt[fa]+1;
        d[u]=d[fa]+1;
        for (int i=1;i<=cnt[fa];i++){
            p[u][i]=p[fa][i];
            v[u][i]=__gcd(v[fa][i],a[u]);
        }
        p[u][cnt[u]]=d[u];
        v[u][cnt[u]]=a[u];

        for (int i=1;i<cnt[u];i++) if (v[u][i]==v[u][i+1]){
            for (int j=i;j<cnt[u];j++) v[u][j]=v[u][j+1],p[u][j]=p[u][j+1];
            cnt[u]--;
        }

    }
    for (int i=1;i<=cnt[u];i++){
        //cout<<u<<' '<<v[u][i]<<' '<<p[u][i]<<endl;
        (ans+=v[u][i]*(p[u][i]-p[u][i-1]))%=M;
    }
    //cout<<u<<' '<<ans<<endl;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0);
    printf("%lld\n",((ans%M)+M)%M);
}