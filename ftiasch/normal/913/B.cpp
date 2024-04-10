#include <cstdio>
#include <cstring>

const int N = 1000;

int p[N], cnt[N];
bool leaf[N];

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        memset(leaf, true, sizeof(leaf));
        for (int i = 1; i < n; ++ i) {
            scanf("%d", p + i);
            leaf[-- p[i]] = false;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = n - 1; i >= 0; -- i) {
            cnt[p[i]] += leaf[i];
        }
        bool ok = true;
        for (int i = 0; i < n; ++ i) {
            ok &= leaf[i] || cnt[i] >= 3;
        }
        puts(ok ? "Yes" : "No");
    }
}