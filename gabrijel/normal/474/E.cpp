#include <bits/stdc++.h>
using namespace std;

const long long int inf = 1e18;
const int maxn = 100100;
const int offset = (1<<18);

int n, d;
vector <long long int> st, so;
vector <int> rj, ispis;
long long int najm = inf, najv = 0;
long long int zadnji = inf;
int maksrj = 0;

struct tournament
{
    int maks [offset * 2];
    void update(int cvor, int vr)
    {
        maks [cvor] = vr;
        cvor /= 2;
        while (cvor)
        {
            maks [cvor] = max(maks [cvor * 2], maks [cvor * 2 + 1]);
            cvor /= 2;
        }
        return;
    }
    int get(int cvor, int a, int b, int l, int r)
    {
        //cout << a << " " << b << endl;
        if (l > b || r < a) return 0;
        if (l >= a && r <= b) return maks [cvor];
        int mid = (l + r) / 2;
        return max(get(cvor * 2, a, b, l, mid), get(cvor * 2 + 1, a, b, mid + 1, r));
    }
};

tournament T;

int main()
{
    long long int x;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        st.push_back(x);
    }
    so = st;
    sort(so.begin(), so.end());
    so.erase(unique(so.begin(), so.end()), so.end());
    for (int i = 0; i < (int) so.size(); i++)
    {
        najm = min(najm, so [i]);
        najv = max(najv, so [i]);
    }

    for (int i = 0; i < (int) st.size(); i++)
    {
        long long int tr = st [i];
        long long int manji = tr - (long long) d, veci = tr + (long long) d;
        int trrj = 0, ind;
        if (manji >= najm)
        {
            ind = (upper_bound(so.begin(), so.end(), manji) - so.begin()) - 1;
            trrj = max(trrj, T.get(1, 0, ind, 0, offset - 1));
        }
        if (veci <= najv)
        {
            ind = (lower_bound(so.begin(), so.end(), veci) - so.begin());
            trrj = max(trrj, T.get(1, ind, offset - 1, 0, offset - 1));
        }
        T.update(lower_bound(so.begin(), so.end(), st [i]) - so.begin() + offset, trrj + 1);
        //cout << trrj + 1 << endl;
        maksrj = max(maksrj, trrj + 1);
        rj.push_back(trrj + 1);
    }
    printf("%d\n", maksrj);
    for (int i = (int) rj.size() - 1; i >= 0; i--)
    {
        if (!maksrj) break;
        if (rj [i] == maksrj)
        {
            if (abs(zadnji - st [i]) >= (long long) d)
            {
                zadnji = st [i];
                ispis.push_back(i);
                maksrj--;
            }
        }
    }
    reverse(ispis.begin(), ispis.end());
    for (int i = 0; i < (int) ispis.size(); i++)
    {
        printf("%d ", ispis [i] + 1);
    }
    return 0;
}