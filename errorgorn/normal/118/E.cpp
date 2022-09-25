#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;
typedef pair<int,int> ii;

void quit(){
    printf("0\n");
    exit(0);
}

int n,m;
vector<int> al[100005];
int counter;

int dfs_time[100005];
int low[100005];
vector<ii> fin;
void dfs(int i,int p){
    //printf("dfs: %d %d\n",i,p);
    dfs_time[i]=low[i]=counter++;
    for (auto &it:al[i]){
        if (it==p) continue;
        if (dfs_time[it]){
            low[i]=min(low[i],dfs_time[it]);
            if (dfs_time[it]>dfs_time[i]) fin.push_back(ii(it,i));
        }
        else{
            dfs(it,i);
            if (low[it]>dfs_time[i]) quit();
            low[i]=min(low[i],low[it]);
            fin.push_back(ii(i,it));
        }
    }
}


int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    while (m--){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    counter=1;
    dfs(1,-1);
    
    for (int x=0;x<fin.size();x++){
        printf("%d %d\n",fin[x].first,fin[x].second);
    }
}