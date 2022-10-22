#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int m, n, d;
bool haunted[100005];
int maxDis[100005];

vector<int> adj[100005];
vector<int> dis[100005];
vector<int> done[100005];
vector<int> oInd[100005];

int left[100005];
queue<int> q;

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for(int i=0; i < n; ++i){
        maxDis[i]=0;
        haunted[i]=0;
        left[i]=0;
    }
    for(int i=0; i < m; ++i){
        int x;
        scanf("%d", &x);
        haunted[x-1]=1;
    }
    for(int i=0; i < n-1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        oInd[a].push_back(adj[b].size());
        oInd[b].push_back(adj[a].size());
        adj[a].push_back(b);
        adj[b].push_back(a);
        dis[a].push_back(-1000000);
        dis[b].push_back(-1000000);
        done[a].push_back(0);
        done[b].push_back(0);
        ++left[a];
        ++left[b];
    }
    for(int i=0; i < n; ++i)
        if(left[i] <= 1)
            q.push(i);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        int a1=-1000000, a2=-1000000;
        for(int i=0; i < dis[f].size(); ++i){
            if(dis[f][i] > maxDis[f])
                maxDis[f]=dis[f][i];
            if(dis[f][i] < a2)
                continue;
            if(dis[f][i] < a1)
                a2=dis[f][i];
            else{
                a2=a1;
                a1=dis[f][i];
            }
        }
        if(haunted[f]){
            if(0 >= a2){
                if(0 < a1)
                    a2=0;
                else{
                    a2=a1;
                    a1=0;
                }
            }
        }
        for(int i=0; i < dis[f].size(); ++i){
            if(left[f] && done[adj[f][i]][oInd[f][i]])
                continue;
            int N;
            if(dis[f][i] == a1)
                N=a2;
            else
                N=a1;
            if(N+1 > dis[adj[f][i]][oInd[f][i]])
                dis[adj[f][i]][oInd[f][i]]=N+1;
            if(!done[f][i]){
                --left[adj[f][i]];
                if(left[adj[f][i]] <= 1)
                    q.push(adj[f][i]);
            }
            done[f][i]=1;
        }
    }
    int ans=0;
    for(int i=0; i < n; ++i)
        if(maxDis[i] <= d)
            ++ans;
    printf("%d", ans);
    return 0;
}