#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> ii;
typedef pair<long long ,ii> iii;
int n,m,k,q;
vector<ii> al[100005];
ii p[100005][20]; //this is for 2k decomp initialize everything to -1
int depth[100005];
priority_queue<ii, vector<ii>, greater<ii> > pq;
long long w[100005];
vector<iii> edges;
int pa[100005],r[100005]; //parent and rank array for UDFS
int parent(int i){ return (pa[i]==i)? i: pa[i]=parent(pa[i]);}
void unions(int i, int j){
    i=parent(i),j=parent(j);
    if (r[i]>r[j]){
        pa[j]=i;
    }
    else{
        pa[i]=j;
        if (r[i]==r[j]) r[i]++;
    }
}
void dfs(int i,int pp){ //dfs from source to preprocess the 2k decomp
    int curr;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if ((*it).first==pp) continue;

        p[(*it).first][0]=ii(i,(*it).second);
        curr=i;
        for (int x=0;p[curr][x]!=ii(-1,-1);x++){
            p[(*it).first][x+1].second=max(p[(*it).first][x].second,p[curr][x].second);
            curr=p[(*it).first][x+1].first=p[curr][x].first;
        }

        depth[(*it).first]=depth[i]+1;
        dfs((*it).first,i);
    }
}

long long query(int i,int j){
    long long ans=0;

    if (depth[i]<depth[j]) swap(i,j);

    int climb=depth[i]-depth[j];

    for (int x=0;x<20;x++){
        if (climb&1){
            ans=max(ans,p[i][x].second);
            i=p[i][x].first;
        }
        climb>>=1;
    }

    if (i==j) return ans;

    for (int x=19;x>=0;x--){
        if (p[i][x].first!=p[j][x].first){
            ans=max(ans,max(p[i][x].second,p[j][x].second));
            i=p[i][x].first;
            j=p[j][x].first;
        }
    }

    return max(ans,max(p[i][0].second,p[j][0].second));
}

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&q);

    int a,b;
    long long c;
    for (int x=0;x<m;x++){
        scanf("%d%d%lld",&a,&b,&c);
        al[a].push_back(ii(b,c));
        al[b].push_back(ii(a,c));
        edges.push_back(iii(c,ii(a,b)));
    }

    memset(w,127,sizeof(w));
    for (int x=1;x<=k;x++) {
        w[x]=0;
        pq.push(ii(w[x],x));
    }
    long long temp;
    int node;
    while (!pq.empty()){
        temp=pq.top().first;
        node=pq.top().second;
        pq.pop();
        if (temp>w[node]) continue; //important
        for (vector<ii>::iterator it=al[node].begin();it!=al[node].end();it++){
            if (w[(*it).first]>w[node]+(*it).second){
                w[(*it).first]=w[node]+(*it).second;
                pq.push(ii (w[(*it).first],(*it).first));
            }
        }
    }

    for (int x=0;x<m;x++){
        edges[x].first+=w[edges[x].second.first]+w[edges[x].second.second];
    }

    for (int x=1;x<=n;x++) pa[x]=x,al[x].clear();

    sort(edges.begin(),edges.end());
    reverse(edges.begin(),edges.end());

    int components=n;
    while (components!=1){
        a=edges.back().second.first,b=edges.back().second.second,c=edges.back().first;

        if (parent(a)!=parent(b)){
            components--;
            unions(a,b);
            al[a].push_back(ii(b,c));
            al[b].push_back(ii(a,c));
        }

        edges.pop_back();
    }

    memset(p,-1,sizeof(p));
    dfs(1,-1);

    while (q--){
        scanf("%d%d",&a,&b);
        printf("%lld\n",query(a,b));
    }
}