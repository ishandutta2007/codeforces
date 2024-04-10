#include <bits/stdc++.h>
using namespace std;

char s[100105], st[100105], ans[100105];
int n, sti, ansi, cnt[26];

int main()
{
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    int curidx = 0;
    char cur = 'a';
    while (cur <= 'z') {
        if (!cnt[cur - 'a']) {
            ++cur;
            continue;
        }
        while (sti && st[sti - 1] <= cur)
            ans[ansi++] = st[--sti];
        while (curidx < n) {
            --cnt[s[curidx] - 'a'];
            if (s[curidx] == cur) {
                ans[ansi++] = s[curidx++];
                break;
            }
            st[sti++] = s[curidx++];
        }
    }
    while (sti)
        ans[ansi++] = st[--sti];
    cout << ans << endl;

    return 0;
}