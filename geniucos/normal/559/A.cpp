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

int a1, a2, a3, a4, a5, a6;

long long get (int l)
{
    return 1LL * l * l;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);

long long sol = get (a1 + a6 + a5) - get (a1) - get (a3) - get (a5);
printf ("%I64d\n", sol);

return 0;
}