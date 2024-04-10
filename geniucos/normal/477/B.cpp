#include<cstdio>
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

int N, K;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
printf ("%d\n", (6 * N - 1) * K);

for (int i=0; i<N; i++)
{
    int a, b, c, d;
    a = 6 * i + 1, b = 6 * i + 2, c = 6 * i + 3, d = 6 * i + 5;
    a *= K, b *= K, c *= K, d *= K;
    printf ("%d %d %d %d\n", a, b, c, d);
}

return 0;
}