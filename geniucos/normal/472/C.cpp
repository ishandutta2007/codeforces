#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int n, dp[100009][2], p[100009];
char a[100009][53], b[100009][53];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

bool CMP(char a[], char b[])
{
    int i, n1, n2;
    n1=strlen(a+1);
    n2=strlen(b+1);
    for (i=1; i<=n1&&i<=n2; i++)
        if (a[i]!=b[i])
        {
            return a[i]<b[i];
        }
    return (n1<n2);
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &n);
for (int i=1; i<=n; i++)
    scanf ("%s %s\n", a[i]+1, b[i]+1);
for (int i=1; i<=n; i++)
    scanf ("%d", &p[i]);
dp[0][0]=dp[0][1]=1;
for (int i=1; i<=n; i++)
{
    if (CMP(a[p[i-1]], a[p[i]]) && dp[i-1][0]) dp[i][0]=1;
    else
    if (CMP(b[p[i-1]], a[p[i]]) && dp[i-1][1]) dp[i][0]=1;

    if (CMP(a[p[i-1]], b[p[i]]) && dp[i-1][0]) dp[i][1]=1;
    else
    if (CMP(b[p[i-1]], b[p[i]]) && dp[i-1][1]) dp[i][1]=1;
}
if (dp[n][0]||dp[n][1]) printf ("YES\n");
else printf ("NO\n");
return 0;
}