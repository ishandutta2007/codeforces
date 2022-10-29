#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
using  namespace std;
const int N = 2e6 + 10;
struct node{//0
    int son[26];
    int id, fail;
}tri[N];
int d[N];
int L;
unordered_set<int> h[N];
void ins(int s,char*s1,int l, int v,int len){
    static int ss;
    while (l != len) {
        if (!tri[s].son[ss=s1[l]-'a'])
            tri[s].son[ss]=++L;
        s = tri[s].son[ss], l ++;
    }
    tri[s].id = v;
}
void bfs(){
    static int l,r,x;
    l=0,r=1,d[1]=0;
    while (l<r){
        ++l;
        for (int i=0;i<26;i++)
            if (tri[d[l]].son[i]){
                x=tri[d[l]].fail;
                while (!tri[x].son[i]&&x)x=tri[x].fail;
                d[++r]=tri[d[l]].son[i];
                if (tri[x].son[i]!=d[r])
                    tri[d[r]].fail=tri[x].son[i];
            }
    }
}
int n, m, w;
char s[N], s1[N];
int f[N];
bool bz[N];
int main() {
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i < m; i ++)
        s[i + n * m] = s[i];
    scanf("%d" ,&w);
    for (int i = 1; i <= w; i ++)
        scanf("%s", s1), ins(0, s1, 0, i, m);
    bfs();
    int x = 0;
    for (int i = 1; i <= n * m + m - 1; i ++) {
        while (x && !tri[x].son[s[i] - 'a']) x = tri[x].fail;
        if (tri[x].son[s[i] - 'a']) {
            x = tri[x].son[s[i] - 'a'];
        }
        if (tri[x].id) {
            if (h[tri[x].id].find(i % m) != h[tri[x].id].end()) continue;
            f[i] = tri[x].id;
            h[tri[x].id].insert(i % m);
        }
    }
    for (int i = 0; i < m; i ++)
        bz[i] = 1;
    for (int i = m ; i <= n * m+ m - 1; i ++)
        if (bz[i - m] && f[i]){
            bz[i] = 1;
        }
    int last = -1;
    for (int i = n*m; i <= n *m + m -1;i  ++)
        if (bz[i])
            last = i;
    if (last == -1) {
        puts("NO");
        return 0;
    }
    puts("YES");
    vector<int>d;
    while (f[last]) {
        d.push_back(f[last]);
        last -= m;
    }
    reverse(d.begin(), d.end());
    for (auto u:d)
        printf("%d ", u);
    return 0;
}