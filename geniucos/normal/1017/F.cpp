#include<bits/stdc++.h>

using namespace std;

int N;
unsigned int bigN, A, B, C, D;
unsigned char cr[(100000000 >> 3) + 50];

unsigned int ans = 0;
void addPrime (unsigned int i)
{
    unsigned int curr = i * i * i * A + i * i * B + i * C + D;
    unsigned int e = 0, j = i;
    while (1)
    {
        e += bigN / j;
        if (1LL * j * i > N) break;
        j = j * i;
    }
    ans += curr * e;
}

void addPrime2 (unsigned int &i)
{
    ans += (bigN / i) * (i * i * i * A + i * i * B + i * C + D);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int a, b, c, d;
scanf ("%d %d %d %d %d", &N, &a, &b, &c, &d);
A = a, B = b, C = c, D = d, bigN = N;
for (int i=1; 9 * i * i <= N; i++)
    if ((cr[i >> 3] & (1 << (i & 7))) == 0)
    {
        int x = 6 * (i >> 1) + 4 * (i & 1) + 1;
        for (int j=x * x; j<=N; j+=x)
        {
            int r = j % 6, pos;
            if (r == 1)
            {
                pos = 2 * (j / 6);
                cr[pos >> 3] |= 1 << (pos & 7);
            }
            else
            if (r == 5)
            {
                pos = 2 * (j / 6) + 1;
                cr[pos >> 3] |= 1 << (pos & 7);
            }
        }
    }
addPrime (2);
addPrime (3);
int i;
for (i=1; 9 * i * i <= N; i++)
    if ((cr[i >> 3] & (1 << (i & 7))) == 0)
        addPrime (6 * (i >> 1) + 4 * (i & 1) + 1);
for (; i<=100000000; i++)
    if ((cr[i >> 3] & (1 << (i & 7))) == 0)
    {
        unsigned int x = 6 * (i >> 1) + 4 * (i & 1) + 1;
        if (x > bigN) break;
        addPrime2 (x);
    }
cout << ans << '\n';
return 0;
}