#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
int cnt[2];
struct Bottle {
    long long x, y;
    Bottle() {}
    Bottle(long long x, long long y) {
        this->x = x;
        this->y = y;
    }
    bool operator < (const Bottle&) const;
};
std::multiset<Bottle> s[2];
enum UpdateType {INSERT, REMOVE};

bool comp(long long x1, long long y1, long long x2, long long y2) {
    if (y1 == 0)
        return false;
    if (y2 == 0)
        return true;
    if (x1 / y1 != x2 / y2)
        return x1 / y1 < x2 / y2;
    return comp(y2, x2 % y2, y1, x1 % y1);
}

bool Bottle::operator < (const Bottle& other) const {
    if (this->x < 0 && other.x < 0)
        return comp(-other.x, other.y, -this->x, this->y);
    if (this->x < 0)
        return true;
    if (other.x < 0)
        return false;
    return comp(this->x, this->y, other.x, other.y);
}

void update(int id, Bottle b, UpdateType t) {
    if (t == INSERT) {
        s[id].insert(b);
        if (s[id].count(b) == 1 && s[id ^ 1].count(b) > 0)
            ++cnt[1];
    }
    if (t == REMOVE) {
        s[id].erase(s[id].find(b));
        if (s[id].count(b) == 0 && s[id ^ 1].count(b) > 0)
            --cnt[1];
    }
}

void update(Bottle b, UpdateType t) {
    if (b.x == 0 && b.y == 0) {
        if (t == INSERT)
            ++cnt[0];
        if (t == REMOVE)
            --cnt[0];
    }
    if (b.y > 0 || b.y == 0 && b.x > 0)
        update(0, b, t);
    if (b.y < 0 || b.y == 0 && b.x < 0)
        update(1, Bottle(-b.x, -b.y), t);
}

int query() {
    if (cnt[0] > 0)
        return 1;
    if (cnt[1] > 0)
        return 2;
    if (!s[0].empty() && !s[1].empty() && *s[0].begin() < *--s[1].end() && *s[1].begin() < *--s[0].end())
        return 3;
    return 0;
}

int main() {
    int a, b, c, n; scanf("%d%d%d%d", &a, &b, &c, &n);
    c = a + b + c;
    std::vector<Bottle> v(1);
    for (int i = 1; i <= n; ++i) {
        char ch; scanf(" %c", &ch);
        if (ch == 'A') {
            long long x, y, z; scanf("%lld%lld%lld", &x, &y, &z);
            z = x + y + z;
            x = x * c - z * a;
            y = y * c - z * b;
            v.push_back(Bottle(x, y));
            update(v.back(), INSERT);
        }
        if (ch == 'R') {
            int id; scanf("%d", &id);
            update(v[id], REMOVE);
        }
        printf("%d\n", query());
    }
}