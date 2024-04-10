#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int c[1100];
int v[1100];
pair<int,int>cost[1100];
vector<int>g[1100];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",c+i);
        cost[i]=make_pair(-c[i],i);
    }
    for(int i=0;i<b;i++){
        int p,q;
        scanf("%d%d",&p,&q);
        p--;q--;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    std::sort(cost,cost+a);
    int ret=0;
    for(int i=0;i<a;i++){
        int at=cost[i].second;
        v[at]=1;
        for(int j=0;j<g[at].size();j++){
            if(!v[g[at][j]])ret+=c[g[at][j]];
        }
    }
    printf("%d\n",ret);
}