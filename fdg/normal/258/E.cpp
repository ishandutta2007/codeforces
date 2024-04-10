#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:256000000")

using namespace std;

vector < vector <int> > g;
int sz[100005];
int l[100005],r[100005];
int what[100005];

int dfs(int v,int par = -1) {
    sz[v]=1;
    for(int i=0;i<g[v].size();++i)
        if (g[v][i]!=par) sz[v]+=dfs(g[v][i],v);
    return sz[v];
}

void go(int v,int L,int R,int par = -1) {
//  cout << v << "  " << L << " " << R << endl;
    l[v]=L; r[v]=R;
    what[v]=L++;
    for(int i=0;i<g[v].size();++i)
        if (g[v][i]!=par) {
            go(g[v][i],L,L+sz[g[v][i]]-1,v);
            L+=sz[g[v][i]];
        }
}

int tree[801005];
int add[801005],cnt[801005];

void update(int i,int l,int r,int L,int R,int d) {
    if (add[i]) {
        tree[i]+=add[i];
        if (l!=r) {
            add[2*i]+=add[i];
            add[2*i+1]+=add[i];
        }
        add[i]=0;
    }
    if (l==r) cnt[i]=1;
    if (l==L&&r==R) {
        add[i]+=d;
        return;
    }
    int m=(l+r)>>1;
    if (R<=m) update(2*i,l,m,L,R,d);
    else if (L>m) update(2*i+1,m+1,r,L,R,d);
    else {
        update(2*i,l,m,L,m,d);
        update(2*i+1,m+1,r,m+1,R,d);
    }
    tree[i]=min(tree[2*i]+add[2*i],tree[2*i+1]+add[2*i+1]);
    cnt[i]=0;
    if (tree[i]==tree[2*i]+add[2*i])
        cnt[i]+=cnt[2*i];
    if (tree[i]==tree[2*i+1]+add[2*i+1])
        cnt[i]+=cnt[2*i+1];
}

struct item{
    item(int _x = 0,int _y1 = 0,int _y2 = 0,int _add = 0) : x(_x), y1(_y1), y2(_y2), add(_add) {};
    int x,y1,y2,add;
};

bool operator < (const item & a,const item & b) {
    return a.x<b.x;
}

int res[100005];
vector <item> v;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n);
    for(int i=0;i<n-1;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    go(0,0,n-1);
    v.reserve(1000000);
    for(int i=0;i<n;++i) {
        v.push_back(item(i,i,i,1));
        v.push_back(item(i+1,i,i,-1));
    }
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        int l1=l[a],r1=r[a],l2=l[b],r2=r[b];
        v.push_back(item(l1,l2,r2,1));
        v.push_back(item(r1+1,l2,r2,-1));
        v.push_back(item(l2,l1,r1,1));
        v.push_back(item(r2+1,l1,r1,-1));
        v.push_back(item(l1,l1,r1,1));
        v.push_back(item(r1+1,l1,r1,-1));
        v.push_back(item(l2,l2,r2,1));
        v.push_back(item(r2+1,l2,r2,-1));
//      cout << l1 << " " << r1 << "    " << l2 << "    " << r2 << endl;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;++i)
        update(1,0,n-1,i,i,0);
    for(int i=0,j=0;j<n;++j) {
        while(i<v.size()&&v[i].x<=j) {
            update(1,0,n-1,v[i].y1,v[i].y2,v[i].add);
            ++i;
        }
        if (tree[1]+add[1]==0) ans=n-cnt[1];
        else ans=n;
        if (j<n)
            res[j]=ans-1;
    }
    for(int j=0;j<n;++j) {
        if (j) printf(" ");
        printf("%d",res[what[j]]);
    }
    printf("\n");
    return 0;
}