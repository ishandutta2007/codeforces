#include <bits/stdc++.h>

using namespace std;

char s[100001];
long long cnt[26];
long long freq[26][26];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            freq[j][c] += cnt[j];
            ans = max(ans, freq[j][c]);
        }
        cnt[c]++;
        ans = max(ans, cnt[c]);
    }
    printf("%lld\n", ans);
    return 0;
}