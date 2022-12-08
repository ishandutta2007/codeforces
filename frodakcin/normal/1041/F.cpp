#include <iostream>
#include <cstdio>

#include <map>
#include <utility>

using namespace std;

#define mp make_pair

typedef map<int, int> mii;

const int MAXN = 200000 + 10;
const int MAXM = 200000 + 10;
const int MAXX = 1e9 + 10;

int N, M, t;

int a[MAXN], b[MAXN];

int ins(int v, mii& m) {
    if(m.find(v) == m.end()){
        m.insert(mp(v, 1));
        return 1;
    }
    return (++m[v]);
}

int count(int L) {
    mii ct;
    
    int ret = 0;
    for(int i = 0;i < N;i++) if((t = ins(a[i]%(2 * L), ct)) > ret) ret = t;
    for(int i = 0;i < M;i++) if((t = ins((b[i] + L)%(2 * L), ct)) > ret) ret = t;
    return ret;
}

int c0() {
    mii ct;
    
    int ret = 0;
    for(int i = 0;i < N;i++) if((t = ins(a[i], ct)) > ret) ret = t;
    for(int i = 0;i < M;i++) if((t = ins(b[i], ct)) > ret) ret = t;
    return ret;
}

int main() {
    scanf("%d%d", &N, &t);
    for(int i = 0;i < N;i++) scanf("%d", a + i);
    scanf("%d%d", &M, &t);
    for(int i = 0;i < M;i++) scanf("%d", b + i);
    
    int ans = c0();
    
    for(int i = 1;i < MAXX;i <<= 1) if((t = count(i)) > ans) ans = t;
    
    printf("%d\n", ans);
    
    return 0;
}