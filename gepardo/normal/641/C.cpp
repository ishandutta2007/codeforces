#include <cstdio>
#include <algorithm>

using namespace std;

int p1 = 0, qp1 = 0;
int n, k;
int d[3000000], e[3000000];
int u[3000000], w[3000000], t[3000000];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a; scanf("%d", &a); d[i] = a;
        if (a == 1) { 
            int x; 
            scanf("%d", &x); 
            e[i] = x; 
        }
    }
    vector<int> ops;
    for (int i = 0; i < k; i++) {
        if (d[i] == 1) {
            if (llabs(e[i]) % 2 == 1) {
                if (ops.size() == 0) {
                    ops.push_back(1);
                } else if (*ops.rbegin() == 1) {
                    ops.pop_back();
                } else {
                    ops.push_back(1);
                }
            }
        } else {
            if (ops.size() == 0) {
                ops.push_back(2);
            } else if (*ops.rbegin() == 2) {
                ops.pop_back();
            } else {
                ops.push_back(2);
            }
        }
    }
    if (ops.size() == 0) {
        for (int i = 0; i < n; i++) {
            w[i] = i;
        }
    } else {
        int sz = ops.size();
        if (ops[0] == 1) {
            sz--;
            for (int i = 0; i < n; i++) {
                w[i] = (i + 1) % n;
            }
        } else {
            for (int i = 0; i < n; i++) {
                w[i] = i;
            }
        }
        int opC = sz / 2;
        int q = (opC / 2) % (n / 2);
        for (int i = 0; i < n; i++) {
            t[i] = w[i];
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                w[i] = t[(i + opC * 2) % n];
            }
        }
        if (sz % 2 == 1) {
            for (int i = 0; i < (n / 2); i++) {
                swap(w[i * 2], w[i * 2 + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (w[i] == 0) {
            p1 = i;
        }
    }
    qp1 = 0;
    for (int i = 0; i < k; i++) {
        if (d[i] == 1) {
            qp1 = (qp1 + e[i] + n) % n;
        } else if (qp1 % 2 == 0) {
            qp1++; 
        } else { 
            qp1--;
        }
    }
    qp1 =  (qp1 + n - p1) % n;
    for (int i = 0; i < n; i++) {
        printf("%d ", w[(i + n - qp1) % n] + 1);
    }
    return 0;
}