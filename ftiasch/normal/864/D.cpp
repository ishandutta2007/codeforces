#include <algorithm>
#include <cstdio>
#include <set>

const int N = 200000;

int a[N], cnt[N], skip[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        cnt[-- a[i]] ++;
    }
    int need = 0;
    std::set<int> free;
    for (int i = 0; i < n; ++ i) {
        if (cnt[i] == 0) {
            free.insert(i);
        } else {
            need += cnt[i] - 1;
        }
    }
    printf("%d\n", need);
    for (int i = 0; i < n; ++ i) {
        if (cnt[a[i]] > 1) {
            int can = *free.begin();
            if (can < a[i] || skip[a[i]]) {
                cnt[a[i]] --;
                a[i] = can;
                free.erase(can);
            } else {
                skip[a[i]] = true;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", a[i] + 1, " \n"[i == n - 1]);
    }
}