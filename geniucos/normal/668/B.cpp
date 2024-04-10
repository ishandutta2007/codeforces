#include<bits/stdc++.h>

using namespace std;

int N, M, A_type, B_type, A_rot, B_rot, a[1000009];

int pow (int a, int b, int mod)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
A_rot = 0, B_rot = 0, A_type = 1, B_type = 2;
while (M --)
{
    int type;
    scanf ("%d", &type);
    if (type == 2)
    {
        swap (A_type, B_type), swap (A_rot, B_rot);
        continue;
    }
    int x;
    scanf ("%d", &x), x %= N;
    if (x < 0) x += N;
    if (x % 2 == 1)
    {
        ///rotesc cu 1 si scad x-ul
        B_rot ++;
        if (B_rot == N / 2) B_rot = 0;
        swap (A_type, B_type), swap (A_rot, B_rot);
    }
    A_rot += x / 2, B_rot += x / 2;
    A_rot %= (N / 2), B_rot %= (N / 2);
}
int pos = 0;
for (int i=1; i<=N; i+=2)
{
    int val;
    if (++pos <= A_rot) val = N / 2 - A_rot + pos;
    else val = pos - A_rot;
    a[i] = (val - 1) * 2 + A_type;
}
pos = 0;
for (int i=2; i<=N; i+=2)
{
    int val;
    if (++pos <= B_rot) val = N / 2 - B_rot + pos;
    else val = pos - B_rot;
    a[i] = (val - 1) * 2 + B_type;
}
for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);
printf ("\n");
return 0;
}