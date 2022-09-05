#include<bits/stdc++.h>

using namespace std;

void Ans (bool ok)
{
    if (ok) printf ("YES\n");
    else printf ("NO\n");
    exit (0);
}
int N, a[100009];
long long sum = 0;
set < long long > S;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), sum += a[i];
if (sum % 2) Ans (0);
sum /= 2;
long long currS = 0;
for (int i=1; i<=N; i++)
{
    currS += a[i];
    S.insert (a[i]);
    if (currS == sum) Ans (1);
    if (sum <= currS && S.find (currS - sum) != S.end ()) Ans (1);
}
S.clear (), currS = 0;
for (int i=N; i>=1; i--)
{
    currS += a[i];
    S.insert (a[i]);
    if (currS == sum) Ans (1);
    if (sum <= currS && S.find (currS - sum) != S.end ()) Ans (1);
}
Ans (0);
return 0;
}