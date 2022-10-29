#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int SAM_SONN = 26 ;
const int SAM_N = 2e6 + 10;
struct node {
    int son[SAM_SONN];
    int len, fail, sum;
    int bz;
    void clear() {
        memset(son, 0, sizeof(son));
        len = fail = 0;
    }
} tri[SAM_N];
int lst, L;
void init() {
    while (L) tri[L--].clear();
    lst = L = 1;
}
int add(int last, int c) {
    static int v, u, up, up1;
    v = ++L;
    u = last;
    tri[v].len = tri[u].len + 1;
    for (; u && !tri[u].son[c]; u = tri[u].fail)tri[u].son[c] = v;
    if (!u)tri[v].fail = 1;
    else {
        up = tri[u].son[c];
        if (tri[up].len == tri[u].len + 1)tri[v].fail = up;
        else {
            up1 = ++L;
            tri[up1] = tri[up];
            tri[up1].len = tri[u].len + 1;
            tri[up1].sum = 0;
            tri[up].fail = tri[v].fail = up1;
            for (; u && tri[u].son[c] == up; u = tri[u].fail)tri[u].son[c] = up1;
        }
    }
    return lst = v;
}

vector<int> d;
int tmp[SAM_N];
void gettp() {//fail1d[d.size()-1]=1
    int mxlen = 0;
    for (int i = 1; i <= L; i ++) mxlen = max(tri[i].len, mxlen);
    for (int i = 0; i <= mxlen; i ++) tmp[i] = 0;
    d.resize(L);
    for (int i = 1; i <= L; i ++) tmp[tri[i].len] ++;
    for (int i = mxlen - 1; i >= 0; i --) tmp[i] += tmp[i + 1];
    for (int i = 1; i <= L; i ++)
        d[--tmp[tri[i].len]] = i;
}
const int N = 1e6 + 10;
char s[N];
int main() {
    scanf("%s", s) ;
    int n = strlen(s);
    init();
    for (int i = 0; i < n; i ++)
        tri[add(lst, s[i] - 'a')].sum ++;
    gettp();
    for (int i = 0; i < L - 1; i ++)
        tri[tri[d[i]].fail].sum += tri[d[i]].sum;
    int T;
    scanf("%d", &T);
    int tag = 0;
    while (T --) {
        scanf("%s", s);
        int n = strlen(s);
        ++tag;
        int len = 0;
        int x = 1;
        int ans = 0;
        for (int i = 0; i < n + n; i ++) {
            char c = s[i % n] - 'a';
            while (x != 1 && !tri[x].son[c]) {
                x = tri[x].fail;
                len = tri[x].len;
            }
            if (!tri[x].son[c]) {
                continue;
            }
            x = tri[x].son[c];
            len ++;
            while (tri[tri[x].fail].len >= n) {
                x = tri[x].fail;
                len = tri[x].len;
            }
            if (len >= n && tri[x].bz != tag){
                tri[x].bz = tag;
                ans += tri[x].sum;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}