#include <cassert>
#include <cstdio>
#include <functional>
#include <string>
#include <queue>
#include <vector>

// 2 ::= 2 '|' 1 | 1
// 1 ::= 1 '&' 0 | 0
// 0 ::= '!' 0 | '(' 2 ')' | 'x' | 'y' | 'z'

using std::string;

using P = std::pair<int, int>;

bool vis[3][1 << 8];
string best[3][1 << 8];
std::priority_queue<P, std::vector<P>, std::greater<P>> queue;

bool cmp(const string& b, const string& a)
{
    return b.empty() || a.length() < b.length() || (a.length() == b.length() && a < b);
}

void update(int t, int v, const string& a)
{
    auto& b = best[t][v];
    if (cmp(b, a)) {
        b = a;
        queue.emplace(b.size(), t << 8 | v);
    }
}

int main()
{
    for (int i = 0; i < 3; ++ i) {
        int val = 0;
        for (int msk = 0; msk < 8; ++ msk) {
            val |= (msk >> 2 - i & 1) << msk;
        }
        update(0, val, string(1, 'x' + i));
    }
    int t, v;
    std::vector<int> buf[3];
    while (!queue.empty()) {
        auto top = queue.top();
        queue.pop();
        t = top.second >> 8;
        v = top.second & 255;
        if (vis[t][v]) {
            continue;
        }
        vis[t][v] = true;
        if (t == 0) {
            update(1, v, best[t][v]);
            for (auto&& u : buf[1]) {
                update(1, u & v, best[1][u] + '&' + best[0][v]);
            }
            update(0, v ^ 255, string("!") + best[t][v]);
        } else if (t == 1) {
            update(2, v, best[t][v]);
            for (auto&& u : buf[2]) {
                update(2, u | v, best[2][u] + '|' + best[1][v]);
            }
            for (auto&& u : buf[0]) {
                update(1, u & v, best[1][v] + '&' + best[0][u]);
            }
        } else if (t == 2) {
            for (auto&& u : buf[1]) {
                update(2, u | v, best[2][v] + '|' + best[1][u]);
            }
            update(0, v, string("(") + best[t][v] + ")");
        }
        buf[t].emplace_back(v);
    }
    int n;
    scanf("%d", &n);
    while (n --) {
        static char buf[9];
        scanf("%s", buf);
        int val = 0;
        for (int msk = 0; msk < 8; ++ msk) {
            val |= buf[msk] - '0' << msk;
        }
        string res;
        for (int t = 0; t < 3; ++ t) {
            assert(!best[t][val].empty());
            if (cmp(res, best[t][val])) {
                res = best[t][val];
            }
        }
        puts(res.c_str());
    }
}