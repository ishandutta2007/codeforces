#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
char s[1000010];
int sta[1000010], ans[1000010], len[1000010], n, top, stasum;
inline void insert(int id) {
    while (top && len[sta[top]] <= len[id]) {
        stasum = (stasum + 1ll * ans[sta[top]] * (mod - len[sta[top]] - 1)) % mod;
        stasum = (stasum + 1ll * ans[sta[top - 1]] * (len[sta[top]] + 1)) % mod;
        top--;
    }
    stasum = (stasum + 1ll * ans[id] * (len[id] + 1)) % mod;
    stasum = (stasum + 1ll * ans[sta[top]] * (mod - len[id] - 1)) % mod;
    sta[++top] = id;
}
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int TTag = 1;
    while (s[n] == '0') TTag++, n--;
    if (n == 0) return cout << TTag - 1 << endl, 0;
    int Ans = 0;
    for (int i = n; i; i--) {
        int tmp = i;
        i--;
        while (s[i] == '0') i--;
        i++;
        len[tmp] = tmp - i, ans[tmp] = stasum + 1;
        insert(tmp);
        if (i == 1) Ans = 1ll * ans[tmp] * (len[tmp] + 1) % mod;
    }
    return cout << 1ll * Ans * TTag % mod << endl, 0;
}