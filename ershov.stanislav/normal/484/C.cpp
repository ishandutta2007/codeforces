#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000111;

char s[N], s2[N];
int p1[N], pc[N], np[N];
int n, m, k, d;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", s);
    n = strlen(s);
    cin >> m;
    for (int num = 0; num < m; num++) {
        scanf("%d%d", &k, &d);

        for (int i = 0; i < k; i++) p1[i] = (i%d)*( (k - 1)/d + 1 ) + i/d - max(i%d - (k-1)%d - 1, 0) - 1;
        for (int i = k; i < n; i++) p1[i] = i - 1;
        for (int i = 0; i < n; i++) {
            if (p1[i] < 0) p1[i]+=n;
            pc[i] = i;
        }
        for (int i = 21; i>=0; i--) {
            for (int j = 0; j < n; j++) np[j] = pc[pc[j]];
            for (int j = 0; j < n; j++) pc[j] = np[j];
            if ((n - k + 1)&(1<<i)) {
                for (int j = 0; j < n; j++) np[j] = p1[pc[j]];
                for (int j = 0; j < n; j++) pc[j] = np[j];
            }
        }
        for (int i = 0; i < n; i++) s2[(pc[i] - k + 1 + n)%n] = s[i];
        for (int i = 0; i < n; i++) s[i] = s2[i];
        printf("%s\n", s);
    }
    return 0;
}