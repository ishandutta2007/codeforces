#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct entry {
    int a,b;
} e[101005];

int comp(entry a, entry b) {
    return a.a < b.a;
}

int n,a[101005],b[101005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        e[i].a = a[i];
        e[i].b = b[i];
    }

    if (n == 1) { cout << "Poor Alex"; return 0; }

    sort(a,a+n);
    sort(b,b+n);
    sort(e,e+n,comp);

    bool good = true;
    for (int i = 0; i < n; ++i) {
        if (e[i].b != b[i]) {
            good = false;
        }
    }

    if (good)
        cout << "Poor Alex";
    else cout << "Happy Alex";

    return 0;
}