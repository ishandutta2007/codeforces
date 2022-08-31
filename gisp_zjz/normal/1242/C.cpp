#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=100005;
map <ll,int> f;
int ans[1<<15];
int b[15][5555],tot,sz[15],pos[maxn],loc[maxn],g[maxn],pre[1<<15],B[15],n;
ll a[15][5555],A[15];
bool dp[1<<15];
ll sum,s[15],req[15];
int go(int x,ll val){
    bool vis[15];
    for (int i=0;i<n;i++) vis[i]=0;
    int tmp=x,mask=1<<x;
    ll tmp_val=val;
    while (1){
        vis[x]=1;
        if (f.find(val+req[x])==f.end()) return -1;
        int p=f[val+req[x]];
        int y=pos[p];
        A[x]=val; B[y]=x;
        if (y==tmp) {
            if (tmp_val==a[y][loc[p]]) return mask;
            return -1;
        }
        if (vis[y]) return -1;
        val=a[y][loc[p]]; x=y; mask|=1<<x;
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&sz[i]);
        for (int j=1;j<=sz[i];j++){
            ll x; scanf("%lld",&a[i][j]);
            x=a[i][j];
            s[i]+=x;
            f[x]=++tot;
            pos[tot]=i;
            loc[tot]=j;
            b[i][j]=tot;
        }
        sum+=s[i];
    }
    if (sum%n){puts("No");return 0;}
    for (int i=0;i<n;i++) req[i]=sum/n-s[i];
    for (int i=0;i<n;i++)
    for (int j=1;j<=sz[i];j++){
        int x=go(i,a[i][j]);
        if (x==-1) continue;
        if (!ans[x]) ans[x]=b[i][j];
    }
    memset(pre,-1,sizeof(pre));
    pre[0]=0;
    for (int i=1;i<(1<<n);i++){
        for (int j=i;;j=(j-1)&i){
            if (pre[i^j]!=-1&&ans[j]) {pre[i]=j;break;}
            if (!j) break;
        }
    }
    if (pre[(1<<n)-1]==-1) {puts("No");return 0;}
    int r=(1<<n)-1;
    while (r) {
        int x=pre[r]; r^=x;
        int y=ans[x];
        assert(x==go(pos[y],a[pos[y]][loc[y]]));
    }
    for (int i=0;i<n;i++) s[i]-=A[i],s[B[i]]+=A[i];
    for (int i=0;i<n;i++) assert(s[i]==sum/n);
    puts("Yes");
    for (int i=0;i<n;i++) printf("%lld %d\n",A[i],B[i]+1);
    return 0;
}