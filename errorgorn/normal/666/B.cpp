#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n,m;
vector<int> al[100005];
queue<int> q;
int memo[3005][3005];
int w[3005];
vector<ii> singles[3005];
vector<ii> ringles[3005];
void bfs(int i){
    memset(w,-1,sizeof(w));
    w[i]=0;
    q.push(i);
    int node;
    while (!q.empty()){
        node=q.front(),q.pop();
        for (vector<int>::iterator it=al[node].begin();it!=al[node].end();it++){
            if (w[*it]==-1){
                w[*it]=w[node]+1;
                q.push(*it);
            }
        }
    }
    for (int x=1;x<=n;x++) memo[i][x]=w[x];
    memo[i][i]=-1;
}
int main(){
    scanf("%d%d",&n,&m);
    int a,b,c,d;
    for (int x=0;x<m;x++){
        scanf("%d%d",&a,&b);
        al[a].push_back(b);
    }

    for (int x=1;x<=n;x++) bfs(x);

    for (int x=1;x<=n;x++){
        for (int y=1;y<=n;y++){
            if (memo[x][y]!=-1){
                singles[x].push_back(ii(memo[x][y],y));
                ringles[y].push_back(ii(memo[x][y],x));
            }
        }
    }

    for (int x=1;x<=n;x++){
        sort(singles[x].begin(),singles[x].end(),[](ii i,ii j){
            return i.first>j.first;
        });
        sort(ringles[x].begin(),ringles[x].end(),[](ii i,ii j){
            return i.first>j.first;
        });
    }
    int best=0;
    for (int B=1;B<=n;B++){
        for (int C=1;C<=n;C++){
            if (memo[B][C]==-1) continue;
            for (int x=0;x<3;x++){
                if (singles[C].size()==x) break;
                if (singles[C][x].second==B) continue;
                for (int y=0;y<3;y++){
                    if (ringles[B].size()==y) break;
                    if (ringles[B][y].second==C || ringles[B][y].second==singles[C][x].second) continue;
                    if (best<memo[B][C]+ringles[B][y].first+singles[C][x].first){
                        best=memo[B][C]+ringles[B][y].first+singles[C][x].first;
                        a=ringles[B][y].second;
                        b=B;
                        c=C;
                        d=singles[C][x].second;
                    }
                }
            }
        }
    }

    printf("%d %d %d %d\n",a,b,c,d);
}