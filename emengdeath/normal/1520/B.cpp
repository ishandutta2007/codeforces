#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
char s[10000];
vector<int> a;
int main() {
    int T;
    for (int i = 1;i <= 9; i ++)
    {
        int x = 0;
        for (int j = 1; x + 1ll * j * i <= 1e9; j *= 10)
            x += j * i, a.push_back(x);
    }
    sort(a.begin(), a.end());
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        printf("%d\n", upper_bound(a.begin(), a.end(), n) - a.begin());
    }
    return 0;
}