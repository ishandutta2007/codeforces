#include <algorithm>
#include <cstdio>
#include <set>
#include <numeric>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
set<long long> f;
vector<int> a;
int n, q;
int T;
int mx, mn, v;
long long all;
void work(const vector<int>& a) {
    all = 0;
    mx = *max_element(a.begin(), a.end());
    mn = *min_element(a.begin(), a.end());
    v = (mx + mn) / 2;
    vector<int> l, r;
    for (auto u:a) {
        all += u;
        if (u <= v) l.push_back(u);
        else r.push_back(u);
    }
    f.insert(all);
    if (mn == mx) return;
    work(l);
    work(r);
}
int main() {
    scanf("%d", &T);
    while (T -- ){
        scanf("%d %d", &n, &q);
        a.clear();
        while (n --) {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        f.clear();
        work(a);
        while (q --) {
            int s;
            scanf("%d", &s);
            if (f.find(s) != f.end())
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}