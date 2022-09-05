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

int N, t[10], w[10], a, b;

double mod (double x)
{
    if (x < 0) return -x;
    return x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=1; i<=5; i++)
    scanf ("%d", &t[i]);
for (int i=1; i<=5; i++)
    scanf ("%d", &w[i]);
scanf ("%d %d", &a, &b);
double val = 100.0 * a - 50.0 * b;
for (int i=1; i<=5; i++)
{
    double x = i * 500.0;
    double curr = x - (double) x * t[i] / 250.0 - 50.0 * w[i];
    if (0.3 * x > curr) curr = 0.3 * x;
    val += curr;
}
/*int sol = (int) val, pos, mini = 10000.0;
for (int i=sol - 2; i<=sol + 2; i++)
    if (mod ((double) i - val) < mini)
        mini = mod ((double) i - val), pos = i;
printf ("%d\n", pos);*/
printf ("%.lf\n", val);

return 0;
}