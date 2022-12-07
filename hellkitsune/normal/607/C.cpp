#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[2000007];
int n, len;
int p[2000007];

int main() {
    //freopen("input.txt", "r", stdin);
    int len;
    scanf("%d", &len), --len;
    scanf("%s%s", s, s + len + 1);
    REP(i, len) if (s[i] == 'W') s[i] = 'a';
    else if (s[i] == 'E') s[i] = 'b';
    else if (s[i] == 'N') s[i] = 'c';
    else s[i] = 'd';
    for (int i = len + 1; i <= 2 * len; ++i) if (s[i] == 'W') s[i] = 'b';
    else if (s[i] == 'E') s[i] = 'a';
    else if (s[i] == 'N') s[i] = 'd';
    else s[i] = 'c';
    reverse(s, s + len);
    s[len] = 'e';
    n = 2 * len + 1;

    p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j]) ++j;
		p[i] = j;
	}

    if (p[2 * len] > 0) printf("NO\n");
    else printf("YES\n");
	return 0;
}