#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K;
vector<pair<int, int>> ans;
mt19937 rnd(time(0));

struct seg {
    long long a, b, c, id;

    bool para(seg o) { return a * o.b == b * o.a; }
    seg inter(seg o) { return (seg){c * o.b - b * o.c, a * o.c - c * o.a, a * o.b - b * o.a}; }
    bool chk(seg o) { return a * o.a + b * o.b == c * o.c; }
};
vector<seg> V;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, a, b, c; i <= n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        V.push_back((seg){a, b, -c, i});
    }
    for (; !V.empty() && K; K--) {
        pair<int, int> p(V[0].id, -1);
        vector<seg> nV = V;
        for (int $ = 0; $ < 25 && V.size() - nV.size() <= K; $++) {
            int i = rnd() % V.size(), j = rnd() % V.size();
            if (V[i].para(V[j])) continue;
            vector<seg> T;
            auto q = V[i].inter(V[j]);
            for (int k = 0; k < V.size(); k++) {
                if (!V[k].chk(q)) T.push_back(V[k]);
            }
            if (T.size() < nV.size()) nV = T, p = {V[i].id, V[j].id};
        }
        ans.push_back(p);
        if (!~p.second) V.erase(V.begin());
        else V = nV;
    }
    if (!V.empty()) puts("NO"), exit(0);
    printf("YES\n%d\n", ans.size());
    for (auto p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}