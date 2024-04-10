#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
const int N = 2e6;
int n;
char s[N];
int l[N], r[N];
long long ans;
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n ; i++) {
        l[i] = l[i - 1] + (s[i] == 'v' && s[i - 1] == 'v');
    }
    for (int i = n; i ; i--) {
        r[i] = r[i + 1] + (s[i] == 'v' && s[i + 1] == 'v');
    }
    for (int i = 1;  i<= n ; i ++)
        if (s[i] == 'o')
            ans += (long long)l[i] * r[i];
    printf("%lld\n", ans);
    return 0;
}