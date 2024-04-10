#include <cstdio>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
vector<int> al[100005];
set<ii> e;
bool visited[100005];
int dfs(int i){
    int ans=1;
    visited[i]=true;
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (!visited[*it]) ans+=dfs(*it);
    }
    return ans;
}
int main(){
    int ans=0;
    scanf("%d%d",&n,&m);
    int a,b;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        if (a>b) swap(a,b);
        if (!e.count(ii(a,b))){
            e.insert(ii(a,b));
            al[a].push_back(b);
            al[b].push_back(a);
        }
    }
    for (int x=1;x<=n;x++){
        if (!al[x].empty() && !visited[x]) ans+=dfs(x)-1;
    }
    printf("%d\n",m-ans);
}