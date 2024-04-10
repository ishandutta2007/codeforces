#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[1001005],ss[1001005];
int n,pi[1001005];

void fail() {
    puts("Just a legend");
    exit(0);
}

void ans(int l, int r) {
    strcpy(ss,s+l);
    ss[r-l+1] = 0;
    puts(ss);
    exit(0);
}

int main()
{
    scanf("%s",s);
    n = strlen(s);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    if (pi[n-1] == 0) fail();
    for (int i = 1; i < n-1; ++i) {
        if (pi[i] == pi[n-1]) ans(0, pi[n-1]-1);
    }
    if (pi[pi[n-1]-1] == 0) fail();
    ans(0, pi[pi[n-1]-1]-1);

    return 0;
}