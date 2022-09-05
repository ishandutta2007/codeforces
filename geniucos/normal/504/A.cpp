#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>

using namespace std;

int X[100009], t[100009], nr, N, D[100009];

queue < int > cc;

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<N; i++)
{
    scanf ("%d %d", &D[i], &X[i]);
    if (D[i] == 1)
        cc.push (i);
    t[i] = -1;
}

while (!cc.empty())
{
    int nod = cc.front();
    cc.pop();

    if (D[nod] == 0) continue;

    t[nod] = X[nod];
    D[nod] --;

    D[t[nod]] --;
    X[t[nod]] ^= nod;
    if (D[t[nod]] == 1)
    {
        cc.push (t[nod]);
    }
}

for (int i=0; i<N; i++)
    if (t[i] != -1)
        nr ++;

printf ("%d\n", nr);

for (int i=0; i<N; i++)
    if (t[i] != -1)
        printf ("%d %d\n", i, t[i]);

return 0;
}