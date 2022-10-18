#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;

long long n,a[300005],res[300005];

struct entry {
    long long val;
    int idx;
} e[300005];

int comp(entry a, entry b) {
    return a.val < b.val;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> e[i].val;
        e[i].idx = i;
    }

    sort(e,e+n,comp);
    res[e[0].idx] = e[0].val;
    for (int i = 1; i < n; ++i)
        res[e[i].idx] = max(e[i].val, res[e[i - 1].idx] + 1);

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";

    return 0;
}