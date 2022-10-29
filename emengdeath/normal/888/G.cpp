#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
struct node{
    int son[2];
    int v;
}tri[N * 41];
int a[N];
int tot = 1;
int n;
long long ans;
void ins(int x, int v) {
    int s = 1;
    for (int i = 29; i >= 0; i --) {
        bool sig = ((x >> i) & 1);
        tri[s].v += v;
        if (!tri[s].son[sig])
            tri[s].son[sig] = ++tot;
        s = tri[s].son[sig];
    }
    tri[s].v += v;
}
int get(int x) {
    int v = 0, s= 1;
    for (int i = 29; i >= 0; i --) {
        bool sig = ((x >> i) & 1);
        if (tri[tri[s].son[sig]].v)
            s = tri[s].son[sig];
        else
            v |= (1 << i), s = tri[s].son[sig ^ 1];
    }
    return v;
}
void work(int l, int r, int sig) {
    if (sig < 0 || l >= r) return;
    if (((a[l] >> sig) & 1) == ((a[r] >> sig) & 1)) {
        work(l, r, sig - 1);
        return;
    }
    int mid = l;
    while (!((a[mid + 1] >> sig) & 1)) mid ++;
    for (int i= l ; i<= r; i ++)
        if (i <= mid)
            ins(a[i], -1);
    int v = 2e9;
    for (int i = l; i <= mid; i ++)
        v = min(v, get(a[i]));
    ans += v;
    work(mid + 1, r, sig - 1);
    for (int i= l ; i<= r; i ++)
        if (i <= mid) {
            ins(a[i], 1);
        } else {
            ins(a[i], -1);
        }
    work(l, mid, sig - 1);
    for (int i= l ; i<= r; i ++)
        if (i > mid)
            ins(a[i], 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int tmp = n;
    n = 1;
    ins(a[1], 1);
    for (int i = 1; i <= tmp; i ++)
        if (a[n] != a[i])
            a[++n] = a[i], ins(a[n], 1);
    work(1, n, 29);
    printf("%lld\n", ans);
    return 0;
}