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

int N, M, a[200009];
char sir[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1);
N = strlen (sir + 1);

scanf ("%d", &M);
while (M)
{
    M --;
    int x;
    scanf ("%d", &x);
    a[x] ^= 1;
}
for (int i=1; i<=N / 2; i++)
{
    a[i] ^= a[i-1];
    if (a[i])
        swap (sir[i], sir[N-i+1]);
}
printf ("%s\n", sir + 1);

return 0;
}