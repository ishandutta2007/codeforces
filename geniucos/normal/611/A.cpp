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

int sol, sum, N;
int cnt[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

char c;
scanf ("%d of %c", &N, &c);
int first = 5;
if (c == 'w')
{
    ///gen luni etc
    for (int i=0; i<12; i++)
        for (int j=1; j<=cnt[i]; j ++)
        {
            sol += (first == N);
            first ++;
            if (first == 8) first = 1;
        }
}
else
{
    for (int i=0; i<12; i++)
        sol += (cnt[i] >= N);
}
printf ("%d\n", sol);

return 0;
}