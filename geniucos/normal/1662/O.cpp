#include<bits/stdc++.h>

using namespace std;

int nr, code[22][362], t[10000];
bool edg1[22][362], edg2[22][362];

int tata(int i) {
    if (t[i] == i) return i;
    return t[i] = tata(t[i]);
}

void unite(int i, int j) {
    i = tata(i), j = tata(j);
    if (i != j)
        t[i] = j;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

nr = 1;
for (int j=0; j<360; j++)
    code[0][j] = nr;
for (int i=1; i<20; i++)
    for (int j=0; j<360; j++)
        code[i][j] = ++nr;
nr ++;
for (int j=0; j<360; j++)
    code[20][j] = nr;
int tests, testId = 0;
scanf ("%d", &tests);
while (tests --)
{
    for (int i=0; i<20; i++)
        for (int j=0; j<360; j++)
            edg1[i][j] = 0;
    for (int i=0; i<=20; i++)
        for (int j=0; j<360; j++)
            edg2[i][j] = 0;
    int M;
    scanf ("%d\n", &M);
    while (M --) {
        char type;
        scanf ("%c", &type);
        if (type == 'C') {
            int r, teta1, teta2;
            scanf ("%d %d %d\n", &r, &teta1, &teta2);
            while (teta1 != teta2) {
                edg1[r - 1][teta1] = 1;
                teta1 = (teta1 + 1) % 360;
            }
        } else {
            int r1, r2, teta;
            scanf ("%d %d %d\n", &r1, &r2, &teta);
            for (int i=r1; i<r2; i++)
                edg2[i][(teta + 359) % 360] = 1;
        }
    }
    for (int i=1; i<=nr; i++)
        t[i] = i;
    for (int i=0; i<20; i++)
        for (int j=0; j<360; j++)
            if (!edg1[i][j])
                unite(code[i][j], code[i + 1][j]);
            //else
              //  printf("blocked %d,%d->%d,%d\n", i, j, i + 1, j);
    for (int i=0; i<=20; i++)
        for (int j=0; j<360; j++)
            if (!edg2[i][j])
                unite(code[i][j], code[i][(j + 1) % 360]);
            //else
              //  printf("blocked %d,%d->%d,%d\n", i, j, i, (j+1)%360);
    // if (tata(code[0][0]) == tata(code[20][0]))
    if (tata(1) == tata(nr))
        printf("YES\n");
    else
        printf("NO\n");
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/