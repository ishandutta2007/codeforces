// Yandex Algorithm 2011 Round 1
// Problem C -- Petya and Tree
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 111111;

int n, m, root, parent[N], key[N], child[N][2], minimum[N], maximum[N], rangeCnt, begin[N], end[N], cnt[N];
long long sum[N];

void preCal(int x){
    if(child[x][0] and child[x][1]){
        preCal(child[x][0]);
        preCal(child[x][1]);
        minimum[x] = minimum[child[x][0]];
        maximum[x] = maximum[child[x][1]];
    }else{
        minimum[x] = key[x];
        maximum[x] = key[x];
    }
}

void dfs(int x, int a, int b, int d, long long s){
    if(child[x][0] and child[x][1]){
        dfs(child[x][0], a, key[x] - 1, d + 1, s + minimum[child[x][1]]);
        dfs(child[x][1], key[x] + 1, b, d + 1, s + maximum[child[x][0]]);
    }else{
        begin[rangeCnt] = a;
        end[rangeCnt] = b;
        cnt[rangeCnt] = d;
        sum[rangeCnt ++] = s;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", parent + i, key + i);
    }
    memset(child, 0, sizeof(child));
    for(int i = 1; i <= n; ++ i){
        if(parent[i] == -1){
            root = i;
        }else{
            child[parent[i]][key[parent[i]] < key[i]] = i;
        }
    }
    preCal(root);
    rangeCnt = 0;
    dfs(root, INT_MIN, INT_MAX, 0, 0);
    //for(int i = 0; i < rangeCnt; ++ i){
    //    printf("[%d, %d] %d %lld\n", begin[i], end[i], cnt[i], sum[i]);
    //}
    scanf("%d", &m);
    while(m --){
        int x;
        scanf("%d", &x);
        int lower = 0;
        int upper = rangeCnt - 1;
        while(lower < upper){
            int mider = (lower + upper + 1) >> 1;
            if(begin[mider] <= x){
                lower = mider;
            }else{
                upper = mider - 1;
            }
        }
        printf("%.10f\n", (double)sum[lower] / cnt[lower]);
    }
    return 0;
}