#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
namespace LinearBasis{
    unsigned long long d[64];
    int tot = 0;
    void clear(){
        tot = 0;
        memset(d, 0, sizeof(d));
    }
    bool insert(unsigned long long x){
        for (int i = 0; i < tot; i ++)
            if ((d[i] ^ x) < x)
                x ^= d[i];
        if (x) {
            d[tot++] = x;
            sort(d, d + tot, [](int x, int y){
                return x > y;
            });
            return 1;
        } else
            return 0;
    }
};
const int N = 2e5 + 10;
int a[N];
int n;
vector<int>d;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), a[i] ^= a[i - 1];
    if (!a[n]) {
        puts("-1");
        return 0;
    }
    int sig = 1;
    d.push_back(0);
    while (sig) {
        sig = 0;
        int l = d[d.size() - 1];
        for (int i = l + 1; i <= n - 1; i ++) {
            LinearBasis::clear();
            d.push_back(i);
            d.push_back(n);
            bool tag = 1;
            for (int j = 1; j < d.size() && tag; j ++) {
                tag &= LinearBasis::insert(a[d[j]] ^ a[d[j - 1]]);
            }
            if (!tag) {
                d.pop_back();
                d.pop_back();
                continue;
            }
            if (tag) {
                d.pop_back();
                sig = 1;
                break;
            }
        }
    }
    printf("%d\n", d.size());
    return 0;
}