#include <stdio.h>
#include <set>
#include <functional>

using namespace std;

int ans[100000];
set< pair<long long, int>, greater< pair<long long, int> > > q;

int n, m;
int op[110000][4];
long long a;

int main() {
    scanf("%d", &n);

    long long sz = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op[i][0], &op[i][1]);
        if (op[i][0] == 2) {
            scanf("%d", &op[i][2]);
            sz += op[i][1] * op[i][2];
        }
        else sz++;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%I64d", &a);
        q.insert(make_pair(a, i));
    }

    for (int i = n-1; i >= 0; i--) {
        if (op[i][0] == 1) {
            while (!q.empty() && q.begin()->first == sz) {
                ans[q.begin()->second] = op[i][1];
                q.erase(q.begin());
            }

            sz--;
        }

        else {
            long long new_sz = sz - op[i][2]*op[i][1];
            while (!q.empty() && q.begin()->first > new_sz) {
                long long new_o = ((q.begin()->first - new_sz - 1) % op[i][1]) + 1;
                q.insert(make_pair(new_o, q.begin()->second));
                q.erase(q.begin());
            }
            sz = new_sz;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", ans[i]);
    }
}