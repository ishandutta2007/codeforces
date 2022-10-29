#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
using namespace std;
const int N = 1e6;
namespace xor_permutation{//0~2^k-1 xor
    const int N = 1<<20;
    int a[N], b[N], f[N];
    int ind[N];
    void fix(int x, int y) {
        if (f[x] == (a[x] ^ b[x])) {
            return;
        }
        if (f[x] == (a[x] ^ b[y])) {
            swap(b[y], b[x]);
            swap(ind[b[x]], ind[b[y]]);
            return;
        }
        if (f[x] == (a[y] ^ b[y])) {
            swap(a[x], a[y]);
            swap(b[x], b[y]);
            swap(ind[b[x]], ind[b[y]]);
            return;
        }
        if (f[x] == (a[y] ^ b[x])) {
            swap(a[x], a[y]);
            return;
        }
        int z = ind[f[x] ^ a[x]];
        swap(b[z], b[x]);
        swap(ind[b[z]], ind[b[x]]);
        swap(a[y], a[z]);
        fix(z, y);
    }
    bool work(int * c, int k){
        int all = 0;
        for (int i = 0; i < (1 << k);i++)
        {
            a[i] = b[i] = ind[i] = i;
            f[i] = 0;
            all ^= c[i];
        }
        if (all) return 0;
        for (int i = 0; i < (1 << k) - 1; i ++)
        {
            f[i + 1] ^= (f[i] ^ c[i]);
            f[i] = c[i];
            fix(i, i + 1);
        }
        return 1;
    }
}
int a[1000000];
int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < (1 << k) ; i ++){
        scanf("%d", &a[i]);
    }
    bool isans = xor_permutation::work(a, k);
    if (isans){
        printf("Shi\n");
        for (int i =0 ;i  < (1 << k) ; i ++)
            printf("%d ", xor_permutation::a[i]);
        printf("\n");
        for (int i =0 ;i  < (1 << k) ; i ++)
            printf("%d ", xor_permutation::b[i]);
        printf("\n");
    } else printf("Fou");
    return 0;
}