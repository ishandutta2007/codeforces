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
const int N = 1e7;
char s[N];
int n;
int tot;
bool sig;
char ans[N];
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int l = 0, r = n + 1;
    while (1) {
        if (s[l + 1] == s[r - 1] && l + 1 <= r - 1) {
            if (l + 1 == r - 1) sig = 1;
            ans[++tot] = s[l + 1];
            l ++;
            r --;
            continue;
        } else
            if (s[l + 1] == s[r - 2] && l + 1 <= r - 2) {
                if  (l + 1 == r - 2) sig = 1;
                ans[++tot] = s[l + 1];
                l ++ ;
                r -= 2;
                continue;
            } else
            if (s[l + 2] == s[r - 1] && l + 2 <= r - 1) {
                if  (l + 2 == r - 1) sig = 1;
                ans[++tot] = s[l + 2];
                l +=2 ;
                r --;
                continue;
            } else
            if (s[l + 2] == s[r - 2] && l + 2 <= r - 2) {
                if  (l + 2 == r - 2) sig = 1;
                ans[++tot] = s[l + 2];
                l +=2 ;
                r -= 2;
                continue;
            }
        break;
    }
    int sum = tot * 2 - sig;
    if (sum < n / 2) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 1; i <= tot; i ++)
        printf("%c", ans[i]);
    if (sig) {
        for (int i = tot - 1; i >= 1; i --)
            printf("%c",ans[i]);
    }else
        for (int i = tot ; i >= 1; i --)
            printf("%c", ans[i]);
    return 0;
}