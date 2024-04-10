#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n;
char s[3][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 3; i++) {
            scanf("%s", s[i] + 1);
        }
        auto chk = [&](int i1, int i2) {
            int c1 = 0, c2 = 0;
            vector<int> pos1, pos2;
            for (int i = 1; i <= n << 1; i++) {
                if (s[i1][i] == '0') c1++, pos1.push_back(i);
                if (s[i2][i] == '0') c2++, pos2.push_back(i);
            }
            if (min(c1, c2) < n) {
                pos1.clear(), pos2.clear(), c1 = c2 = 0;
                for (int i = 1; i <= n << 1; i++) {
                    if (s[i1][i] == '1') c1++, pos1.push_back(i);
                    if (s[i2][i] == '1') c2++, pos2.push_back(i);
                }
                if (min(c1, c2) < n) return 0;
            }
            while (pos1.size() > pos2.size()) pos1.pop_back();
            while (pos2.size() > pos1.size()) pos2.pop_back();
            int p1 = 1, p2 = 1;
            for (int i = 0; i < pos1.size(); i++) {
                while (p1 < pos1[i]) putchar(s[i1][p1]), p1++;
                while (p2 < pos2[i]) putchar(s[i2][p2]), p2++;
                putchar(s[i1][p1]), p1++, p2++;
            }
            while (p1 <= n << 1) putchar(s[i1][p1]), p1++;
            while (p2 <= n << 1) putchar(s[i2][p2]), p2++;
            putchar('\n'); return 1;
        };
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 1; i <= n << 1; i++) {
            if (s[0][i] == s[1][i]) c1++;
            if (s[0][i] == s[2][i]) c2++;
            if (s[1][i] == s[2][i]) c3++;
        }
        assert(chk(0, 1) || chk(1, 2) || chk(0, 2));
    }
    return 0;
}