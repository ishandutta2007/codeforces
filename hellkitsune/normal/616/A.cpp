#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[1000005];
char t[1000005];

int main() {
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    int dif = max(n, m) - min(n, m);
    for (int i = max(n, m) - 1; i >= dif; --i) {
        if (n < m) s[i] = s[i - dif];
        else t[i] = t[i - dif];
    }
    REP(i, dif) {
        if (n < m) s[i] = '0';
        else t[i] = '0';
    }
    n = max(n, m);
    //t[n] = s[n] = '\0';
    //printf("%s %s", s, t);
    REP(i, n) if (s[i] < t[i]) {
        cout << "<" << endl;
        return 0;
    } else if (s[i] > t[i]) {
        cout << ">" << endl;
        return 0;
    }
    cout << "=" << endl;
    return 0;
}