#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, ap[100009][2], a[100009];

int type1 (int st, int dr)
{
    return ap[dr][1] - ap[st-1][1];
}

int type2 (int st, int dr)
{
    return ap[dr][2] - ap[st-1][2];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    ap[i][1] = ap[i-1][1];
    ap[i][2] = ap[i-1][2];
    ap[i][a[i]] ++;
}

vector < pair < int , int > > answer;
for (int T = 1; T <= N; T++)
{
    bool ok = 1;
    int i, j, p1, p2, lst;
    i = 1;
    p1 = p2 = 0;
    while (i <= N)
    {
        int p, u, mij;
        p = i;
        u = N;
        j = N + 1;
        while (p<=u)
        {
            mij = (p + u) >> 1;
            if ( max (type1 (i, mij), type2(i, mij)) >= T)
            {
                j = mij;
                u = mij - 1;
            }
            else p = mij + 1;
        }
        if (j == N + 1)
        {
            ok = 0;
            break;
        }
        if (type1(i, j) == T)
            p1 ++, lst = 1;
        else
            p2 ++, lst = 2;
        i = j + 1;
    }

    if (ok == 1 && p1 != p2 && ((p1 > p2 && lst == 1) || (p1 < p2 && lst == 2)))
        answer.push_back (make_pair (max(p1, p2), T));
}
sort (answer.begin(), answer.end());
printf ("%d\n", answer.size());
for (int i=0; i<answer.size(); i++)
    printf ("%d %d\n", answer[i].first, answer[i].second);
return 0;
}