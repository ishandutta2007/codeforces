#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int M = 1e6;
struct node {
    int son[26];
    int fail, len;
    int fa;
    void clear() {
        for (int i = 0; i < 26; i++)
            son[i] = 0;
        fail = len = 0;
        fa = 0;
    }
} tri[M];

char S[M], T[M];
int lst, L, N, len;
int now_lst[M];
int k;
void pre() {
    S[0] = -1;
    tri[1].clear();
    tri[0].clear();
    tri[1].len = -1;
    tri[0].fail = 1;
    lst = 0;
    L = 1;
}

int getfail(int x) {
    while (S[N] != S[N - tri[x].len - 1])x = tri[x].fail;
    return x;
}

bool add() {
    static int y;
    y = getfail(lst);
    if (tri[y].len + 2 >= k) return 0;
    if (!tri[y].son[S[N] - 'a']) {
        tri[++L].clear();
        tri[L].fail = tri[getfail(tri[y].fail)].son[S[N] - 'a'], tri[L].len = tri[y].len + 2;
        tri[y].son[S[N] - 'a'] = L;
        tri[L].fa = y;
    }
    lst = tri[y].son[S[N] - 'a'];
    return 1;
}
bool dfs(int x, bool sig) {
    if (x == len + 1) {
        return !sig;
    }
    for (int i = 'a'; i <= 'z'; i ++) {
        if (sig && i < T[x]) continue;
        lst = now_lst[x - 1];
        S[x] = i;
        N = x;
        int tmp = L;
        if (add()) {
            now_lst[x] = lst;
            if (dfs(x+1, sig && i == T[x])) return 1;
            if (tmp != L)
                L --, tri[tri[tmp].fa].son[i - 'a'] = 0;
        }
    }
    return 0;
}
int main() {
    scanf("%d", &k);
    pre();
    scanf("%s", T + 1);
    now_lst[0] = 0;
    len = strlen(T + 1);
    if (dfs(1, 1))  {
        printf("%s", S + 1);
    } else {
        puts("Impossible");
    }
    return 0;
}