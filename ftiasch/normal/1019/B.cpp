#include <bits/stdc++.h>

int ask(int i)
{
#ifdef LOCAL_JUDGE
    // static const int a[] = {1, 2, 1, 2, 3, 4, 3, 2};
    static const int a[] = {1, 2, 3, 2, 1, 0};

    return a[i];
#else
    printf("? %d\n", i + 1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
#endif
}

int n;

int eval(int i)
{
    return ask(i) - ask(i + n);
}

int solve()
{
    scanf("%d", &n);
    n >>= 1;
    int l = 0;
    int fl = eval(l);
    if (fl & 1) {
        return -2;
    }
    if (fl == 0) {
        return 0;
    }
    int r = n;
    while (l < r) {
        int m = l + r >> 1;
        int fm = eval(m);
        if (fm == 0) {
            return m;
        }
        if (fl * fm < 0) {
            r = m;
        } else {
            l = m;
            fl = fm;
        }
    }
    return -1;
}

int main()
{
    printf("! %d\n", solve() + 1);
}