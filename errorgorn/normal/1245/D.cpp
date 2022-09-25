#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
ii pos[2005];
long long c[2005];
long long k[2005];
struct edge{
    int s,e;
    long long cost;
    edge (int ss,int ee, long long cc){
        s=ss;
        e=ee;
        cost=cc;
    }
};
vector<edge> edges;
int p[2005],r[2005]; //parent and rank array for UDFS
int parent(int i){ return (p[i]==i)? i: p[i]=parent(p[i]);}
void unions(int i, int j){
    i=parent(i),j=parent(j);
    if (r[i]>r[j]){
        p[j]=i;
    }
    else{
        p[i]=j;
        if (r[i]==r[j]) r[i]++;
    }
}

vector<int> power;
vector<ii> conect;

int main(){
    for (int x=0;x<2005;x++) p[x]=x;
    scanf("%d",&n);
    for (int x=1;x<=n;x++) scanf("%d%d",&pos[x].first,&pos[x].second);
    for (int x=1;x<=n;x++) scanf("%lld",&c[x]);
    for (int x=1;x<=n;x++) scanf("%lld",&k[x]);

    for (int x=1;x<=n;x++){
        edges.push_back(*new edge(0,x,c[x]));
    }

    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            if (x==y) continue;
            edges.push_back(*new edge(x,y, (abs(pos[x].first-pos[y].first)+abs(pos[x].second-pos[y].second))*(k[x]+k[y]) ));
        }
    }

    sort(edges.begin(),edges.end(),[](edge &i, edge&j){
        return i.cost>j.cost;
    });

    long long ans=0;
    int u=n;
    int s,e;
    long long cost;
    while (u){
        s=edges.back().s;
        e=edges.back().e;
        cost=edges.back().cost;
        edges.pop_back();
        if (parent(s)!=parent(e)){
            u--;
            ans+=cost;
            unions(s,e);

            if (s==0) power.push_back(e);
            else conect.push_back(ii(s,e));
        }
    }

    printf("%lld\n",ans);
    printf("%d\n",power.size());
    for (int x=0;x<power.size();x++) printf("%d ",power[x]);
    printf("\n");
    printf("%d\n",conect.size());
    for (int x=0;x<conect.size();x++) printf("%d %d\n",conect[x].first,conect[x].second);
}