#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1000;
int n;
int a[N];
map<vector<int>, int> f;
int count(int x){
    int sum = 0;
    while (x) sum += (x & 1), x /= 2;
    return sum;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    for (int i = 0; i < (1 << 15); i ++) {
        vector<int> d(n - 1);
        int x = count((a[1] ^ i) & ((1 << 15) - 1));
        for (int j = 2; j <= n; j++)
            d[j - 2] = x - count((a[j] ^ i) & ((1 << 15) - 1));
        f[d] = i;
    }
    for (int i = 0; i < (1 << 15); i ++){
        vector<int> d(n - 1);
        int x = count(((a[1] >> 15) ^ i) & ((1 << 15) - 1));
        for (int j = 2; j <= n; j++)
            d[j - 2] = count(((a[j] >> 15) ^ i) & ((1 << 15) - 1)) - x;
        if (f.find(d) != f.end()) {
            printf("%d\n", f[d] + (i << 15));
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}