#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_a"

const double pi = acos(-1.0);
const int size = 30 * 1000 + 100;
const int ssize = 1000;

int ans[size][ssize];
int cnt[size];
int n, d;

int main() {
    //assert(freopen("input.txt", "r", stdin));
    ///assert(freopen("output.txt", "w", stdout));
    
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        int h;
        scanf("%d", &h);

        cnt[h]++;
    }

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < ssize; j++) {
            int jump = d + j - ssize / 2;
            ans[i][j] = cnt[i];
            for (int k = -1; k <= 1; k++) {
                if (jump + k > 0 && i + jump + k < size && j + k >= 0) {
                    ans[i][j] = max(ans[i][j], ans[i + jump + k][j + k] + cnt[i]);
                }
            }
        }
    }

    cout << ans[d][ssize / 2] << endl;

    return 0;
}