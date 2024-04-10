#include<bits/stdc++.h>
#define maxn 603

using namespace std;
int a[maxn],c[maxn][maxn],pre[maxn],e[maxn],b[maxn],n,p[maxn],m,r,f[maxn];
vector<int>h[maxn];

void add_edge(int u,int v){
    h[u].push_back(v);
    h[v].push_back(u);
}

void dfs(int x,int fa,int o){
    e[x]=o; pre[x]=fa;
    for (int i=0;i<h[x].size();i++){
        int y=h[x][i];
        if (y==fa) continue;
        dfs(y,x,o^1);
    }
}

int sum[maxn];
int qry1(int l,int r){
    if (l==1&&sum[r]!=-1) return sum[r];
    printf("? %d\n",r-l+1);
    for (int i=l;i<=r;i++) printf("%d ",a[i]); printf("\n");
    fflush(stdout);
    int w;scanf("%d",&w);
    return w;
}
int qry1(int d,int l,int r){
    printf("? %d\n",r-l+2);
    for (int i=l;i<=r;i++) printf("%d ",a[i]); printf("%d\n",d);
    fflush(stdout);
    int w;scanf("%d",&w);
    return w;
}

int qry2(int l,int r){
    printf("? %d\n",r-l+1);
    for (int i=l;i<=r;i++) printf("%d ",b[i]); printf("\n");
    fflush(stdout);
    int w;scanf("%d",&w);
    return w;
}

int qry1(int l,int r,int ll,int rr){
    printf("? %d\n",r-l+1+rr-ll+1);
    for (int i=l;i<=r;i++) printf("%d ",a[i]);
    for (int i=ll;i<=rr;i++) printf("%d ",a[i]); printf("\n");
    fflush(stdout);
    int w;scanf("%d",&w);
    return w-qry1(l,r)-qry1(ll,rr);
}

int qry2(int l,int r,int ll,int rr){
    printf("? %d\n",r-l+1+rr-ll+1);
    for (int i=l;i<=r;i++) printf("%d ",a[i]);
    for (int i=ll;i<=rr;i++) printf("%d ",b[i]); printf("\n");
    fflush(stdout);
    int w;scanf("%d",&w);
    return w-qry1(l,r)-qry2(ll,rr);
}

int ans[maxn],cc;
void solve(int l,int r,int ll,int rr){
    if (l!=r){
        int mid=(l+r)/2;
        if (qry1(l,mid,ll,rr)) solve(l,mid,ll,rr);
        else solve(mid+1,r,ll,rr);
    } else if (ll!=rr){
        int mid=(ll+rr)/2;
        if (qry1(l,r,ll,mid)) solve(l,r,ll,mid);
        else solve(l,r,mid+1,rr);
    } else {
        int s=a[l],t=a[ll];
        dfs(s,0,0); cc=0;
        while (t!=s) ans[cc++]=t,t=pre[t];
        ans[cc++]=s;
        printf("N %d\n",cc);
        for (int i=0;i<cc;i++) printf("%d ",ans[i]); printf("\n");
    }
}

void solve(int l,int r){
    int mid=(l+r)/2;
    if (qry1(l,mid)) solve(l,mid);
    else if (qry1(mid+1,r)) solve(mid+1,r);
    else solve(l,mid,mid+1,r);
}

int solve1(int x,int l,int r){
    if (l==r) return l;
    int mid=(l+r)/2;
    if (qry2(1,x,l,mid)) solve1(x,l,mid);
    else solve1(x,mid+1,r);
}

int lowbit(int x){
    return x&(-x);
}

int solve2(int x,int l,int r){
    if (l==r) return r;
    int mid;
    for (int i=0;i<10;i++) if (l+(1<<i)<=r) mid=l+(1<<i)-1;
    if (c[l][mid]==-1){
        printf("N 2\n%d %d\n",l,mid);
        return -1;
    }
    if (qry1(x,l,mid)-c[l][mid]) solve2(x,l,mid);
    else solve2(x,mid+1,r);
}

int main(){
    cin >> n;
    if (n<3){
        printf("Y 1\n1\n");return 0;
    }
    memset(c,-1,sizeof(c));
    a[1]=1; f[1]=1; c[1][1]=0;
    memset(sum,-1,sizeof(sum));
    for (int i=2;i<=n;i++){
        int cnt=0; sum[i-1]=qry1(1,i-1);
        for (int j=1;j<=n;j++) if (!f[j]) b[++cnt]=j;
        int x=solve1(i-1,1,cnt),y=b[x];
        int z=solve2(y,1,i-1);
        if (z==-1)return 0;
        add_edge(a[z],y);
        a[i]=y; f[y]=1; c[i][i]=0;
        for (int j=2;i%j==0;j+=j){
            c[i-j+1][i]=qry1(i-j+1,i);
        }
    }
    dfs(1,0,0);
    int cnt=0;
    memset(sum,-1,sizeof(sum));
    for (int i=1;i<=n;i++) if (!e[i]) a[++cnt]=i;
    if (qry1(1,cnt)) {
        solve(1,cnt);
        return 0;
    }
    cnt=0;
    for (int i=1;i<=n;i++) if (e[i]) a[++cnt]=i;
    if (qry1(1,cnt)) {
        solve(1,cnt);
        return 0;
    }
    printf("Y %d\n",cnt);
    for (int i=1;i<=cnt;i++) printf("%d ",a[i]); printf("\n");
    return 0;
}