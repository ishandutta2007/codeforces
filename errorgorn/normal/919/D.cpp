#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,m;
char val[300005];
vector<int> al[300005];
bool onstack[300005];

void quit(){
    printf("-1\n");
    exit(0);
}

bool visited[300005];
vector<int> ts;
void dfs(int i){
    onstack[i]=true;
    visited[i]=true;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if (onstack[*it]) quit();
        if (!visited[*it]){
            dfs(*it);
        }
    }
    ts.push_back(i);
    onstack[i]=false;
}

int memo[300005][26];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",&val);
    
    int a,b;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
    }
    
    
    for (int x=1;x<=n;x++) if (!visited[x]) dfs(x);
    reverse(ts.begin(),ts.end());
    
    int ans=0;
    int node;
    for (int x=0;x<n;x++){
        node=ts[x];
        ans=max(ans,++memo[node][val[node-1]-'a']);
        for (auto &it:al[node]){
            for (int y=0;y<26;y++) memo[it][y]=max(memo[it][y],memo[node][y]);
        }
    }
    
    printf("%d\n",ans);
}