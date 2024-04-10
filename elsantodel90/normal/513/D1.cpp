#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

typedef long long tint;
typedef pair<int,int> pint;

const int MAXN = 1100000;

vector<int> l[MAXN], r[MAXN];

int TP = 0;
int tree[MAXN];

int n;

// Si es <= maxLeft, tiene que ser un descendiente por izquierda necesariamente
// El arbol se extiende al menos hasta treeLowerBound
// go devuelve el primero AFUERA del arbol.
int go(int root, int treeLowerBound)
{
    // Ir a los izquierdos
    int maxLeft = root;
    forall(c, l[root]) if (*c > maxLeft) maxLeft = *c;
    if (maxLeft > treeLowerBound) treeLowerBound = maxLeft;
    forall(c, r[root]) if (*c > treeLowerBound) treeLowerBound = *c;
    if (maxLeft > root)
    {
        maxLeft = go(root+1, maxLeft);
        if (maxLeft == -1) return -1;
    }
    else
        maxLeft = root+1;
    // Aca maxLeft tiene lo que viene a ser el primer right (todo right ha de ser >= maxLeft).
    tree[TP++] = root;
    // Ir a los derechos
    forall(c, r[root]) if (*c < maxLeft) return -1;
    if (maxLeft <= treeLowerBound)
        return go(maxLeft, treeLowerBound);
    else
        return maxLeft;
}

int main()
{   
    #ifdef ACMTUYO
        freopen("d.in","r",stdin);
    #endif
    int c; scanf("%d%d", &n,&c);
    bool palante = true;
    forn(i,c)
    {
        int a,b; char s[16];
        scanf("%d %d %s", &a, &b, s);
        a--; b--;
        if (a >= b) palante = false;
        if (strcmp(s, "LEFT") == 0)
            l[a].push_back(b);
        else
            r[a].push_back(b);
    }
    if (palante && go(0,n-1) >= 0)
    {
        forn(i,n)
        {
            if (i) printf(" ");
            printf("%d", tree[i]+1);
        }
        printf("\n");
    }
    else
        printf("IMPOSSIBLE\n");
    return 0;
}