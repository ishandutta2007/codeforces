#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
bool visited[200005];
vector<int> al[200005];
vector<ii> ranges;
void dfs(int i){
    visited[i]=true;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if (!visited[*it]){
            dfs(*it);
        }
    }
}
vector<ii> compress_ranges(vector<ii> ranges){
    vector<ii> r;
    r.push_back(ranges[0]);
    for (int x=1;x<ranges.size();x++){
        if (r.back().second>=ranges[x].first){
            r.back().second=max(r.back().second,ranges[x].second);
        }
        else{
            r.push_back(ranges[x]);
        }
    }
    return r;
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    while (m--){
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        ranges.push_back(ii(a,b));
        al[a].push_back(b);
        al[b].push_back(a);
    }

    sort(ranges.begin(),ranges.end());

    ranges=compress_ranges(ranges);

    int ans=0;

    for (int x=0;x<ranges.size();x++){
        dfs(ranges[x].first);
        for (int y=ranges[x].first;y<=ranges[x].second;y++){
            if (!visited[y]) dfs(y),ans++;
        }
    }

    printf("%d\n",ans);
}