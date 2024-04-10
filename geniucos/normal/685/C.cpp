#include<bits/stdc++.h>

using namespace std;

int T, N;
long long minA, minB, minC, minD, maxA, maxB, maxC, maxD;
bool currP;

bool mod2 (long long val) {if (val % 2 == 0) return 0; return 1;}

bool ok (long long D)
{
    if (maxA - D > minA + D) return 0;
    if (maxB - D > minB + D) return 0;
    if (maxC - D > minC + D) return 0;
    if (maxD - D > minD + D) return 0;
    ///[maxA + maxB + maxC - 3D, minA + minB + minC + 3D] N [maxD - D, minD + D]
    long long st = maxD - D, dr = minD + D;
    if (maxA + maxB + maxC > maxD + 2LL * D) st = maxA + maxB + maxC - 3LL * D;
    if (minA + minB + minC < minD - 2LL * D) dr = minA + minB + minC + 3LL * D;
    //st = max (st, maxA + maxB + maxC - 3LL * D), dr = min (dr, minA + minB + minC + 3LL * D);
    if (mod2 (st) != currP) st ++;
    if (mod2 (dr) != currP) dr --;
    if (st <= dr) return 1;
    return 0;
}

bool Ok (long long D)
{
    long long A = maxA, B = maxB, C = maxC, a = minA, b = minB, c = minC;
    if (mod2 (A + D)) maxA ++; if (mod2 (a + D)) minA --;
    if (mod2 (B + D)) maxB ++; if (mod2 (b + D)) minB --;
    if (mod2 (C + D)) maxC ++; if (mod2 (c + D)) minC --;
    currP = 0;
    if (ok (D))
    {
        maxA = A, maxB = B, maxC = C, minA = a, minB = b, minC = c;
        return 1;
    }
    maxA = A, maxB = B, maxC = C, minA = a, minB = b, minC = c, currP = 1;
    if (!mod2 (A + D)) maxA ++; if (!mod2 (a + D)) minA --;
    if (!mod2 (B + D)) maxB ++; if (!mod2 (b + D)) minB --;
    if (!mod2 (C + D)) maxC ++; if (!mod2 (c + D)) minC --;
    bool ans = ok (D);
    maxA = A, maxB = B, maxC = C, minA = a, minB = b, minC = c;
    return ans;
}

void Reconstruct (long long D)
{
    long long st = maxD - D;
    if (maxA + maxB + maxC > maxD + 2LL * D) st = maxA + maxB + maxC - 3LL * D;
    if (mod2 (st) != currP) st ++;
    long long sum = st, A, B, C;
    A = maxA - D, B = maxB - D, C = maxC - D;
    sum -= A, sum -= B, sum -= C;

    while (sum > 0)
    {
        if (minA + D - (maxA - D) <= sum) sum -= (minA + D - (maxA - D)), A = minA + D;
        else A += sum, sum = 0;
        if (mod2 (A) != currP) A --, sum ++;

        if (minB + D - (maxB - D) <= sum) sum -= (minB + D - (maxB - D)), B = minB + D;
        else B += sum, sum = 0;
        if (mod2 (B) != currP) B --, sum ++;

        if (minC + D - (maxC - D) <= sum) sum -= (minC + D - (maxC - D)), C = minC + D;
        else C += sum, sum = 0;
        if (mod2 (C) != currP) C --, sum ++;
    }

    printf ("%I64d %I64d %I64d\n", (st - A) / 2, (st - B) / 2, (st - C) / 2);
}

void Rec (long long D)
{
    long long A = maxA, B = maxB, C = maxC, a = minA, b = minB, c = minC;
    if (mod2 (A + D)) maxA ++; if (mod2 (a + D)) minA --;
    if (mod2 (B + D)) maxB ++; if (mod2 (b + D)) minB --;
    if (mod2 (C + D)) maxC ++; if (mod2 (c + D)) minC --;
    currP = 0;
    if (ok (D))
    {
        Reconstruct (D);
        return ;
    }
    maxA = A, maxB = B, maxC = C, minA = a, minB = b, minC = c, currP = 1;
    if (!mod2 (A + D)) maxA ++; if (!mod2 (a + D)) minA --;
    if (!mod2 (B + D)) maxB ++; if (!mod2 (b + D)) minB --;
    if (!mod2 (C + D)) maxC ++; if (!mod2 (c + D)) minC --;
    Reconstruct (D);
    maxA = A, maxB = B, maxC = C, minA = a, minB = b, minC = c;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
    {
        long long x, y, z, a, b, c, d;
        scanf ("%I64d %I64d %I64d", &x, &y, &z);
        a = y + z - x, b = x + z - y, c = x + y - z, d = x + y + z;
        if (i == 1) minA = maxA = a, minB = maxB = b, minC = maxC = c, minD = maxD = d;
        else
        {
            if (a < minA) minA = a;
            if (a > maxA) maxA = a;
            if (b < minB) minB = b;
            if (b > maxB) maxB = b;
            if (c < minC) minC = c;
            if (c > maxC) maxC = c;
            if (d < minD) minD = d;
            if (d > maxD) maxD = d;
        }
    }
    long long p = 0, u = 3e18, mij, ras;
    while (p <= u)
    {
        mij = p + (u - p) / 2;
        if (Ok (mij)) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
  //  printf ("%d\n", Ok (0));
    //printf ("%I64d\n", ras);
    Rec (ras);
}
return 0;
}