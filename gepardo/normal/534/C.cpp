#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n, A; scanf("%I64d%I64d", &n, &A);
    vector <long long> q(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &q[i]);
        sum += q[i];
    }
    for (int i = 0; i < n; i++)
    {
        long long lRange = max(A - (sum - q[i]), 1LL);
        long long rRange = min(A - (n - 1), q[i]);
        long long res = max(rRange - lRange + 1, 0LL);
        printf("%I64d ", q[i] - res);
    }
}