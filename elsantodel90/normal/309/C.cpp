#include <cstdio>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)

const int MAXN = 1100000;
const int MAXS = 30;

int a[MAXN], bc[MAXS];
vector<int> b[MAXS];

int main()
{
    int n,m; scanf("%d%d", &n, &m);
    forn(i,n) scanf("%d", &a[i]);
    forn(i, MAXS) bc[i] = 0;
    forn(i,m)
    {
        int x;
        scanf("%d",&x);
        bc[x]++;
    }
    int ret = 0;
    forn(s, MAXS)
    {
        int T = 0;
        forn(i,n) { T += a[i] % 2; a[i] /= 2; }
        int k = 0;
        forn(i, bc[s]) b[s].push_back(1);
        while (T > 0 && k < (int)b[s].size())
        {
            ret += b[s][k];
            k++;
            T--;
        }
        while (k < (int)b[s].size())
        {
            if (k+1 < (int)b[s].size())
                b[s+1].push_back(b[s][k] + b[s][k+1]);
            else
                b[s+1].push_back(b[s][k]);
            k += 2;
        }
    }
    printf("%d\n",ret);
    return 0;
}