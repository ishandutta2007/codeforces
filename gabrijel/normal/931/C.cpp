#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int n, a = inf, b = inf, c = inf, mini, maxi, l = 0, m = 0, r = 0, sred;
int niz [100100];
int cnt = 0;

int main()
{
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niz [i]);
        if (a == inf) {a = niz [i]; cnt++;}
        else if (a != niz [i] && b == inf) {b = niz [i]; cnt++;}
        else if (a != niz [i] && b != niz [i] && c == inf) {c = niz [i]; cnt++;};
    }
    if ((cnt < 3 && abs(a - b) < 2) || cnt < 2)
    {
        printf("%d\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", niz [i]);
        }
    }
    else if (cnt < 3)
    {
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; i++)
        {
            if (niz [i] == a) cnta++;
            else if (niz [i] == b) cntb++;
        }
        int kol = min(cnta, cntb);
        int preba = 0, prebb = 0;
        printf("%d\n", n - kol * 2);
        for (int i = 0; i < n; i++)
        {
            if (niz [i] == a && preba < kol) {preba++; printf("%d ", (a + b) / 2);}
            else if (niz [i] == b && prebb < kol) {prebb++; printf("%d ", (a + b) / 2);}
            else printf("%d ", niz [i]);
        }
    }
    else
    {
        mini = min(min(a, b), c);
        maxi = max(max(a, b), c);
        for (int i = 0; i < n; i++)
        {
            if (niz [i] == mini) l++;
            else if (niz [i] == maxi) r++;
            else m++;
        }
        if ((a == mini || b == mini) && (a == maxi || b == maxi)) sred = c;
        else if ((a == mini || c == mini) && (a == maxi || c == maxi)) sred = b;
        else sred = a;
        //cout << l << " " << r << " " << m << endl;
        if (min(l, r) > m / 2)
        {
            int brl = 0;
            int brr = 0;
            int kolko = min(l, r);
            printf("%d\n", n - kolko * 2);
            for (int i = 0; i < n; i++)
            {
                if (niz [i] == mini && brl < kolko)
                {
                    brl++;
                    printf("%d ", sred);
                }
                else if (niz [i] == maxi && brr < kolko)
                {
                    brr++;
                    printf("%d ", sred);
                }
                else
                {
                    printf("%d ", niz [i]);
                }
            }
        }
        else
        {
            printf("%d\n", n - (m / 2) * 2);
            int br = 0;
            int kolko = (m / 2) * 2;
            for (int i = 0; i < n; i++)
            {
                if (niz [i] == sred && br < kolko)
                {
                    if (br % 2 == 0)
                    {
                        printf("%d ", mini);
                    }
                    else
                    {
                        printf("%d ", maxi);
                    }
                    br++;
                }
                else
                {
                    printf("%d ", niz [i]);
                }
            }
        }
    }
    return 0;
}