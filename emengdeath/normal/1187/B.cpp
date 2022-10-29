#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;
const int N = 3e5;
int f[N][26], d[26];
int n;
char s[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++){
        for (int j = 0;j < 26; j ++)
            f[i][j] = f[i - 1][j];
        char c;
        scanf(" %c", &c);
        f[i][c - 'a'] ++;
    }
    int T;
    scanf("%d", &T);
    while (T --) {
        memset(d, 0, sizeof(d));
        scanf("%s",s);
        int len = strlen(s);
        for (int i = 0; i < len ; i++)
            d[s[i] - 'a'] ++;
        int l = 1, r = n, mid, s = n;
        while (l <= r) {
            mid = (l + r) / 2;
            bool sig= 1;
            for (int i = 0; i<26; i++)
                if (d[i]>f[mid][i]) {
                    sig = 0;
                    break;
                }
            if (sig) s = min(s, mid), r = mid - 1;
            else
                l = mid +1;
        }
        printf("%d\n", s);
    }
    return 0;
}