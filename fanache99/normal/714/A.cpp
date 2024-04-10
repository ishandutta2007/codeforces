#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

long long Intersect(long long a, long long b, long long c, long long d) {
    long long answer = min(b, d) - max(a, c) + 1;
    if (answer < 0)
        answer = 0;
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long l1, r1, l2, r2, k;
    scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);
    long long answer = Intersect(l1, r1, l2, r2);
    if (k >= l1 && k <= r1 && k >= l2 && k <= r2)
        answer--;
    printf("%I64d\n", answer);
    return 0;
}