#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6;
int n;
int a[N];
bool work() {
    int sum = 0;
    for (int i= 1; i <= n; i ++)
        sum ^= a[i];
    if ((sum & 1) != (n & 1)) return 0;
    vector<int>d;
    for (int i = 1; i < n; i ++)
        if (!a[i]) {
            a[i] ^= 1;
            a[i +1] ^= 1;
            d.push_back(i);
        }
    printf("%d\n", d.size());
    for (auto u:d)
        printf("%d ", u);
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1;i  <= n; i ++) {
        char c;
        scanf(" %c", &c);
        a[i] = (c == 'B');
    }
    if (work()) return 0;
    for (int i = 1; i <= n ; i++)
        a[i] ^= 1;
    if (work()) return 0;
    printf("-1\n");
    return 0;
}