#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, ans[1<<25], x;
pair<int, int> pots[] = {{3, 1}, {7, 1}, {15, 5}, {31, 1}, {63, 21}, {127, 1}, {255, 85}, {511, 73}, {1023, 341}, {2047, 89}, {4095, 1365}, {8191, 1}, {16383, 5461}, {32767, 4681}, {65535, 21845}, {131071, 1}, {262143, 87381}, {524287, 1}, {1048575, 349525}, {2097151, 299593}, {4194303, 1398101}, {8388607, 178481}, {16777215, 5592405}, {33554431, 1082401}};

int main() {
    for(int i = 2, j = 3; i < (1 << 25); i++) {
        if(i == j) j = 2*j + 1;
        else ans[i] = j;
    }

    for(int i = 0; i < 24; i++) {
        ans[pots[i].first] = pots[i].second;
    }

    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}