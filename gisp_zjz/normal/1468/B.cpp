#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxn=3e5+10;
bool vis[maxn];
int n,m,r[maxn],sz[maxn],maxsize;
ull a[maxn],b[maxn],ans[maxn];
struct node{ull sum;int tot,id;};
node p[maxn];
struct Cmp{
    bool operator()(const node &u,const node &v){
        return u.sum*v.tot<v.sum*u.tot;
    }
};
bool cmp(node &u,node &v){
    return u.sum*v.tot<v.sum*u.tot;
}
priority_queue<node,vector<node>,Cmp> q;
void _union(int x,int y){
    r[x]=r[y]; vis[y]=1;
    p[x].tot+=p[y].tot;
    p[x].sum+=p[y].sum;
    sz[x]+=sz[y];
    q.push(p[x]);
}
int main(){
    scanf("%d%d",&n,&m); int tmpm=m;
    for (int i=1;i<=n;i++) scanf("%llu",&a[i]);
    for (int i=1;i<=m;i++) scanf("%llu",&b[i]);
    --n; maxsize=1;
    for (int i=1;i<=n+1;i++) {
        r[i]=i; sz[i]=1;
        p[i].tot=1; p[i].sum=a[i]; p[i].id=i;
        if (i<=n) q.push(p[i]);
    }
    while (m>0&&q.size()>0&&q.top().sum<=b[m]) m--;
    while (q.size()>0){
        if (vis[q.top().id]) {q.pop();continue;}
        while (m>0&&q.top().sum<=b[m]*q.top().tot) ans[m--]=maxsize-1;
        node tmp=q.top(); q.pop();
        int L=tmp.id,R=r[L];
        if (R==n+1) continue;
        _union(L,R+1);
        maxsize=max(maxsize,sz[L]);
    }
    while (m>0) ans[m--]=maxsize-1;
    for (int i=1;i<=tmpm;i++) printf("%d ",ans[i]);puts("");
    return 0;
}