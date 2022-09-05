#include<bits/stdc++.h>

using namespace std;

int N, suf[10009][5];
char sir[10009];
vector < string > ans;

void Print ()
{
    sort (ans.begin (), ans.end ());
    ans.erase (unique (ans.begin (), ans.end ()), ans.end ());
    printf ("%d\n", ans.size ());
    for (vector < string > :: iterator it = ans.begin (); it != ans.end (); it ++)
        printf ("%s\n", (*it).c_str ());
}

bool diff (int a, int b, int i, int j)
{
    if (j - i + 1 != b - a + 1) return 1;
    for (int k=0; k<=b - a; k++)
        if (sir[i + k] != sir[a + k]) return 1;
    return 0;
}

void add (int st, int dr)
{
    string curr;
    for (int i=st; i<=dr; i++)
        curr.push_back (sir[i]);
    ans.push_back (curr);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);

for (int i=N - 1; i>=1; i--)
    for (int j=2; j<=3; j++)
    if (i + j - 1 <= N)
    {
        if (i + j - 1 == N) suf[i][j] = 1;
        else
        {
            for (int k=2; k<=3; k++)
                if (i + j + k - 1 <= N && suf[i + j][k] && diff (i, i + j - 1, i + j, i + j + k - 1))
                    suf[i][j] = 1;
        }
    }
for (int i=6; i<=N - 1; i++)
    for (int j=2; j<=3; j++)
        if (i + j - 1 <= N && suf[i][j])
            add (i, i + j - 1);
Print ();
return 0;
}