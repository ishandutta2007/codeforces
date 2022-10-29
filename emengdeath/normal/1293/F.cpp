#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5001;
int a[N], prime[N];
long long ans;
struct node{
    vector<pair<int, int> > d;
    vector<pair<int, int> > g;
    int sum;
    long long allv, allsum;
    int calc(int x, int y) {
        return x >=y ?calc(x / y, y) + x / y:0;
    }
    void init(int x){
        for (int i = 1; i <= prime[0] && prime[i] <= x; i ++)
            d.push_back(make_pair(prime[i], calc(x, prime[i])));
        reverse(d.begin(), d.end());
    }
    int len() {
        int v = 0;
        for (auto u:d)
            v += u.second;
        return v;
    }
}f[N * 4];
int n, tot;
vector<int>d;
int sum[N];
vector<pair<int, int> > getlca(vector<pair<int, int> >a,vector<pair<int, int> >b ) {
    vector<pair<int, int> > c;
    for (int i = 0; i < a.size() && i < b.size(); i ++)
        if (a[i].first == b[i].first) {
            if (a[i].second != b[i].second) {
                c.push_back(make_pair(a[i].first, min(a[i].second, b[i].second)));
                break;
            } else
                c.push_back(a[i]);
        } else
            break;
    return c;
}
bool operator!= (vector<pair<int, int> >  a, vector<pair<int, int> > b) {
    if (a.size() != b.size()) return 1;
    for (int i = 0; i < a.size(); i++)
        if (a[i].first != b[i].first || a[i].second != b[i].second) return 1;
    return 0;
}
void dfs(int x) {
    f[x].allsum = f[x].sum;
    for (auto u:f[x].g)
    {
        dfs(u.first);
        f[x].allsum += f[u.first].allsum;
        f[x].allv += f[u.first].allv + f[u.first].allsum * u.second;
    }
}
void dfs(int x, long long allsum, long long allv) {
    ans = min(ans, allv + f[x].allv);
    for (auto u:f[x].g){
        long long allsum1 = allsum + f[x].allsum - f[u.first].allsum;
        dfs(u.first, allsum1, allv + f[x].allv - (f[u.first].allv + f[u.first].allsum * u.second) + allsum1 * u.second);
    }
}
int main() {
    for (int i = 2; i <= 5000; i ++)
    {
        if (!a[i])
            prime[a[i] = ++prime[0]] = i;
        for (int j = 1; j <= a[i] && prime[j] * i <= 5000; j ++)
            a[prime[j] * i] = j;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++){
        int x;
        scanf("%d", &x);
        sum[max(x, 1)] ++;
    }
    tot = 1;
    f[1].init(1);
    f[1].sum = sum[1];
    d.push_back(1);
    for (int i = 2; i <= 5000; i ++){
        f[++tot].sum = sum[i];
        f[tot].init(i);
        int now = tot;
        if ((getlca(f[d[d.size() - 1]].d, f[now].d) )!= f[d[d.size() - 1]].d) {
            int last = d[d.size() - 1];
            d.pop_back();
            while (d.size() && getlca(f[d[d.size() - 1]].d, f[now].d) != f[d[d.size() - 1]].d) {
                int u = d[d.size() - 1];
                f[u].g.push_back(make_pair(last, f[last].len() - f[u].len()));
                last = u;
                d.pop_back();
            }
            if (!d.size() || getlca(f[last].d, f[now].d) != f[d[d.size() - 1]].d)
            {
                f[++tot].d = getlca(f[last].d, f[now].d);
                f[tot].g.push_back(make_pair(last, f[last].len() - f[tot].len()));
                d.push_back(tot);
            } else
                f[d[d.size() - 1]].g.push_back(make_pair(last, f[last].len() - f[d[d.size() - 1]].len()));
        }
        d.push_back(now);
    }
    while (d.size() > 1) {
        int u = d[d.size() - 1], v = d[d.size() - 2];
        f[v].g.push_back(make_pair(u, f[u].len() - f[v].len()));
        d.pop_back();
    }
    dfs(1);
    ans = 1e18;
    dfs(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}