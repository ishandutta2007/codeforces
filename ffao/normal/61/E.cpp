#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long tree[1100000];
const int m = 1100000;

int n;
typedef pair<int, int> pii;
pair<int, int> a[1100000];

bool valsort(const pii& a, const pii& b) {
    return a.second < b.second;
}

long long read(tree t, int x) {
    long long s = 0;
    while (x > 0) {
        s += t[x];
        x -= x&-x;
    }
    return s;    
}

void update(tree t, int x, long long delta) {
    while (x <= m) {
        t[x] += delta;
        x += x&-x;
    }
}

tree first, second;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
        a[i].first = i;
    }
    sort(a, a+n, valsort);
    for (int i = 0; i < n; i++) a[i].second = n-i;
    sort(a, a+n);
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += read(second, a[i].second);
        update(second, a[i].second, read(first, a[i].second));
        update(first, a[i].second, 1);
    }
    
    cout << ans << endl;
}