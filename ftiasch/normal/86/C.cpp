// Yandex Algorithm 1011 Round 1
// Problem C -- Genetic engineering
#include <cstdio>
#include <cstring>

const int MOD = 1000000009;
const char genetic[4] = {'A', 'C', 'G', 'T'};

int n, m, nodeCnt, depth[111], childs[111][4], fail[111], transform[111][4], queue[111], dp[1111][111][11];
bool terminated[111];

int charToInt(char c){
    for (int i = 0; i < 4; ++ i) {
        if (c == genetic[i]) {
            return i;
        }
    }
    return -1;
}

void update(int &x, int a){
    x = (x + a) % MOD;
}

int main() {
    scanf("%d%d", &n, &m);
    nodeCnt = 1;
    memset(childs, 0, sizeof(childs));
    memset(terminated, 0, sizeof(terminated));
    for (int i = 0; i < m; ++ i) {
        char str[11];
        scanf("%s", str);
        int len = strlen(str), cur = 0;
        for (int j = 0; j < len; ++ j) {
            depth[cur] = j;
            int c = charToInt(str[j]); 
            if (not childs[cur][c]) {
                childs[cur][c] = nodeCnt ++;
            }         
            cur = childs[cur][c];
        }
        depth[cur] = len;
        terminated[cur] = true;
    }
    int head = 0, tail = 0;
    for (int c = 0; c < 4; ++ c) {
        transform[0][c] = childs[0][c];
        if (childs[0][c]) {
            fail[childs[0][c]] = 0;
            queue[tail ++] = childs[0][c];
        }
    }
    while (head != tail) {
        int cur = queue[head ++]; 
        if (terminated[fail[cur]] and not terminated[cur]) {
            terminated[cur] = true;
            depth[cur] = depth[fail[cur]];
        }
        for (int c = 0; c < 4; ++ c) {
            if (childs[cur][c]) {
                transform[cur][c] = childs[cur][c];
                fail[childs[cur][c]] = transform[fail[cur]][c];            
                queue[tail ++] = childs[cur][c];
            } else {
                transform[cur][c] = transform[fail[cur]][c];
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1; 
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < nodeCnt; ++ j) {
            for (int k = 0; k < 11; ++ k) {
                if (dp[i][j][k]) {
                    for (int c = 0; c < 4; ++ c) {
                        int next = transform[j][c], ex = k + 1;
                        if (terminated[next]) {
                            if (k < depth[next]) {
                                ex = 0; 
                            }
                        }
                        if(ex >= 11){
                            continue;
                        }
                        update(dp[i + 1][next][ex], dp[i][j][k]);
                    }
                }
            }
        }
    }
    //for(int i = 0; i <= n; ++ i){
    //    printf("step %d\n", i);
    //    for(int j = 0; j < nodeCnt; ++ j){
    //        printf("node %d: ", j);
    //        for(int k = 0; k < 11; ++ k){
    //            printf("%d ", dp[i][j][k]);
    //        }
    //        printf("\n");
    //    }
    //}
    int result = 0;
    for (int j = 0; j < nodeCnt; ++ j) {
        update(result, dp[n][j][0]);
    }
    printf("%d\n", result);
    return 0;
}