#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector < vector <int> > g,who;
int d[100005],mn[100005],mx[100005];
int used[100005],finish[100005];
vector < vector <int> > in;
int deg[100005];

pair <int,int> go(int v) {
    if (used[v]==2) return make_pair(mn[v],mx[v]);
    if (used[v]==1) {
        if (finish[v]) return make_pair(-2,-2);
        else return make_pair(-1,-1);
    }
    used[v]=1;
    mx[v]=0;
    for(int i=0;i<who[v].size();++i) {
        int t=who[v][i];
        int minv=d[t],maxv=d[t];
        bool ok=true;
        for(int j=0;j<g[t].size();++j) {
            pair <int,int> p=go(g[t][j]);
            if (!finish[g[t][j]]) {
                ok=false;
                break;
            }
            if (maxv!=-2) {
                if (p.second==-2) maxv=-2;
                else if (p.second==-3) maxv=-3;
                else {
                    maxv+=p.second;
                    maxv=min(maxv,314000000);
                }
            }
        }
        if (!ok) continue;

        if (maxv==-2) mx[v]=-2;
        else if (maxv==-3) {
            if (mx[v]!=-2) mx[v]=-3;
        } else {
            if (mx[v]!=-2&&mx[v]!=-3) mx[v]=max(mx[v],maxv);
        }
    }
    used[v]=2;
    return make_pair(mn[v],mx[v]);
}
int type[100005],addm[100005];

struct cmp {
    bool operator () (pair <pair<int,int>,int> a,pair <pair<int,int>,int> b) {
        return a.first.first>b.first.first||a.first.first==b.first.first&&a.first.second>b.first.second;
    }
};

priority_queue < pair<pair <int,int>,int>, vector <pair <pair<int,int>,int> >, cmp > q;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int m,n;
    scanf("%d%d",&m,&n);
    g.resize(m); who.resize(n);
    in.resize(n);
    for(int i=0;i<m;++i) {
        int t,l,a;
        scanf("%d%d",&t,&l); --t;
        who[t].push_back(i); type[i]=t;
        for(int j=0;j<l;++j) {
            scanf("%d",&a);
            if (a==-1) d[i]++;
            else {
                g[i].push_back(a-1);
                in[a-1].push_back(i);
                deg[i]++;
            }
        }
    }
    for(int i=0;i<n;++i) mn[i]=-2;
    memcpy(addm,d,sizeof(addm));
    for(int i=0;i<m;++i)
        q.push(make_pair(make_pair(deg[i],addm[i]),i));
    while(q.size()) {
        pair <pair<int,int>,int> p=q.top(); q.pop();
        if (make_pair(deg[p.second],addm[p.second])!=p.first) continue;
        if (p.first.first==0&&!finish[type[p.second]]) {
            finish[type[p.second]]=true;
            if (addm[p.second]!=-2)
                mn[type[p.second]]=addm[p.second];
            for(int j=0;j<in[type[p.second]].size();++j) {
                deg[in[type[p.second]][j]]--;
                if (mn[type[p.second]]==-2) addm[in[type[p.second]][j]]=-2;
                else if (addm[in[type[p.second]][j]]!=-2)
                    addm[in[type[p.second]][j]]=min(314000000,addm[in[type[p.second]][j]]+mn[type[p.second]]);
                q.push(make_pair(make_pair(deg[in[type[p.second]][j]],addm[in[type[p.second]][j]]),in[type[p.second]][j]));
            }
        }
    }
    for(int i=0;i<n;++i)
        if (!used[i]) go(i);
    for(int i=0;i<n;++i)
        printf("%d %d\n",finish[i] ? mn[i] : -1,finish[i] ? mx[i] : -1);
    return 0;
}