#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[1000005];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        a[i] = i;
    }
    int b = 0;
    for (int i = 2; i <= N; ++i) {
        int c = a[b];
        int p = b + i;
        while (p < b + N) {
            swap(a[p < N ? p : p - N], c);
            p += i;
        }
        a[b] = c;
        ++b;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", a[b + i < N ? b + i : b + i - N] + 1);
    }
    printf("\n");

    return 0;
}