#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int a[100000], b[100000];
multiset<int> s;
int t[100000], t1[100000];
int p[100001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        s.insert(a[i]);
        p[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        t[i] = n - 1 + p[b[i]];
        t1[i] = n - 1 - p[b[i]];
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", t[i], t1[i]);
    }
    return 0;
}