#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;
bool root[100005];
int val[100005];
int left[100005];
int right[100005];
unordered_set <int> s;
void dfs(int node,int l,int r){
    if (l>r) return;
    if (l<=val[node] && val[node]<=r) s.insert(val[node]);
    if (left[node]!=-1) dfs(left[node],l,min(val[node]-1,r));
    if (right[node]!=-1) dfs(right[node],max(val[node],l),r);
}
int main(){
    int n;
    scanf("%d",&n);
    for (int x=1;x<=n;x++){
        scanf("%d%d%d",&val[x],&left[x],&right[x]);
        if (left[x]!=-1) root[left[x]]=true;
        if (right[x]!=-1) root[right[x]]=true;
    }
    for (int x=1;x<=n;x++){
        if (!root[x]){
            dfs(x,0,1000000000);
            break;
        }
    }
    int ans=0;
    for (int x=1;x<=n;x++){
        if (!s.count(val[x])) ans++;
    }
    printf("%d\n",ans);
}