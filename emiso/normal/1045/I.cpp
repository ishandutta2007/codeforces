#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, f[26];
map<int, int> ff;
char s[MN]; string str;
ll ans;

void add() {
    int j = 0;
    for(int i = 0; i < 26; i++) {
        j += ((f[i] % 2) << i);
    }
    for(int b = 0; b < 26; b++)
        ans += 1LL*ff[j^(1<<b)];
    ans += ff[j];
    ff[j]++;
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        memset(f, 0, sizeof f);
        scanf("%s", s);
        str = s;
        for(char c : str) {
            f[c-'a']++;
        }
        add();
    }

    printf("%lld\n", ans);
    return 0;
}