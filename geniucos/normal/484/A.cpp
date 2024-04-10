#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int maxi, biti, T, i, bit[70];
long long L, R, ans, val, act, s[70][70];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
for (int i=0; i<=62; i++)
    for (int j=i; j<=62; j++)
    {
        s[i][j] = 0;
        for (int k=i; k<=j; k++)
            s[i][j] |= 1LL << k;
    }
while (T)
{
    T --;
    scanf ("%I64d %I64d", &L, &R);
    if (L == 0 && R == 0)
    {
        printf ("0\n");
        continue;
    }
    for (int i=62; i>=0; i--)
        bit[i] = ((L & (1LL << i)) > 0);

    maxi = -1;
    for (int sf = 0; sf <=62; sf++)
    {
        //// >=sf
        biti = sf;
        if (sf) act = s[0][sf-1];
        else act = 0;

        for (int i=62; i>=sf; i--)
        {
            if (act + s[sf][i-1] < L)
            {
                act |= 1LL << i;
                biti ++;
            }
        }

        val = act;

        if (val <= R)
        {
            if (biti > maxi) maxi = biti, ans = val;
            else
            if (biti == maxi && val < ans) ans = val;
        }
        ////
    }
    printf ("%I64d\n", ans);
}
return 0;
}