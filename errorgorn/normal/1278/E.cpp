#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int n;
vector<int> al[500005];

ii fin[500005];
int END=2;

void dfs(int i,int p){
    int last=END+al[i].size()-1;
    if (p==-1) last++;
    fin[i].second=last;
    END=last+1;
    for (auto &it:al[i]){
        if (it==p) continue;
        last--;
        fin[it].first=last;
        dfs(it,i);
    }
}
int main(){
    scanf("%d",&n);
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    fin[1].first=1;
    dfs(1,-1);
    
    for (int x=1;x<=n;x++) printf("%d %d\n",fin[x].first,fin[x].second);
}