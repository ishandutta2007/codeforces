#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, Q;

set < int > a, b;
multiset < int > best1, best2;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &Q);

a.insert (0);
a.insert (N);

b.insert (0);
b.insert (M);

best1.insert (N);
best2.insert (M);

while (Q)
{
    Q --;
    char tip;
    int v;
    scanf ("%c %d\n", &tip, &v);
    if (tip == 'V')
    {
        if (a.find (v) != a.end()) ;
        else
        {
            a.insert (v);
            set < int > :: iterator it1, it2;
            it1 = it2 = a.find (v);
            it1 --;
            it2 ++;
            best1.erase (best1.find (*it2 - *it1));
            best1.insert (*it2 - v);
            best1.insert (v - *it1);
        }
    }
    else
    {
        if (b.find (v) != b.end()) ;
        else
        {
            b.insert (v);
            set < int > :: iterator it1, it2;
            it1 = it2 = b.find (v);
            it1 --;
            it2 ++;
            best2.erase (best2.find (*it2 - *it1));
            best2.insert (*it2 - v);
            best2.insert (v - *it1);
        }
    }
    int l, L;
    l = *best1.rbegin ();
    L = *best2.rbegin ();
    printf ("%I64d\n", (long long) 1LL * l * L);
}

return 0;
}