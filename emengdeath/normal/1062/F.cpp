#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<vector<int> >in, out;
void work(int n, const vector<vector<int> >&g, const vector<vector<int> >&rg, vector<int>&sum) {
    vector<int> d;
    vector<int> du;
    du.resize(n, 0);
    for (int i = 0; i < n; i ++) {
        du[i] = rg[i].size();
        if (du[i] == 0)
            d.push_back(i);
    }
    for (int i = 0; i < d.size(); i ++) {
        if (d.size() - i == 1) {
            sum[d[i]] += n - d.size();
        } else
            if (d.size() - i == 2) {
                int v = d[i + 1];
                bool flag = 1;
                for (auto u:g[v])
                    if (du[u] == 1)
                        flag = 0;
                if (flag)
                    sum[d[i]] += n - d.size();
            }
        for (auto u:g[d[i]])
            if (!(-- du[u]))
                d.push_back(u);
    }
}
pair<vector<int>, vector<int> > solve(vector<vector<int> > in, vector<vector<int> > out) {
    int n = in.size();
    vector<int> sum(n, 0);
    vector<int> important_p, semi_important_p;
    work(n, in, out, sum);
    work(n, out, in, sum);
    for (int i = 0; i < n; i ++)
        if (sum[i] == n - 1)
            important_p.push_back(i);
        else
            if (sum[i] == n - 2)
                semi_important_p.push_back(i);
    return {important_p, semi_important_p};
}
int main() {
    scanf("%d %d", &n, &m);
    in.resize(n);
    out.resize(n);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x --, y --;
        in[y].push_back(x);
        out[x].push_back(y);
    }
    auto u = solve(in, out);
    printf("%d\n", u.first.size() + u.second.size());
    return 0;
}