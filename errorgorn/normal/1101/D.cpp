#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
int val[200005];
vector<int> al[200005];
vector<int> pfactors[200005];

int ans=0;

vector<ii> dfs(int i,int p){
    vector<ii> rope;
    for (auto &it: pfactors[val[i]]){
        rope.push_back(ii(it,1));
    }
    
    vector<ii> temp;
    for (auto &it:al[i]){
        if (it==p) continue;
        temp=dfs(it,i);
        for (auto &tit:temp){
            for (auto &rit:rope){
                if (tit.first!=rit.first) continue;
                
                ans=max(ans,tit.second+rit.second);
                rit.second=max(rit.second,tit.second+1);
            }
        }
    }
    
    return rope;
}

int main(){
    for (int x=2;x<200005;x++){
        if (pfactors[x].empty()){
            for (int y=x;y<200005;y+=x) pfactors[y].push_back(x);
        }
    }

    scanf("%d",&n);
    for (int x=1;x<=n;x++) scanf("%d",&val[x]);
    for (int x=1;x<=n;x++) if (val[x]>1) ans=1;
    
    int a,b;
    for (int x=1;x<n;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    dfs(1,-1);
    printf("%d\n",ans);
}