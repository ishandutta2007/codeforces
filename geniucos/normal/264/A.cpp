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

int N;
char sir[1000009];

void solve (int poz)
{
    if (poz == N + 1)
        return;
    if (sir[poz] == 'r')
        printf ("%d\n", poz), solve (poz + 1);
    else
        solve (poz + 1), printf ("%d\n", poz);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1);
N = strlen (sir + 1);
solve (1);

return 0;
}