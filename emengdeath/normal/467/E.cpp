#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int N = 1e6;
int cnt, n;
int a[N];
map<int, int> f;
int fb[N];
int last[N][3], g[N * 4], nex[N];
pair<int, pair<int, int> > s[N];
pair<pair<int, int>, pair<int, pair<int, int> > > w[N];
pair<int, int> fw[N * 4];
void ins(int l, int r, int s, int ll, int rr, int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        g[s] = max(g[s], v);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, v);
    ins((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
}
int get(int l, int r, int s, int ll) {
    int v = 0;
    while (1) {
        v = max(v, g[s]);
        if (l == r) return v;
        if ((l + r) / 2 >= ll)
            r = (l + r )/ 2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
}
pair<int, int> getw(int l, int r, int s, int ll) {
    if (l > ll) return {0, 0};
    if (r <= ll) return fw[s];
    return max(getw(l, (l + r) / 2, s + s, ll) , getw((l + r)/ 2 + 1, r, s + s + 1, ll));
}
void insw(int l, int r, int s, int ll,int v){
    while (1) {
        fw[s] = max(fw[s], {v, ll});
        if (l == r) return;
        if ((l + r) / 2  >= ll)
            r = (l + r) /2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (f.find(a[i]) == f.end())
            fb[f[a[i]] = ++cnt] = a[i];
        a[i] = f[a[i]];
    }
    for (int i = 1; i <= n; i ++) {
        if (last[a[i]][0]) {
            ins(1, n, 1, last[a[i]][0] + 1, i - 1, last[a[i]][0]);
            nex[last[a[i]][0]] = i;
            int v = get(1, n, 1, last[a[i]][0]);
            if (v) {
                s[a[i]] = max(s[a[i]], {v, {last[a[i]][0], nex[v]}});
                auto vv = getw(1, n, 1, s[a[i]].first - 1);
                w[i] = max(w[i], {{vv.first + 1, vv.second}, s[a[i]]});
            }
        }
        if (last[a[i]][2]) {
            auto v = getw(1, n, 1, last[a[i]][2] - 1);
            w[i] = max(w[i], {{v.first + 1, v.second}, {last[a[i]][2], {last[a[i]][1], last[a[i]][0]}}});
        }
        insw(1, n, 1, i, w[i].first.first);
        last[a[i]][2] = last[a[i]][1];
        last[a[i]][1] = last[a[i]][0];
        last[a[i]][0] = i;
    }
    pair<int, int> x = fw[1];
    vector<int> ans;
    while (x.first) {
        ans.push_back(fb[a[x.second]]);
        ans.push_back(fb[a[w[x.second].second.second.second]]);
        ans.push_back(fb[a[w[x.second].second.second.first]]);
        ans.push_back(fb[a[w[x.second].second.first]]);
        x = w[x.second].first;
        x.first --;
    }
    printf("%d\n", (int)ans.size());
    reverse(ans.begin(), ans.end());
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}