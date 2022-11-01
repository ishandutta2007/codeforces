#include <bits/stdc++.h>
using namespace std;

int q;
vector <long long int> suma;

int main()
{
    int sta, tko, maks = 0;
    int l, r, mid;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &sta);
        if (sta == 1)
        {
            scanf("%d", &tko);
            if (tko > maks) maks = tko;
            if (!suma.size()) suma.push_back(tko);
            else suma.push_back(suma.back() + tko);
        }
        else
        {
            l = 0; r = suma.size() - 2;
            while (l < r)
            {
                mid = (r + l) / 2 + (r + l) % 2;
                if ((double) (suma [mid - 1] + maks) / (mid + 1) < (double) (suma [mid] + maks) / (mid + 2)) r = mid - 1;
                else l = mid;
            }
            if (suma.size() == 1) printf("%lf\n", (double) 0);
            else if (suma.size() == 2) printf("%lf\n", maks - (double) (maks + suma [0]) / 2);
            else printf("%lf\n", (double) maks - (suma [l] + (double) ((l == suma.size() - 1) ? 0 : maks)) / (l + ((l == suma.size() - 1) ? 1 : 2)));
        }
    }
    return 0;
}