
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 3e5 + 10;

struct Trie {
    static const int L = 31;
    static const int M = L * 3e5 + 10, S = 2;
    int root, sz;
    int nxt[M][S], have[M];
    int newNode() {
        have[sz] = 0;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        root = newNode();
    }
    void update(int x, int d) {
        int u = root;
        for(int i = L; ~i; --i) {
            int c = x >> i & 1, &v = nxt[u][c];
            if(v == -1) v = newNode();
            have[v] += d;
            u = v;
        }
    }
    int query(int x) {
        int u = root, ret = 0;
        for(int i = L; ~i; --i) {
            int c = x >> i & 1;
            if(have[nxt[u][c]]) {
                ret |= c << i;
                // printf("%d=%d\n", i, c);
                u = nxt[u][c];
            } else {
                ret |= (c ^ 1) << i;
                // printf("%d=%d\n", i, c ^ 1);
                u = nxt[u][c ^ 1];
            }
        }
        return ret;
    }
} trie;

int a[N], b[N];

int main() {

    int n; 
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        trie.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", b + i);
            trie.update(b[i], 1);
        }
        for(int i = 1; i <= n; ++i) {
            int ret = trie.query(a[i]);
            // printf("ret=%d\n", ret);
            printf("%d%c", a[i] ^ ret, " \n"[i == n]);
            trie.update(ret, -1);
        }
    }
}