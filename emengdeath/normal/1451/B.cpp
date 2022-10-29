#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e2 + 10;
int n, q, T;
bool bz[N];
int l[N], r[N];
char s[N];
void work() {
    for (int i = 1; i <= q; i ++) {
        int x = 1;
        for (int j = l[i]; j < r[i]; j ++) {
            while (s[x] != s[j]) x ++;
            bz[i] |= (x != j);
            ++x;
        }
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &q);
        scanf("%s", s + 1);
        for (int i = 1; i <= n;i ++) s[i] -= '0';
        for (int i = 1; i <= q; i ++) {
            bz[i] = 0;
            scanf("%d %d", &l[i], &r[i]);
        }
        work();
        reverse(s+1,s+n+1);
        for (int i = 1; i <= q; i ++)
        {
            swap(l[i], r[i]);
            l[i] = n - l[i] + 1;
            r[i] = n - r[i] + 1;
        }
        work();
        for (int i =1; i <= q; i ++)
            if (bz[i]) puts("YES"); else  puts("NO");
    }
    return 0;
}