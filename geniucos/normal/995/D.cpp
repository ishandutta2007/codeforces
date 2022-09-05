#include<bits/stdc++.h>

using namespace std;

int N, Q, a[(1 << 19) + 1];
long double sum = 0.0;

void print ()
{
    cout << setprecision (15) << (long double) 1.0 * sum / (1 << N) << '\n';
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q);
for (int i=0; i<(1 << N); i++)
    scanf ("%d", &a[i]), sum += a[i];
print ();
while (Q --)
{
    int pos, val;
    scanf ("%d %d", &pos, &val);
    sum += val - a[pos], a[pos] = val;
    print ();
}
return 0;
}