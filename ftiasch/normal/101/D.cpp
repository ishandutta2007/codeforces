// Codeforces Beta Round #79
// Problem D -- Castle
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 222222;

int n, edgeCnt, firstEdge[N], to[N], length[N], nextEdge[N], nodeCnt[N], lengthSum[N];
long long f[N];

bool compare(int u, int v){
    return (long long)lengthSum[u] * nodeCnt[v] < (long long)lengthSum[v] * nodeCnt[u];
}

void dfs(int p, int u){
    vector<int> childs;
    f[u] = 0;
    nodeCnt[u] = 1;
    lengthSum[u] = 0;
    for(int iter = firstEdge[u]; iter != -1; iter = nextEdge[iter]){
        int v = to[iter];
        if(v != p){
            dfs(u, v);
            nodeCnt[u] += nodeCnt[v];
            lengthSum[v] += 2 * length[iter];
            lengthSum[u] += lengthSum[v];
            f[u] += (long long)length[iter] * nodeCnt[v] + f[v];
            childs.push_back(v);
        }
    }
    sort(childs.begin(), childs.end(), compare);
    long long nodeCntSum = 0;
    for(vector<int>::reverse_iterator iter = childs.rbegin(); iter != childs.rend(); ++ iter){
        f[u] += nodeCntSum * lengthSum[*iter];
        nodeCntSum += nodeCnt[*iter];
    }
}

void addEdge(int u, int v, int w){
    to[edgeCnt] = v;
    length[edgeCnt] = w;
    nextEdge[edgeCnt] = firstEdge[u];
    firstEdge[u] = edgeCnt ++;
}

int main(){
    scanf("%d", &n);
    edgeCnt = 0;
    memset(firstEdge, -1, sizeof(firstEdge));
    for(int i = 1; i < n; ++ i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    dfs(0, 1);
    //for(int i = 1; i <= n; ++ i){
    //    printf("-- %d: %d\n", i, lengthSum[i]);
    //}
    printf("%.8f\n", (double)f[1] / (n - 1));
    return 0;
}