#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int i, n;
bool cr[1000009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d", &n);

for (int i=2; i<=1000; i++)
    if (cr[i]==0)
    {
        for (int j=i*i; j<=1000 *1000; j+=i)
            cr[j]=1;
    }
cr[1]=0;

for (int i=1; i<n; i++)
    if (cr[i]==1&&cr[n-i] == 1)
    {
        printf ("%d %d\n", i, n-i);
        return 0;
    }

return 0;
}