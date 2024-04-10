#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

typedef long long lld;
#define mem(a,b) memset(a, b, sizeof(a))

using namespace std;

const int N = 1000100;

inline void checkmin(int &a, int b) {
    if(a > b) a = b;
}

struct Satate {
    int pre, go[26];
    int up, down, right;
    void Clear() {
        mem(go, 0xff);
        pre = up = down = right = -1;
    }
}   pool[N<<1];

int root, last;
int tpcnt[N<<1], tpseq[N<<1];
int ept;

void init() {
    ept = 1;
    root = 0;
    last = 0;
    pool[0].Clear();
    pool[root].up = 0;
}

void extend(int w) {
    int p = last, np = ept ++ ;
    pool[np].Clear();
    pool[np].up = pool[p].up + 1;
    for(; p != -1 && pool[p].go[w] == -1; p = pool[p].pre) {
        pool[p].go[w] = np;
    }
    if(p == -1) {
        pool[np].pre = root;
    } else {
        int q = pool[p].go[w];
        if(pool[p].up + 1 == pool[q].up) {
            pool[np].pre = q;
        } else {
            int nq = ept ++;
            pool[nq] = pool[q];
            pool[nq].up = pool[p].up + 1;
            pool[q].pre = nq;
            pool[np].pre = nq;
            for(; p != -1 && pool[p].go[w] == q; p = pool[p].pre) {
                pool[p].go[w] = nq;
            }
        }
    }
    last = np;
}

void topo(char * ch, int len) {
    mem(tpcnt, 0);
    for(int i=0; i<ept; i++) tpcnt[pool[i].up] ++;
    for(int i=1; i<=len; i++) tpcnt[i] += tpcnt[i-1];
    for(int i=0; i<ept; i++) tpseq[--tpcnt[pool[i].up]] = i;
    for(int i=0; i<ept; i++) pool[i].down = pool[i].up, pool[i].right = 0;
    for(int i=0; i<ept; i++)
        for(int j=0; j<26; j++) {
            if(pool[tpseq[i]].go[j] != -1)
                checkmin(pool[pool[tpseq[i]].go[j]].down,
                         pool[tpseq[i]].down + 1);
        }
    for(int i=0, p=0; i<len; i++)
        p = pool[p].go[ch[i]-'a'], pool[p].right ++;
    for(int i=ept-1; i>0; --i) {
        pool[pool[tpseq[i]].pre].right += pool[tpseq[i]].right;
    }
}

void print(int i){
    printf("node %d: up=%d down=%d right=%d fail=%d\n", i, pool[i].up, pool[i].down, pool[i].right, pool[i].pre);
    for(int j=0; j<26; ++j){
        if(pool[i].go[j] != -1){
            printf("%c->%d\n", j+'a', pool[i].go[j]);
            
        }
    }
}
char str[N];
char ss[N<<1];
int f[N];
int len[N<<1] = {};
int vis[N<<1] = {0};
int main()
{
    scanf("%s", str);
    init();
    for(int i=0; str[i]; i++)
        extend(str[i]-'a');
    topo(str, strlen(str));
    int n;
    scanf("%d", &n);
    for(int t=1; t<=n; t++) {
        scanf("%s", ss);
        int ls = strlen(ss);
        for(int i=0; i<ls; ++i) ss[i+ls] = ss[i];
        lld ans = 0;
        int p = root, tlen = 0;
        for(int i=0; i<ls; ++i){
            while(tlen < i+ls){
                if(pool[p].go[ss[tlen]-'a'] == -1) break;
                p = pool[p].go[ss[tlen]-'a'];
                tlen ++;
            }
            if(vis[p] != t && tlen == i+ls){
                 ans += pool[p].right;
                 vis[p] = t;
        }
            if(p != root && tlen - i == pool[p].down){
                p = pool[p].pre;
            }
        }        
        printf("%I64d\n", ans);
    }
    
    //system("pause");
    
    return 0;
}