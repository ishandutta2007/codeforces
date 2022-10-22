#include <bits/stdc++.h>
using namespace std;
#define Rep(i, l, r) for(int i = l ; i <= r ; i ++)
#define Lep(i, r, l) for(int i = r ; i >= l ; i --)

inline int read() {
    int x = 0, flag = 1;
    char ch = getchar();
    for( ; ch > '9' || ch < '0' ; ch = getchar()) if(ch == '-') flag = -1;
    for( ; ch >= '0' && ch <= '9' ; ch = getchar()) x = x * 10 + ch - '0';
    return x * flag;
}
const int MAXN = 2e5 + 50;
typedef long long LL;
int n, val[MAXN], tim[MAXN], siz[MAXN],zz[MAXN];
int rt[MAXN], pos[MAXN], cnt = 0, m;
LL Ans[MAXN], TSUM;
vector <int> E[MAXN];
vector<int> lyj[MAXN];
struct SegmentTree1 {
    int ls, rs, siz; LL tsum;
} T[MAXN * 62];
struct Qs { 
    int tim, id; 
    bool operator <(const Qs& f) const { return tim < f.tim; }
} ;
vector <Qs> Q[MAXN];
bool cmp(int a, int b) { return tim[a] < tim[b]; }
void erase(int x) { T[x].ls = T[x].rs = T[x].siz = T[x].tsum = 0; }
int Get(int x, int P, int l, int r, int w, LL Sz, LL tsum) { //  t[x]
    if(l == r) return l - 1e8;
    int mid = (l + r) >> 1; LL SumL = mid - 1e8, sz = 0, t = 0;  // 1e8 
    for(int i = 0 ; i <= P ; i ++) {
        int u = pos[E[x][i]], ls = T[u].ls, p = mid - 1e8;
        if(mid - 1e8 < tim[E[x][i]]) continue;
        SumL += 1ll * p * T[ls].siz - T[ls].tsum;
        sz += T[ls].siz, t += T[ls].tsum;
    } SumL -= tsum, SumL += 1ll * (mid - 1e8) * Sz;
    if(SumL >= w) {
        Rep(i, 0, P) pos[E[x][i]] = T[pos[E[x][i]]].ls;
        return Get(x, P, l, mid, w, Sz, tsum);
    }
    Rep(i, 0, P) pos[E[x][i]] = T[pos[E[x][i]]].rs;
    return Get(x, P, mid + 1, r, w, sz + Sz, tsum + t);
}
int merge(int x, int y) { // 
    if(!x || !y) return x | y;
    int cur = ++ cnt;
    T[cur].siz = T[x].siz + T[y].siz;
    T[cur].tsum = T[x].tsum + T[y].tsum;
    T[cur].ls = merge(T[x].ls, T[y].ls);
    T[cur].rs = merge(T[x].rs, T[y].rs);
    erase(x), erase(y); return cur;
}
void insert(int &x, int l, int r, int pos, int a, LL b) { // 
    if(!x) x = ++ cnt; int mid = (l + r) >> 1;
    T[x].siz += a, T[x].tsum += b;
    if(l == r) return ;
    if(pos + 1e8 <= mid) insert(T[x].ls, l, mid, pos, a, b);
    else insert(T[x].rs, mid + 1, r, pos, a, b);
    T[x].siz = T[T[x].ls].siz + T[T[x].rs].siz;
    T[x].tsum = T[T[x].ls].tsum + T[T[x].rs].tsum;
    return ;
}
int Cover(int &x, int l, int r, int pos) { // 0
    int cur = x, Sz = 0;
    if(l == r) { TSUM += T[x].tsum, Sz = T[cur].siz, erase(x), x = 0; return Sz; }
    int mid = (l + r) >> 1;
    if(pos + 1e8 <= mid) Sz = Cover(T[x].ls, l, mid, pos);
    else {
        Sz += T[T[x].ls].siz, TSUM += T[T[x].ls].tsum,
        erase(T[x].ls), T[x].ls = 0, 
        Sz += Cover(T[x].rs, mid + 1, r, pos);
    }
    T[x].siz = T[T[x].ls].siz + T[T[x].rs].siz;
    T[x].tsum = T[T[x].ls].tsum + T[T[x].rs].tsum;
    return Sz;
}
LL Find(int x, int l, int r, int pos) {
    if(!x) return 0;
    if(l == r) return 1ll * pos * T[x].siz - T[x].tsum;
    int mid = (l + r) >> 1;
    if(pos + 1e8 <= mid) return Find(T[x].ls, l, mid, pos);
    return Find(T[x].rs, mid + 1, r, pos) +  1ll * pos * T[T[x].ls].siz - T[T[x].ls].tsum;
}
void dfs1(int x) {
    int Siz = E[x].size() - 1, now = 0;
    Rep(i, 0, Siz) {
        dfs1(E[x][i]);
        pos[E[x][i]] = rt[E[x][i]]; TSUM = 0;
        int fs = Cover(rt[E[x][i]], 0, 2e8, tim[E[x][i]] - 1);
        insert(rt[E[x][i]], 0, 2e8, tim[E[x][i]], fs, TSUM);
    }
    tim[x] = Get(x, Siz, 0, 2e8, -val[x], 0, 0);
    sort(E[x].begin(), E[x].end(), cmp);

    while(now != Q[x].size()) {
        int Tim = Q[x][now].tim, Id = Q[x][now].id;
        if(E[x].size() == 0) { Ans[Id] = val[x] + Tim; now ++; continue; }
        if(Tim < tim[E[x][0]]) { Ans[Id] = val[x] + Tim; now ++; continue; }
        break;
    }

    Rep(i, 0, Siz) {
        rt[x] = merge(rt[x], rt[E[x][i]]);
        if(now == Q[x].size()) continue;
        int Tim = Q[x][now].tim, Id = Q[x][now].id, f;
        while(Tim >= tim[E[x][i]] && now < Q[x].size()) {
            if(i != Siz) if(Tim >= tim[E[x][i + 1]]) break;
            Ans[Id] = Find(rt[x], 0, 2e8, Tim) + Tim + val[x];
            now ++; if(now == Q[x].size()) break;
            Tim = Q[x][now].tim, Id = Q[x][now].id;
        }
    }
    insert(rt[x], 0, 2e8, tim[x], 1, -val[x]);
    return ;
}
inline void Write(LL x, char c) {
    LL Putout[35], Numbercnt = 0;
    if(x < 0) putchar('-'), x = -x;
    if(!x) { putchar('0'), putchar(c); return ; }
    while(x) Putout[++ Numbercnt] = x % 10, x /= 10;
    for(int i = Numbercnt ; i >= 1 ; i --) putchar(Putout[i] + '0');
    if(Numbercnt == 0) putchar('0'); putchar(c);
    return ;
}
void pd(int u,int f)
{
	for(auto v:lyj[u])
	{
		if(v==f)
			continue;
		E[u].push_back(v);
		val[u]++;
		pd(v,u);
	}
}
int main() {
    n = read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		lyj[u].push_back(v);
		lyj[v].push_back(u);
	}
	pd(1,0);
	m = read();

    Rep(i, 1, m)  {
        int u = read(), x = read();
		zz[i]=x;
		x=-x-1;
        Q[u].push_back((Qs) { x, i } );
    } 
    Rep(i, 1, n) sort(Q[i].begin(), Q[i].end()); dfs1(1);
    Rep(i, 1, m) Write(Ans[i]+zz[i]+1, ' '), putchar('\n');
    return 0;
}