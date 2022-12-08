#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>

const int MAXN = 300000 + 100;
const int MAXP = 50;

std::pair<int,int> lst[MAXN];
int b[MAXN];
int n;

double m2[MAXP];

struct node {
    int sum;
    double s1, s2;
    void merge(node a, node b) {
        sum = a.sum + b.sum;
        s1 = b.s1; if (b.sum < MAXP) s1 += a.s1 * m2[b.sum];
        s2 = a.s2; if (a.sum < MAXP) s2 += b.s2 * m2[a.sum];
    }
} tr[MAXN * 4];

void build(int x, int s, int t) {
    if (s == t) {
        tr[x].sum = 0;
        tr[x].s1 = 1;
        tr[x].s2 = 1;
        return;
    }
    int mid = (s + t) / 2;
    build(x*2, s, mid);
    build(x*2 + 1, mid + 1, t);
    tr[x].merge(tr[x*2], tr[x*2 + 1]);
}

void add(int x, int s, int t, int ind) {
    //std::cout << x << " " << s << " " << t << " " << ind << std::endl;
    if (s == t) {
        ++tr[x].sum;
        tr[x].s1 /= 2;
        tr[x].s2 /= 2;
        return;
    }
    int mid = (s + t) / 2;
    if (ind <= mid)
        add(x*2, s, mid, ind);
    else
        add(x*2 + 1, mid + 1, t, ind);
    tr[x].merge(tr[x*2], tr[x*2 + 1]);
}

node get(int x, int s, int t, int st, int en) {
    if (st <= s && t <= en)
        return tr[x];
    int mid = (s + t) / 2;
    if (en <= mid)
        return get(x*2, s, mid, st, en);
    if (mid < st)
        return get(x*2 + 1, mid + 1, t, st, en);
    node a = get(x*2, s, mid, st, en);
    node b = get(x*2 + 1, mid + 1, t, st, en);
    node c; c.merge(a, b);
    return c;
}

int main() {
    m2[0] = 1;
    for (int i = 1; i < MAXP; ++i)
        m2[i] = m2[i-1] / 2;

    std::cin >> n;
    //std::cout << "#1" << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
        lst[i] = std::make_pair(b[i], i);
    }
    //std::cout << "#2" << std::endl;
    std::sort(lst + 1, lst + n + 1, std::greater<std::pair<int, int> >());

   // std::cout << "building" << std::endl;
    build(1, 1, n);
    //std::cout << "built" << std::endl;

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
    //std::cout << "#a" << std::endl;
        node a = get(1, 1, n, 1, lst[i].second);
    //std::cout << "#b" << std::endl;
        node b = get(1, 1, n, lst[i].second, n);
    //std::cout << "#c" << std::endl;
        ans += lst[i].first * a.s1 * b.s2;
        add(1, 1, n, lst[i].second);
    }
    ans /= n;
    ans /= n;
    ans /= 2;
    std::cout << std::setprecision(9) << ans << std::endl;
    return 0;
}