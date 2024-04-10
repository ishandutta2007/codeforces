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
using namespace std;

int n,a[100005],b[100005],won1[100005],won2[100005],all[200005],all_idx;

struct entry {
    int r, idx, whatList;
} e[200005];

int comp(entry a, entry b) {
    return a.r < b.r;
}

int binidx(int x, int lower, int upper, int whatMass) { // 1 - a, 2 - b
    if (whatMass == 1) {
        if (lower == upper) return lower;
        if (lower == upper - 1) {
            if (a[upper] < x)
                return upper;
            return lower;
        }
        int qi = (lower + upper) / 2;
        int q = a[qi];
        if (q == x) return x;
        if (q > x) return binidx(x, lower, qi,1);
        return binidx(x, qi, upper,1);
    }

    if (lower == upper) return lower;
    if (lower == upper - 1) {
        if (b[upper] < x)
            return upper;
        return lower;
    }
    int qi = (lower + upper) / 2;
    int q = b[qi];
    if (q == x) return x;
    if (q > x) return binidx(x, lower, qi, 2);
    return binidx(x, qi, upper,2);
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i]>>b[i];
        e[all_idx].r = a[i];
        e[all_idx].idx = i;
        e[all_idx].whatList = 1;
        ++all_idx;
        e[all_idx].r = b[i];
        e[all_idx].idx = i;
        e[all_idx].whatList = 2;
        ++all_idx;
    }

    sort(e,e+2*n,comp);

    for (int i = 0; i < n; ++i) {
        if (e[i].whatList == 1) {
            won1[e[i].idx] = 1;
        } else won2[e[i].idx] = 1;
    }

    for (int i = 0; i < n/2; ++i)
        won1[i] = won2[i] = 1;

   // for (int k = 0; k <= n/2; ++k) {
   //     for (int j = k; j < n; ++j) {
   //         if (binidx(a[j],0,n-1,2) < n-2*k) won1[j] = 1;
   //         if (binidx(b[j],0,n-1,1) < n-2*k) won2[j] = 1;
   //     }
   // }

    for (int i = 0; i < n; ++i)
        cout << won1[i];
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << won2[i];
    cout << endl;

    return 0;
}