#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int m, n;
vector<int> adj[100005];
bool added[100005];
int addedN=0;
set<pair<int, int> > used;
int usedTimes[100005];
bool tested[3000000];

bool rec(int left, int index, int N){
    int a=0, b=0;
    for(int i=0; i < N; ++i)
        for(int j=i+1; j < N; ++j){
            if(used.find(make_pair(i, j)) != used.end())
                b |= (1<<a);
            ++a;
        }
    if(tested[b])
        return false;
    tested[b]=1;
    if(left == 0){
        return true;
    }
    for(int i=0; i < N; ++i)
        for(int j=i+1; j < N; ++j){
            bool ok=1;
            for(int k=0; k < adj[i].size(); ++k){
                if(adj[i][k] == j)
                    ok=0;
            }
            if(!ok)
                continue;
            if(used.find(make_pair(i, j)) != used.end())
                continue;
            if(usedTimes[i] >= 2)
                continue;
            if(usedTimes[j] >= 2)
                continue;
            used.insert(make_pair(i, j));       
            ++usedTimes[i];
            ++usedTimes[j];
            bool r=rec(left-1, index+1, N);
            if(r)
                return true;
            --usedTimes[i];
            --usedTimes[j];
            used.erase(make_pair(i, j));
        }
    return false;
}

bool bruteforce(int N, int M){
    for(int i=0; i < N; ++i)
        usedTimes[i]=0;
    for(int i=0; i < 3000000; ++i)
        tested[i]=0;
    bool success=rec(M, 0, N);
    if(!success){
        printf("-1");
        return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i < m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n <= 5){
        if(!bruteforce(n, m))
            return 0;
        for(set<pair<int, int> >::iterator it = used.begin(); it != used.end(); ++it){
            printf("%d %d\n", it->first+1, it->second+1);
        }
        return 0;
    }
    if(!bruteforce(6, 6))
        return 0;
    for(int i=6; i < n; ++i){
        for(set<pair<int, int> >::iterator it = used.begin(); it != used.end(); ++it){
            bool ok=1;
            for(int j=0; j < adj[i].size(); ++j){
                if(adj[i][j] == it->first || adj[i][j] == it->second)
                    ok=0;
            }
            if(ok){
                int a=it->first, b=it->second;
                used.erase(it);
                used.insert(make_pair(a, i));
                used.insert(make_pair(i, b));
                break;
            }
        }
    }
    for(set<pair<int, int> >::iterator it = used.begin(); m--; ++it){
        printf("%d %d\n", it->first+1, it->second+1);
    }
    return 0;
}