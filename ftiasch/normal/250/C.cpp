#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100000;

int n, m, a[N], s[N];
vector <int> indices[N];

int find_next(int i, int k) {
    vector <int> &v = indices[k];
    vector <int> :: iterator iter = lower_bound(v.begin(), v.end(), i);
    if (iter == v.end()) {
        return n;
    }
    return *iter;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        indices[-- a[i]].push_back(i);
    }
    s[n - 1] = 0;
    for (int i = n - 2; i >= 0; -- i) {
        s[i] = s[i + 1] + (a[i] != a[i + 1]);
    }
    int answer = INT_MAX;
    int index_id;
    for (int j = 0; j < m; ++ j) {
        int now = 0;
        int i = 0;
        while (i < n && a[i] == j) {
            i ++;
        }
        while (i < n) {
            int k = find_next(i, j);
            now += s[i] - s[k - 1];
            i = k - 1;
            while (k < n && a[k] == j) {
                k ++;
            }
            if (k < n) {
                now += a[i] != a[k];
            }
            i = k;
        }
        if (now < answer) {
            answer = now;
            index_id = j + 1;
        }
    }
    printf("%d\n", index_id);
    return 0;
}