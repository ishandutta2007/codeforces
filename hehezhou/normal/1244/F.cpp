#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[2000010];
int a[2000010];
vector<int> q;
inline void check(int x, int rnd) {
    if(a[x]) return;
    a[x] = rnd;
    int now = s[x];
    if(rnd & 1) now = 'W' + 'B' - now;
    int last = (x - 1 + n) % n, nxt = (x + 1) % n;
    if((a[last] && a[last] != rnd) && (a[nxt] && a[nxt] != rnd)) s[x] = now;
    else if(a[last] && (a[last] != rnd)) s[x] = s[last];
    else s[x] = s[nxt];
    q.push_back(x);
}
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for(int i = 0; i < n; i++) {
        if(s[i] == s[(i - 1 + n) % n] || s[i] == s[(i + 1) % n]) a[i] = -1, q.push_back(i);
    }
    for(int i = 1; i <= k; i++) {
        if(q.empty()) break;
        vector<int> tmp = q;
        q.clear();
        for(auto j : tmp) {
            check((j - 1 + n) % n, i);
            check((j + 1) % n, i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == 0 && (k % 2)) s[i] = 'W' + 'B' - s[i];
    }
    return puts(s), 0;
}