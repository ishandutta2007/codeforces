#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
const int N = 1e6;
int T;
char s[N], t[N], p[N];
int sums[26], sumt[26], sump[26];
int main()
{
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        scanf("%s", t);
        scanf("%s", p);
        memset(sums, 0, sizeof(sums));
        memset(sumt, 0, sizeof(sumt));
        memset(sump, 0, sizeof(sump));
        for (int i = 0; i < strlen(s); i ++)
            sums[s[i] - 'a'] ++;

        for (int i = 0; i < strlen(t); i ++)
            sumt[t[i] - 'a'] ++;

        for (int i = 0; i < strlen(p); i ++)
            sump[p[i] - 'a'] ++;
        int l = 0;
        bool sig = 1;
        for (int i = 0; i < strlen(s); i ++) {
            while (l < strlen(t) && t[l] != s[i]) ++l;
            if (l == strlen(t)) sig = 0;
            else
                l ++;
        }
        for (int i = 0; i < 26; i ++)
            sig &= (sums[i] + sump[i] >= sumt[i] );

        sig?printf("YES\n"):printf("NO\n");
    }
    return 0;
}