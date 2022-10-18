#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

vector < vector <int> > g,d;
bool leave[100005];
int from[100005];
int n,l,w;

pair <int,int> dfs_d(int v,int dist = 0,int par = -1) {
    pair <int,int> ret=make_pair(dist,v);
    for(int i=0;i<g[v].size();++i) {
        if (g[v][i]!=par&&!leave[g[v][i]]) {
            from[g[v][i]]=v;
            ret=max(ret,dfs_d(g[v][i],dist+1,v));
        }
    }
    return ret;
}

int findDiameter(int start) {
    pair <int,int> p=dfs_d(start);
    p=dfs_d(p.second);
    int cur=p.second,left=p.first/2;
    while(left--) {
        cur=from[cur];
    }
    return cur;
}

struct item {
    int w,l;
};

bool operator < (const item & a,const item & b) {
    return a.w<b.w;
}

vector <item> vec,child[100005];

void dfs(int v,int len,int weight,int color,int par = -1) {
    item it={weight,len};
    child[color].push_back(it);
    for(int i=0;i<g[v].size();++i) {
        int to=g[v][i];
        if (to!=par&&!leave[to]) dfs(to,len+1,weight+d[v][i],color,v);
    }
}

int fen[100005];

void update(int pos,int val) {
    for(;pos<=n;pos|=(pos+1))
        fen[pos]+=val;
}

int find(int pos) {
    int ret=0;
    for(;pos>=0;pos=(pos&(pos+1))-1)
        ret+=fen[pos];
    return ret;
}

long long calc(vector <item> & v) {
    long long ret=0;
    sort(v.begin(),v.end());
    int left=0;
    for(int i=v.size()-1;i>=0;--i) {
        while(left<i&&v[left].w+v[i].w<=w) {
            update(v[left].l,1);
            ++left;
        }
        while(left>i) {
            update(v[--left].l,-1);
        }
        ret+=find(l-v[i].l);
    }
    return ret;
}

long long solve(int start) {
    start=findDiameter(start);
    int cnt=1;
    vec.clear();
    item it={0,0}; vec.push_back(it);
    for(int i=0;i<g[start].size();++i) {
        if (!leave[g[start][i]]) {
            child[cnt].clear();
            dfs(g[start][i],1,d[start][i],cnt++,start);
            vec.insert(vec.end(),child[cnt-1].begin(),child[cnt-1].end());
        }
    }
    long long ans=calc(vec);
    for(int i=1;i<cnt;++i)
        ans-=calc(child[i]);
    leave[start]=true;
    for(int i=0;i<g[start].size();++i)
        if (!leave[g[start][i]]) ans+=solve(g[start][i]);
    return ans;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&l,&w);
    d.resize(n); g.resize(n);
    int p,w;
    for(int i=1;i<n;++i) {
        scanf("%d%d",&p,&w); --p;
        g[i].push_back(p);
        d[i].push_back(w);
        g[p].push_back(i);
        d[p].push_back(w);
    }
    cout << solve(0) << endl;
    return 0;
}