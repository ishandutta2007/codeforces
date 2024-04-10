#include <cstdio>
#include <vector>
using namespace std;
int TC,n,m;
vector<int> al[200005];
vector<int> black,white; ///store bipartite edges
bool visited[200005];
void init(int i){
    for (int x=0;x<=i;x++){
        al[x].clear();
        visited[x]=false;
    }
    black.clear();
    white.clear();
}
void dp(int i,bool j){
    visited[i]=true;
    if (j) black.push_back(i);
    else white.push_back(i);
    for (vector<int>::iterator it=al[i].begin();it!=al[i].end();it++){
        if (!visited[*it]) dp(*it,!j);
    }
}
int main(){
    scanf("%d",&TC);
    while (TC--){
        scanf("%d%d",&n,&m);
        init(n);
        int a,b;
        while (m--){
            scanf("%d%d",&a,&b);
            al[a].push_back(b);
            al[b].push_back(a);
        }
        dp(1,true);
        if (white.size()>black.size()) white.swap(black);
        printf("%d\n",white.size());
        for (int x=0;x<white.size();x++){
            printf("%d ",white[x]);
        }
        printf("\n");
    }
}