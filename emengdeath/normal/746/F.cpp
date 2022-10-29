#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int belong[N];
int a[N], t[N];
priority_queue<pair<int, int> > q, p;
long long all_q, all_p;
int q_cnt, p_cnt;
int w, n, k;
void _flush() {
    while (!q.empty() && belong[q.top().second] != 2) q.pop();
    while (!p.empty() && belong[p.top().second] != 1) p.pop();
}
void flush_v(int x) {
    if (belong[x] == 1)
        all_p -= t[x], p_cnt --;
    if (belong[x] == 2)
        all_q  -= (t[x] + 1)/ 2, q_cnt --;
}
void insert_p(int x) {
    flush_v(x);
    p.push(make_pair(t[x], x));
    all_p += t[x];
    belong[x] = 1;
    p_cnt ++;
}
void insert_q(int x) {
    flush_v(x);
    q.push(make_pair(-t[x], x));
    all_q += (t[x] + 1) / 2;
    belong[x] = 2;
    q_cnt ++;
}
void update(){
    _flush();
    while (p_cnt && (q_cnt < w || -q.top().first < p.top().first)) {
        if (q_cnt < w) {
            insert_q(p.top().second);
        } else {
            int x = q.top().second;
            int y = p.top().second;
            insert_q(y);
            insert_p(x);
        }
        _flush();
    }
}
int main() {
    scanf("%d %d %d", &n, &w, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &t[i]);
    long long ans = 0, all = 0;
    int r = n;
    for (int i = n; i >= 1; i --) {
        insert_p(i);
        all += a[i];
        update();
        while (all_p+all_q > k) {
            all -= a[r];
            flush_v(r);
            belong[r] = 0;
            update();
            r --;
        }
        ans =max(ans, all);
    }
    printf("%lld\n", ans);
    return 0;
}