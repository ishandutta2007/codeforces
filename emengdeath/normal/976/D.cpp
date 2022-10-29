#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>d;
int n;
vector<pair<int, int> > solve(vector<int> d) {
    if (d.size() == 0)
        return vector<pair<int, int> >(0);
    else
        if (d.size() == 1) {
            vector<pair<int, int> >a;
            for (int i = 1; i <= d[0]; i ++)
                for (int j = i + 1; j <= d[0] + 1; j ++)
                    a.push_back(make_pair(i, j));
            return a;
        }
    vector<int>dd;
    for (int i = 1; i < d.size() - 1; i ++)
        dd.push_back(d[i] - d[0]);
    int x = dd.size() ? dd[dd.size() - 1] + 1:1;
    int y = d[d.size() - 1] + 1 - d[0] - x;
    vector<pair<int, int> > a = solve(dd);
    for (int i = 1; i <= d[d.size() - 1] + 1; i ++)
        for (int j = 1; j <= d[d.size() - 1] - x - y + 1; j ++) {
            if (i > x && i >=j + x && d[d.size() - 1] - y + 1 >= i) continue;
            a.push_back(make_pair(i, j + x));
        }
    return a;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        d.push_back(x);
    }
    vector<pair<int, int> > ans = solve(d);
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d\n", u.first, u.second);
    return 0;
}