#include <bits/stdc++.h>
using namespace std;
int c[100010], n, t[100010];
vector<int> _c, _t;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    for(int i = 1; i <= n; i++) scanf("%d", t + i);
    if(c[1] != t[1]) return puts("No"), 0;
    for(int i = 1; i < n; i++) _c.push_back(c[i + 1] - c[i]);
    for(int i = 1; i < n; i++) _t.push_back(t[i + 1] - t[i]);
    sort(_c.begin(), _c.end());
    sort(_t.begin(), _t.end());
    for(int i = 0; i < n - 1; i++) if(_c[i] != _t[i]) return puts("No"), 0;
    return puts("Yes"), 0;
}