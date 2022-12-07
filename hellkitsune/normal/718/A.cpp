#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, t;
char s[200005];

int main() {
    scanf("%d%d", &n, &t);
    scanf("%s", s);
    int ind = 0;
    while (s[ind] != '.') {
        ++ind;
    }
    ++ind;
    bool flag = false;
    for (int i = ind; i < n; ++i) if (s[i] >= '5') {
        if (t > 0) {
            for (int j = i + 1; j < n; ++j) {
                s[j] = '0';
            }
        }
        int j = i;
        while (t > 0) {
            s[j] = '0';
            --t;
            if (s[j - 1] == '.') {
                ++s[j - 2];
                for (int x = j - 2; x >= 1; --x) {
                    if (s[x] > '9') {
                        s[x] = '0';
                        ++s[x - 1];
                    }
                }
                if (s[0] > '9') {
                    flag = true;
                    s[0] = '0';
                }
                break;
            }
            ++s[j - 1];
            --j;
            if (s[j] < '5') break;
        }
        break;
    }
    while (s[n - 1] == '0') {
        --n;
    }
    if (s[n - 1] == '.') {
        --n;
    }
    if (flag) printf("1");
    s[n] = '\0';
    printf("%s\n", s);
    return 0;
}