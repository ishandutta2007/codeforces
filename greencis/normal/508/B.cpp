#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

char s[100105];
int n;

int main()
{
    scanf("%s",s);
    n = strlen(s);
    bool was_cot = false;
    int last_idx = -1;
    for (int i = 0; i < n; ++i) {
        if ((s[i] - 48) % 2 == 0) { was_cot = true, last_idx = i;
            if (s[i] < s[n-1]) { swap(s[i], s[n-1]); printf("%s",s); return 0; }
        }
    }
    if (!was_cot) printf("-1");
    else {
        swap(
             s[last_idx], s[n-1]);
            printf("%s",s);
    }

    return 0;
}