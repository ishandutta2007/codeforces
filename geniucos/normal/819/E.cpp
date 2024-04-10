#include<bits/stdc++.h>

using namespace std;

vector < vector < int > > ans;

void add3 (int a, int b, int c) {ans.push_back ({a, b, c});}
void add4 (int a, int b, int c, int d) {ans.push_back ({a, b, c, d});}

void solve (int N)
{
    if (N == 3) add3 (1, 2, 3), add3 (1, 2, 3);
    else
    if (N == 4) add3 (1, 2, 3), add3 (1, 2, 4), add3 (1, 3, 4), add3 (2, 3, 4);
    if (N <= 4) return ;
    solve (N - 2);
    int s = N, t = N - 1;
    for (int i=1; i<=N - 3; i++)
        add4 (s, i, t, i + 1);
    add3 (s, N - 2, t), add3 (s, 1, t);
}

void print ()
{
    printf ("%d", ans.size ());
    for (auto v : ans)
    {
        printf ("\n%d ", v.size ());
        for (auto it : v)
            printf ("%d ", it);
    }
}

int main ()
{
int N;
scanf ("%d", &N);
solve (N);
print ();
return 0;
}