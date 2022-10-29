#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int n;
int fa[500001];
char s[1000100];
bool bz[26];
int getfa(int x) {return fa[x] == x? x: fa[x] = getfa(fa[x]);}
void combine(int x, int y) {
    x = getfa(x);
    y = getfa(y);
    fa[x] = y;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + 26; i ++) fa[i] = i;
    for (int i = 1; i <= n; i ++){
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len; j ++)
            combine(s[j] - 'a', i + 25), bz[s[j] - 'a'] =1;
    }
    int ans = 0;
    for (int i = 0; i < 26; i ++)
        ans -= (!bz[i]);
    for (int i = 0; i < n + 26; i ++)
        ans += (getfa(i) ==i);
    printf("%d\n", ans);
    return 0;
}