#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 1111;

int n, p, inDeg[N], out[N], diameter[N];

int main(){
    scanf("%d%d", &n, &p);
    memset(inDeg, 0, sizeof(inDeg));
    memset(out, 0, sizeof(out));
    while(p --){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        inDeg[v] += 1;
        out[u] = v;
        diameter[u] = w;
    }
    int result = 0;
    for(int i = 1; i <= n; ++ i){
        result += inDeg[i] == 0 and out[i];
    }
    printf("%d\n", result);
    for(int i = 1; i <= n; ++ i){
        if(inDeg[i] == 0 and out[i]){
            int limit = INT_MAX;
            int j = i;
            while(out[j]){
                limit = min(limit, diameter[j]);
                j = out[j];
            }
            printf("%d %d %d\n", i, j, limit);
        }
    }
    return 0;
}