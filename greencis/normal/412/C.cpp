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

char ans[100005],cur[100005];
bool killed[100005];
int n,len;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < 100005; ++i)
        ans[i] = '?';
    while (n--) {
        scanf("%s",cur);
        len = strlen(cur);
        for (int i = 0; i < len; ++i) {
            if (!killed[i]) {
                if (cur[i] != '?') {
                    if (ans[i] == '?') {
                        ans[i] = cur[i];
                    } else {
                        if (ans[i] != cur[i]) {
                            ans[i] = '?';
                            killed[i] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < len; ++i) {
        if (killed[i]) ans[i] = '?';
        else {
            if (ans[i] == '?') ans[i] = 'a';
        }
    }
    ans[len] = 0;
    printf("%s",ans);

    return 0;
}