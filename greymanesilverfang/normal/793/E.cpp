#include <stdio.h>
using namespace std;
const int MAX_N = 5e3 + 5;

bool chk[MAX_N] = {true}, chkAB[MAX_N] = {true}, chkCD[MAX_N] = {true};
int par[MAX_N], h[MAX_N] = {}, w[MAX_N] = {}, label[MAX_N] = {};

int main() {
    int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &par[i]);
        h[i] = h[par[i]] + 1;
    }
    for (int i = n; i >= 2; --i)
        w[par[i]] += w[i] += w[i] == 0;
    if (w[1] & 1) {
        printf("NO");
        return 0;
    }
    int X = (w[1] >> 1) - 1, Y = (w[1] >> 1) - 1;
    for (int i = a; i != 1; i = par[i])
        label[i] = a;
    for (int i = b; i != 1; i = par[i])
        label[i] = b;
    for (int i = c; i != 1; i = par[i])
        label[i] = c;
    for (int i = d; i != 1; i = par[i])
        label[i] = d;
    for (int i = 2; i < n; ++i) {
        if (par[i] == 1) {
            if (label[i] == 0) {
                for (int j = n - w[i]; j >= 0; --j)
                    if (chk[j]) chk[j + w[i]] = true;
            } else if (label[i] == b) Y -= w[i];
              else if (label[i] == c) X -= w[i];
        } else if (label[par[i]] == a || label[par[i]] == b) {
            for (int j = n - w[i]; j >= 0; --j)
                if (chkAB[j]) chkAB[j + w[i]] = true;
        } else if (label[par[i]] == c || label[par[i]] == d) {
            for (int j = n - w[i]; j >= 0; --j)
                if (chkCD[j]) chkCD[j + w[i]] = true;
        }
    }
    if (X < 0 || Y < 0) {
        printf("NO");
        return 0;
    }
    bool AB = false, CD = false;
    for (int i = 0; i <= X; ++i)
        if (chk[i] && chkAB[X - i])
            AB = true;
    for (int i = 0; i <= Y; ++i)
        if (chk[i] && chkCD[X - i])
            CD = true;
    printf("%s", AB && CD ? "YES" : "NO");
    return 0;
}