#include<bits/stdc++.h>

using namespace std;

int N, through[30], nxt[30], prv[30], ever[30], ap[30];
char sir[100009];

void giveUp ()
{
    printf ("NO\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=0; i<26; i++)
    nxt[i] = prv[i] = -1;
for (int i=1; i<=N; i++)
{
    int l;
    gets (sir + 1), l = strlen (sir + 1);
    for (int j=1; j<=l; j++)
        sir[j] -= 'a';
    for (int j=1; j<l; j++)
    {
        if (nxt[sir[j]] != sir[j + 1] && nxt[sir[j]] != -1) giveUp ();
        else nxt[sir[j]] = sir[j + 1];
        if (ap[sir[j]]) giveUp ();
        ap[sir[j]] = 1;
    }
    for (int j=l; j>1; j--)
    {
        if (prv[sir[j]] != sir[j - 1] && prv[sir[j]] != -1) giveUp ();
        else prv[sir[j]] = sir[j - 1];
    }
    if (ap[sir[l]]) giveUp ();
    for (int j=1; j<=l; j++)
        ap[sir[j]] = 0;
    for (int j=1; j<=l; j++)
        ever[sir[j]] = 1;
}
vector < string > ans;
for (int i=0; i<26; i++)
    if (ever[i] && prv[i] == -1)
    {
        string curr;
        int j = i;
        while (j != -1)
            curr.push_back ('a' + j), through[j] = 1, j = nxt[j];
        ans.push_back (curr);
    }
for (int i=0; i<26; i++)
    if (through[i] == 0 && ever[i] == 1) giveUp ();
sort (ans.begin (), ans.end ());
for (auto s : ans)
    printf ("%s", s.c_str ());
printf ("\n");
return 0;
}