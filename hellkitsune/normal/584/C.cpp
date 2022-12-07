#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, cnt;
char s[100005], t[100005], ans[100005];

char getC(char a, char b) {
    if (a != 'a' && b != 'a') return 'a';
    if (a != 'b' && b != 'b') return 'b';
    return 'c';
}

int main() {
    scanf("%d%d", &n, &cnt);
    scanf("%s%s", s, t);
    int dif = 0;
    REP(i, n) dif += s[i] != t[i];
    bool flag = false;
    REP(i, n) if (s[i] != t[i]) {
        if (dif == 1 && !flag) {
            ans[i] = getC(s[i], t[i]);
            --cnt;
        } else if (flag) {
            ans[i] = s[i];
            --cnt;
        } else {
            ans[i] = t[i];
        }
        flag = !flag;
        --dif;
    }
    if (cnt < 0) {
        printf("-1\n");
        return 0;
    }
    REP(i, n) if (s[i] == t[i]) {
        if (cnt == 0) {
            ans[i] = s[i];
        } else {
            ans[i] = (s[i] == 'a') ? 'b' : 'a';
            --cnt;
        }
    }
    cnt *= 2;
    REP(i, n) if (s[i] != t[i]) {
        if (ans[i] != s[i] && ans[i] != t[i]) continue;
        if (cnt == 0) continue;
        ans[i] = getC(s[i], t[i]);
        --cnt;
    }
    ans[n] = '\0';
    printf("%s\n", ans);
    return 0;
}