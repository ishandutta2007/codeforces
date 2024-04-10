#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
long long a, b;
struct node
{
    long long x;
    int k;
}ans;
void update(long long x, int k)
{
    if (ans.x > x || (ans.x == x && ans.k > k))
    {
        ans.x = x, ans.k = k;
    }
}
long long gcd(long long x, long long y){
    return !x ? y : gcd(y % x, x);
}
long long get(long long x, long long y)
{
    return x / gcd(x, y) * y;
}
int main()
{
    scanf("%lld %lld", &a, &b);
    ans.x = 1e19;
    if (a < b) swap(a, b);
    update(get(a, b), 0);
    int v = a - b;
    for (int i = 1; (long long) i * i <= v ; i ++)
    {
        if ((v % i) == 0 ) {
            int k = (b / i * i + i) - b;
            update(get(a + k, b + k), k);
            int ii = v / i;
            k = (b / ii * ii + ii) - b;
            update(get(a + k, b + k), k);
        }
    }
    printf("%d\n", ans.k);
    return 0;
}