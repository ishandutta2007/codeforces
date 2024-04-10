#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[200005],ans[200005];
int n,cnt[99],ansi; /// declared n as a char and got -2...
vector<int> v;

int main()
{
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] % 2) v.push_back(i);
    }
    while (v.size() >= 2) {
        int bi = v.back(); v.pop_back();
        int ai = v[0]; v.erase(v.begin());
        ++cnt[ai];
        --cnt[bi];
    }
    for (int i = 0; i < 26; ++i) {
        while (cnt[i] >= 2) ans[ansi++] = 'a' + i, cnt[i] -= 2;
    }
    printf("%s", ans);
    for (int i = 0; i < 26; ++i) {
        while (cnt[i]) printf("%c", 'a' + i), --cnt[i];
    }
    reverse(ans, ans + ansi);
    printf("%s", ans);

    return 0;
}