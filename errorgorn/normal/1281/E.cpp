#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<ii> al[200005];
long long G,B;

int par[200005];
int sz[200005];
void dfs(int i,int p){
    par[i]=1;
    sz[i]=1;
    
     for (auto it:al[i]){
         if (it.first==p) continue;
         dfs(it.first,i);
         if (par[it.first]) G+=it.second;
         B+=min(n-sz[it.first],sz[it.first])*(long long)it.second;
         
         sz[i]+=sz[it.first];
         par[i]+=par[it.first];
     }
     
     par[i]%=2;
}
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        G=B=0;
        scanf("%d",&n);
        n<<=1;
        for (int x=1;x<=n;x++) al[x].clear();
        
        int a,b,c;
        for (int x=1;x<n;x++){
            scanf("%d%d%d",&a,&b,&c);
            al[a].push_back(ii(b,c));
            al[b].push_back(ii(a,c));
        }
        
        dfs(1,-1);
        printf("%lld %lld\n",G,B);
    }
}