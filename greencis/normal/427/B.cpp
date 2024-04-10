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
using namespace std;

int n,t,c,a[200005];
long long res;

int main()
{
    scanf("%d%d%d",&n,&t,&c);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    bool refresh = true;
    int idx = 0;
    while (idx < n) {
        if (refresh) {
            if (idx > n-c) break;
            refresh = false;
            bool good = true;
            int bi = -1;
            for (int i = idx; i < idx + c; ++i) {
                if (a[i] > t) {
                    good = false;
                    bi = i;
                    break;
                }
            }
            if (good) ++res, idx += c;
            else {
                refresh = true;
                idx = bi + 1;
            }
        } else {
            if (a[idx] > t) {
                ++idx;
                refresh = true;
            } else {
                ++idx;
                ++res;
            }
        }
    }

    cout << res;
    return 0;
}