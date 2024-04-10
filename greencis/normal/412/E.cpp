#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;

char s[1001005];
int n;
long long res;

int main()
{
    scanf("%s",s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] < 'a' || s[i] > 'z') continue;
        int idx1 = i;
        int letters = 0;
        while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_') {
            if ((s[i] >= 'a' && s[i] <= 'z')) ++letters;
            ++i;
        }
        if (s[i] != '@') continue;
        ++i;
        int idx2 = i;
        while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) ++i;
        if (i - idx2 == 0 || s[i] != '.') {
            i = idx2 - 1;
            continue;
        }
        ++i;
        int idx3 = i;
        if (!(s[i] >= 'a' && s[i] <= 'z')) { --i; continue; }
        while ((s[i] >= 'a' && s[i] <= 'z')) ++i;
        res += ((long long)(letters)) * (long long)(i - idx3);
        i = idx3 - 1;
    }
    cout << res;

    return 0;
}