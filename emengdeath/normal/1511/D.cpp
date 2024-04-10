#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int n, k;
int main() {
    scanf("%d %d", &n, &k);
    vector<int> d;
    for (int i = 1; i <= k; i ++) {
        d.push_back(i);
        for (int j = i + 1; j <= k; j ++)
            d.push_back(i), d.push_back(j);
    }
    for (int i = 0; i < n; i ++)
        printf("%c", d[i % d.size()] + 'a' - 1);
    printf("\n");
    return 0;
}