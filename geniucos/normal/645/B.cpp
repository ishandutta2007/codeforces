#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, K, a[100009], aib[100009];

void U (int pos) {while (pos <= N) aib[pos] ++ , pos += pos - (pos & (pos - 1));}
int Q (int pos) {int sum = 0; while (pos) sum += aib[pos], pos &= pos - 1; return sum;}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    a[i] = i;
for (int i=1; i<=N / 2 && i <= K; i++)
    swap (a[N + 1 - i], a[i]);
long long ans = 0;
for (int i=1; i<=N; i++)
    ans += i - 1 - Q (a[i]), U (a[i]);
printf ("%I64d\n", ans);
return 0;
}