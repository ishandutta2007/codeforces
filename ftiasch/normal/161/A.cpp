#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111;

int n, m, x, y, a[N], b[N];
vector <pair <int, int> > result;

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", b + i);
    }
    int i = 0;
    for (int j = 0; i < n && j < m; ++ j) {
        while (i < n && a[i] - x <= b[j] && a[i] + y < b[j]) {
            i ++;
        }
        if (i == n) {
            break;
        }
        if (a[i] - x <= b[j] && b[j] <= a[i] + y) {
            result.push_back(make_pair(i, j));
            i ++;
        }
    }
    printf("%d\n", (int)result.size());
    for (vector <pair <int, int> > :: iterator iter = result.begin(); \
            iter != result.end(); ++ iter) {
        printf("%d %d\n", iter->first + 1, iter->second + 1);
    }
    return 0;
}