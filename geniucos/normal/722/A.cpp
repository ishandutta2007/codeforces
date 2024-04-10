#include<bits/stdc++.h>

using namespace std;

char sir[6];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int type, a, b, c, d, A, B, C, D, mini;
scanf ("%d\n", &type);
gets (sir + 1);
a = sir[1] - '0', b = sir[2] - '0', c = sir[4] - '0', d = sir[5] - '0';
int st = 0, dr = 23;
if (type == 12) st = 1, dr = 12;
for (int i=st; i<=dr; i++)
    for (int j=0; j<60; j++)
    {
        int curr = ((i / 10) != a) + ((i % 10) != b) + ((j / 10) != c) + ((j % 10) != d);
        if (curr < mini || i + j == st) mini = curr, A = i / 10, B = i % 10, C = j / 10, D = j % 10;
    }
printf ("%d%d:%d%d\n", A, B, C, D);
return 0;
}