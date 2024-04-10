#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long double ld;

const int maxn = 1 << 24, maxn2 = 1 << 23;
int n, cnt[maxn], ans, curmask;
char z[5];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",z);
        ++cnt[(1 << (z[0] - 'a')) | (1 << (z[1] - 'a')) | (1 << (z[2] - 'a'))];
    }
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < maxn2; ++j) {
            curmask = ((j >> i) << (i + 1)) | (j & ((1 << i) - 1));
            cnt[curmask ^ (1 << i)] += cnt[curmask];
        }
    }
    for (int i = 0; i < maxn; ++i)
        ans ^= (n - cnt[i]) * (n - cnt[i]);
    printf("%d",ans);
}