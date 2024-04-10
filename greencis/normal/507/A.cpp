#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans, u[10000];

struct entry {
    int p, idx;
} e[10000];

int comp(entry a, entry b) {
    return a.p < b.p;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> e[i].p;
        e[i].idx = i;
    }
    sort(e,e+n,comp);
    for (int i = 0; i < n && k > 0; ++i) {
        if (e[i].p <= k) k -= e[i].p, ++ans, u[e[i].idx] = 1;
    }
    cout << ans << endl;
    for (int i = 0; i < 10000; ++i)
        if (u[i])
            cout << i+1 << " ";


    return 0;
}