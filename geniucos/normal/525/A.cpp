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

int nr, N, ap[300];
char sir[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
N --;
for (int i=1; i<=N; i++)
{
    ap[sir[2 * i - 1]] ++;
    if (ap[sir[2*i]+'a'-'A'] == 0)
        nr ++;
    else
        ap[sir[2*i]+'a'-'A'] --;
}
printf ("%d\n", nr);

return 0;
}