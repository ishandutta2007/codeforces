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

int N, sol;
char sir[100009];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int get (char c)
{
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'L') return 2;
    return 3;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
    sir[i]= get(sir[i]);
for (int i=1;i<=N;i++)
{
    int x=0,y=0;
    for(int j=i;j<=N;j++)
    {
        x+=dx[sir[j]], y+=dy[sir[j]];
        if(x==0&&y==0) sol++;
    }
}
printf ("%d\n", sol);

return 0;
}