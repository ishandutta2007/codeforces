#include <cstdio>

#include <queue>

#define LOG(FMT...) // fprintf(stderr, "[LOG] "FMT)

using namespace std;

typedef long long ll;

struct tpair {
    ll s;
    int x, y;

    tpair() {}

    tpair(ll s, int x, int y) : s(s), x(x), y(y) {}

    bool operator<(const tpair& a) const;
	bool operator==(const tpair& a) const { return s == a.s && x == a.x && y == a.y; }
};

int n, m, r, k;

ll calc_s(int x, int n);
ll calc_sum(int x, int n);

int main() {
    priority_queue<tpair> q;
    ll whole, cnt = 0;
    scanf("%d%d%d%d", &n, &m, &r, &k);
    whole = (ll)(n - r + 1) * (m - r + 1);
    ll s;
    int x, y;
    x = (n + 1) / 2;
    y = (m + 1) / 2;
    s = calc_s(x, n) * calc_s(y, m);
    q.push(tpair(s, x, y));
    while (k > 0) {
        tpair tmp = q.top();
		q.pop();
		while (!q.empty() && q.top() == tmp)
			q.pop();
        x = tmp.x;
        y = tmp.y;
        s = tmp.s;
        ll sum = calc_sum(x, n) * calc_sum(y, m);
        if (sum >= k) {
            cnt += k * s;
            k = 0;
        } else {
            LOG("%lld %lld\n", sum, s);
            k -= sum;
            cnt += sum * s;
            if (x > 1)
                q.push(tpair(calc_s(x - 1, n) * calc_s(y, m), x - 1, y));
            if (y > 1)
                q.push(tpair(calc_s(x, n) * calc_s(y - 1, m), x, y - 1));
        }
    }
    printf("%.10lf\n", (double)cnt / whole);
    return 0;
}

ll calc_s(int x, int n) {
    return min(x, min(n - r + 1, r));
}

ll calc_sum(int x, int n) {
    if (x == n - x + 1)
        return 1;
    return 2;
}

bool tpair::operator<(const tpair& a) const {
    if (s != a.s)
        return s < a.s;
    if (x != a.x)
        return x < a.x;
    return y < a.y;
}