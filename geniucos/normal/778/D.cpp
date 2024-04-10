#include<bits/stdc++.h>

using namespace std;

#define vpii vector < pair < int, int > >

int N, M;
char sir[59][59];

void add (int i, int j, vpii &curr)
{
    if (sir[i][j] == 'U') sir[i][j] = sir[i + 1][j] = 'L', sir[i][j + 1] = sir[i + 1][j + 1] = 'R';
    else sir[i][j] = sir[i][j + 1] = 'U', sir[i + 1][j] = sir[i + 1][j + 1] = 'D';
    curr.push_back ({i, j});
}

char wanted[2] = {'L', 'U'};
vpii solve ()
{
    vpii curr, ord;
    bool type = M % 2;
    if (M % 2 == 0)
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j+=2)
                ord.push_back ({i, j});
    else
        for (int j=1; j<=M; j++)
            for (int i=1; i<=N; i+=2)
                ord.push_back ({i, j});
    for (auto It = ord.begin (); It != ord.end (); It ++)
    {
        int i = It->first, j = It->second;
        if (sir[i][j] == wanted[type]) continue;
        bool k = type;
        vpii sqs;
        while (1)
        {
            sqs.push_back ({i, j});
            if (k == 0 && sir[i][j + 1] == 'U') break;
            if (k == 1 && sir[i + 1][j] == 'L') break;
            j += (k == 0);
            i += (k == 1);
            k ^= 1;
        }
        for (auto it = sqs.rbegin (); it != sqs.rend (); it ++)
            add (it->first, it->second, curr);
    }
    return curr;
}

void Print (vpii ans)
{
    printf ("%d\n", ans.size ());
    for (auto it = ans.begin (); it != ans.end (); it ++)
        printf ("%d %d\n", it->first, it->second);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
vpii ans = solve ();
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
vpii secondPart = solve ();
for (auto it = secondPart.rbegin(); it != secondPart.rend (); it ++)
    ans.push_back (*it);
Print (ans);
return 0;
}