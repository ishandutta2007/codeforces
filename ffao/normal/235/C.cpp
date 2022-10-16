#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define mp make_pair

using namespace std;

struct SAState {
    int len, link, next[30];
    bool end, is_clon;
    vector<int> inv_link;
};

class SuffixAutomaton {
public:
    static const int MAXLEN = 1000010;
    SAState st[MAXLEN*2];
    int sz, last, len;

    SuffixAutomaton() {
        clear();
    }

    void clear() {
        sz = last = 0;
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        ++sz;
    }

    void extend(int c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        
        int p;
        for (p = last; p != -1 && st[p].next[c] == -1; p = st[p].link) {
            st[p].next[c] = cur;
        }

        if (p == -1) 
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) 
                st[cur].link = q;
            else {
                int clone = sz++;
                st[clone].is_clon = true;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                for (; p != -1 && st[p].next[c] == q; p = st[p].link) 
                    st[p].next[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;
    }

    void postprocess() {
        for (int v = 1; v < sz; v++)
            st[st[v].link].inv_link.push_back(v);
        for (int p = last; p != -1; p = st[p].link)
            st[p].end = true;
    }
};

char p[1100000];
int m;
int pos[2100000];
void func(){ int i, j=-1; pos[0]=-1; for( i=1 ; i<m ; i++ ){ while( j>=0 && p[j+1]!=p[i] ) j=pos[j]; if( p[j+1]==p[i] ) j++; pos[i]=j; } }

SuffixAutomaton sa;
int n, ans;

int pd[2100000];
int count(int v) {
    int& ret = pd[v];
    if (ret == 0) {
        if (!sa.st[v].is_clon) ret++;
        for (int link: sa.st[v].inv_link) ret += count(link);
    }
    return ret; 
}

int cur, used;

void add(int c) {
    while (cur != 0 && sa.st[cur].next[c] == -1) {
        cur = sa.st[cur].link;
        used = sa.st[cur].len;
    }

    if (sa.st[cur].next[ c ] != -1) {
        used++;
        cur = sa.st[cur].next[c];
    }

    while (cur != 0 && sa.st[ sa.st[cur].link ].len >= m) {
        cur = sa.st[cur].link;
    }

    if (used >= m) ans += count(cur);
}

void solve() {
    ans = 0;
    m = strlen(p);
    func();

    int period = (m-1) - pos[m-1];
    if (m % period != 0) period = m;

    cur = 0, used = 0;
    for (int i = 0; i < m; i++) {
        add(p[i]-'a');
    }

    for (int i = 1; i < period; i++) {
        add(p[i-1]-'a');
    }

    printf("%d\n", ans);
} 

int main() {
    scanf("%s", p);

    for (int i = 0; p[i] != '\0'; i++) sa.extend(p[i]-'a');
    sa.postprocess();
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", p);
        solve();
    }
}