#include <cstdio>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<long long,int> li;
int n,m;
vector<ii> al[100005];
int parent[100005];
long long w[100005];
priority_queue<li, vector<li>, greater<li> > pq;
int main(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for (int x=0;x<m;x++){
        scanf("%d%d%d",&a,&b,&c);
        al[a].push_back(ii(b,c));
        al[b].push_back(ii(a,c));
    }
    memset(w,127,sizeof(w));

    w[1]=0;
    pq.push(li(w[1],1));
    long long temp;
    int node;
    while (!pq.empty()){
        temp=pq.top().first;
        node=pq.top().second;
        pq.pop();
        if (temp>w[node]) continue; //important
        for (vector<ii>::iterator it=al[node].begin();it!=al[node].end();it++){
            if (w[(*it).first]>temp+(*it).second){
                w[(*it).first]=temp+(*it).second;
                parent[(*it).first]=node;
                pq.push(li (w[(*it).first],(*it).first));
            }
        }
    }
    if (w[n]==9187201950435737471) {
        printf("-1\n");
        return 0;
    }
    parent[1]=-1;
    vector<int> fin;
    int curr=n;
    while (curr!=-1){
        fin.push_back(curr);
        curr=parent[curr];
    }
    while (!fin.empty()){
        printf("%d ",fin.back());
        fin.pop_back();
    }
}