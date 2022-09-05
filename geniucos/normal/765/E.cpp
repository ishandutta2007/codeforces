#include<bits/stdc++.h>

using namespace std;

int N, cnt[200009], xo[200009], ap[200009], del[200009];
bool EndNow;
map < int, int > mp[200009];

void un (int i, int lst, int oldsz)
{
    if (EndNow) return ;
    if (ap[i] == 1) return ;
    int j = xo[i] ^ lst, nr = oldsz + 1; lst = i;
    vector < int > curr;
    curr.push_back (i);
    bool toprint = (i == 7);
    while (cnt[j] == 2)
    {
//        if (toprint)
  //          printf ("%d %d\n", lst, j);
        int aux = j;
        curr.push_back (j), j = xo[j] ^ lst, nr ++, lst = aux;
    }
    if (cnt[j] == 1)
    {
        while (nr % 2 == 0) nr /= 2;
        printf ("%d\n", nr);
        exit (0);
    }
    for (auto it = curr.begin (); it != curr.end (); it ++)
        ap[*it] = 1;
    int bf = curr[curr.size () - 1];
    if (mp[j].count (nr))
    {
        //for (auto it = curr.begin (); it != curr.end (); it ++)
          //  del[*it] = 1;
//        printf ("am unit %d %d %d\n", bf, j, mp[j][nr]);
        ///unesc il las pe ala vechi
        xo[j] ^= bf, cnt[j] --;
        if (cnt[j] == 2) un (j, mp[j][nr], nr);
    }
    else mp[j][nr] = bf;

}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    //v[x].push_back (y), v[y].push_back (x);
    cnt[x] ++, cnt[y] ++, xo[x] ^= y, xo[y] ^= x;
}
for (int i=1; i<=N; i++)
    if (cnt[i] == 1 && ap[i] == 0)
        un (i, 0, 0);
printf ("-1\n");
return 0;
}