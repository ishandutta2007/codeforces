#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
char s[maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    vector<pair<int, int>> V;
    for (int i = 1; i <= n; i++) if (s[i] == '#') {
        int j = i;
        while (s[j] == '#') j++;
        V.emplace_back(i, j - 1), i = j - 1;
    }
    if (V.empty()) puts("0"), exit(0);
    for (int k : {0, 1, 2, 3}) {
        auto A = V;
        vector<int> ans;
        int m = n - k, tmp;
        for (auto &p : A) {
            p.first -= k;
            if (p.first <= 0 || p.second > m) goto nxt;
        }
        tmp = A[0].first;
        if (A[0].first > 1) {
            if (!k || A[0].first == 2) goto nxt;
            while (A[0].first > 1) {
                if (A[0].first - 2 != 2) {
                    A[0].first -= 2, ans.push_back(1);
                } else if (k > 1) {
                    A[0].first -= 3, ans.push_back(2);
                } else {
                    break;
                }
            }
            if (A[0].first ^ 1) goto nxt;
            reverse(ans.begin(), ans.end());
        }
        for (int i = 0; i < A.size() - 1; i++) {
            ans.push_back(A[i].second - (!i ? tmp : A[i].first) + 1);
            if (A[i].second >= A[i + 1].first) goto nxt;
            if (A[i].second == A[i + 1].first - 2) continue;
            if (!k || A[i].second == A[i + 1].first - 3) goto nxt;
            while (A[i].second < A[i + 1].first - 2) {
                if (A[i].second + 2 != A[i + 1].first - 3) {
                    A[i].second += 2, ans.push_back(1);
                } else if (k > 1) {
                    A[i].second += 3, ans.push_back(2);
                } else {
                    break;
                }
            }
            if (A[i].second ^ (A[i + 1].first - 2)) goto nxt;
        }
        ans.push_back(A.back().second - (A.size() == 1 ? tmp : A.back().first) + 1);
        if (A.back().second < m) {
            if (!k || A.back().second == m - 1) goto nxt;
            while (A.back().second < m) {
                if (A.back().second + 2 != m - 1) {
                    A.back().second += 2, ans.push_back(1);
                } else if (k > 1) {
                    A.back().second += 3, ans.push_back(2);
                } else {
                    break;
                }
            }
            if (A.back().second ^ m) goto nxt;
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n'), exit(0);
        nxt:;
    }
    puts("-1");
    return 0;
}