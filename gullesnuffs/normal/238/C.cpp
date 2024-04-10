#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int cost[3005][2];
int deg[3005], degSaved[3005];

vector<int> to[3005];
vector<int> from[3005];

int main()
{
    scanf("%d", &n);
    for(int i=1; i <= n; ++i)
        degSaved[i]=0;
    for(int i=0; i < n-1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        to[a].push_back(b);
        from[b].push_back(a);
        ++degSaved[a];
        ++degSaved[b];
    }
    queue<int> q;
    int answer=n-1;
    if(n == 2)
        answer=0;
    for(int meet=1; meet <= n; ++meet){
        if(from[meet].size()+to[meet].size() < 2)
            continue;
        for(int i=1; i <= n; ++i){
            deg[i]=degSaved[i];
            if(i == meet)
                deg[i]++;
            if(deg[i] == 1 && i != meet)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node == meet)
                continue;
            int best=-1, bestI=-1;
            int costSum=0;
            bool nextType;
            for(int j=0; j < 2; ++j){
                for(int i=0; i < (j?to[node].size():from[node].size()); ++i){
                    int t=(j?to[node][i]:from[node][i]);
                    if(deg[t] == 1){
                        costSum += cost[t][0];
                        if(cost[t][0]-cost[t][1] > best){
                            best=cost[t][0]-cost[t][1];
                            bestI=t;
                        }
                    }
                    --deg[t];
                    if(deg[t] == 1){
                        q.push(t);
                    }
                    if(deg[t] >= 1)
                        nextType=j;
                }
            }
            cost[node][0]=cost[node][1]=costSum;
            if(best > 0){
                cost[node][1]=costSum-best;
            }
            cost[node][0] += nextType;
            cost[node][1] += 1-nextType;
        }
        vector<int> sub;
        int costSum=0;
        for(int j=0; j < 2; ++j){
            for(int i=0; i < (j?to[meet].size():from[meet].size()); ++i){
                int t=(j?to[meet][i]:from[meet][i]);
                costSum += cost[t][0];
                sub.push_back(cost[t][1]-cost[t][0]);
            }
        }
        sort(sub.begin(), sub.end());
        for(int k=0; k < 2 && k < sub.size() && sub[k] < 0; ++k)
            costSum += sub[k];
        if(costSum < answer)
            answer=costSum;
    }
    printf("%d\n", answer);
    return 0;
}