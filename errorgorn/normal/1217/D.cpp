#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n,m;
vector<ii> al[5005];
bool visited[5005];
int color[5005];
bool onstack[5005];
void dfs(int i){
    visited[i]=true;
    onstack[i]=true;
    for (vector<ii>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (visited[(*it).first]) color[(*it).second]=(onstack[(*it).first]?2:1);
        else color[(*it).second]=1, dfs((*it).first);
    }
    onstack[i]=false;
}

int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    int counter=0;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(ii(b,counter++));
    }
    for (int x=1;x<=n;x++){
        if (!visited[x]) dfs(x);
    }
    int ans=0;
    for (int x=0;x<m;x++){
        ans=max(ans,color[x]);
    }
    printf("%d\n",ans);
    for (int x=0;x<m;x++){
        printf("%d ",color[x]);
    }
}