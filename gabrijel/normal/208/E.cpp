#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
const int logn = 18;

int n, m, v, p;
vector <vector <int> > graf;
vector <int> vi;
int lca [logn] [maxn];
int depth [maxn];
int poz [maxn];
vector <vector <int> > dub;

void rek(int cvor, int dubina, int rod)
{
    lca [0] [cvor] = rod;
    depth [cvor] = dubina;
    dub [dubina].push_back(cvor);
    poz [cvor] = dub [dubina].size() - 1;
    for (int j = 0; j < graf [cvor].size(); j++)
    {
        rek(graf [cvor] [j], dubina + 1, cvor);
    }
    return;
}

inline int getp(int cv, int koji)
{
    int ret = cv;
    int pp = koji, pot = 0;
    while(pp)
    {
        if (pp & 1) ret = lca [pot] [ret];
        pot++;
        pp >>= 1;
    }
    return ret;
}

int main()
{
    memset(lca, -1, sizeof lca);
    int x;
    scanf("%d", &n);
    graf.insert(graf.begin(), n, vi);
    dub.insert(dub.begin(), n, vi);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        x--;
        if (x == -1) {vi.push_back(i); continue;}
        graf [x].push_back(i);
    }
    for (int i = 0; i < vi.size(); i++)
    {
        rek(vi [i], 0, -1);
    }
    for (int i = 1; i < logn; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lca [i] [j] = (lca [i - 1] [j] == -1) ? -1 : lca [i - 1] [lca [i - 1] [j]];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &v, &p);
        v--;
        int rod = getp(v, p);
        if (rod == -1) {printf("0 "); continue;}
        int lg, rg;
        int l, r, mid;
        int trdub = depth [v];
        l = 0;
        r = poz [v];
        while (l < r)
        {
            mid = (l + r) / 2;
            if (rod == getp(dub [trdub] [mid], p))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        lg = l;
        l = poz [v];
        r = dub [trdub].size() - 1;
        while (l < r)
        {
            mid = (l + r) / 2 + (l + r) % 2;
            if (rod == getp(dub [trdub] [mid], p))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        rg = l;
        printf("%d ", rg - lg);
    }
    return 0;
}