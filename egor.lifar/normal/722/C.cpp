#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;

struct node {
    int p, h;
    long long v;
};


const int MAXN = 100228;
node cnm[MAXN];
int a[MAXN];
int p[MAXN];
bool notDeleted[MAXN];
int n;


int get_parent(int x) {
    if (cnm[x].p == -1) {
        return x;
    }
    return cnm[x].p = get_parent(cnm[x].p);
}


int setUnion(int x, int y) {
    x = get_parent(x);
    y = get_parent(y);
    if (cnm[x].h < cnm[y].h) {
        swap(x, y);
    }
    cnm[x].h = max(cnm[x].h, cnm[y].h + 1);
    cnm[y].p = x;
    return x;
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cnm[i].h = 0;
        cnm[i].p = -1;
        cnm[i].v = 0;
    }
    vector<long long> ans;
    long long ansmax = 0;
    for (int t = n - 1; t >= 0; t--) {
        int i = p[t];
        notDeleted[i] = true;
        long long b = a[i];
        int root = i;
        cnm[root].v = b;
        if (i > 0 && notDeleted[i - 1]) {
            int r = get_parent(i - 1);
            b += cnm[r].v;
            root = setUnion(root, r);
            cnm[root].v = b;
        }
        if (i < n - 1 && notDeleted[i + 1]) {
            int r = get_parent(i + 1);
            b += cnm[r].v;
            root = setUnion(root, r);
            cnm[root].v = b;
        }
        ans.push_back(ansmax);
        ansmax = max(ansmax, b);
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}