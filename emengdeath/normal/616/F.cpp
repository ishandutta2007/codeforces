#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e6;
struct node{
    int son[26], fail, len;
    vector<int>g;
    long long v;
    void clear(){
        for (int i = 0; i < 26; i ++) son[i] = 0;
        fail = len = v = 0;
    }
}tri[N];
int L, n;
int d[N];
long long ans =0;
int add(int last,int c){
    static int v,u,up,up1;
    v = tri[last].son[c];
    if (v)
    {
        u = last;
        if (tri[v].len != tri[u].len + 1)  {
            up = ++L;
            tri[up] = tri[v];
            tri[up].len = tri[u].len + 1;
            tri[up].fail = tri[v].fail;
            tri[v].fail = up;
            for (;u && tri[u].son[c] == v; u = tri[u].fail) tri[u].son[c] = up;
            v = up;
        }
    } else {
        v = ++L;
        tri[v].clear();
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
                tri[up].fail = tri[v].fail = up1;
                for (; u && tri[u].son[c] == up; u = tri[u].fail)tri[u].son[c] = up1;
            }
        }
    }
    return v;
}
char s[N];
vector<int>g[N];
void dfs(int x) {
    for (auto u:tri[x].g)
    {
        dfs(u);
        tri[x].v += tri[u].v;
    }
    ans = max(ans, tri[x].v * tri[x].len);
}
int main() {
    scanf("%d", &n);
    L = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s);
        int len = strlen(s);
        int x = 1;
        for (int j = 0; j < len; j ++)
        {
            x = add(x, s[j] - 'a');
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        int x;
        scanf("%d", &x);
        for (auto u:g[i])
            tri[u].v += x;
    }
    for (int i = 1; i <= L; i ++)
        tri[tri[i].fail].g.push_back(i);
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}