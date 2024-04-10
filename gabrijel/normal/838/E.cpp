#include <bits/stdc++.h>
using namespace std;

#define double long double //!

const int maxn = 2600;

int n, xu, yu;

double dp [2] [maxn] [maxn];

double rj = 0;

struct tocka
{
    int x, y;

    tocka(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

double dist(tocka A, tocka B)
{
    return (double) sqrt((double) (A.x - B.x) * (A.x - B.x) + (double) (A.y - B.y) * (A.y - B.y));
}

vector <tocka> sve;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &xu, &yu);
        xu += 1e9;
        yu += 1e9;
        sve.push_back(tocka(xu, yu));
    }

    int novi, sljed, pred;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            novi = i + j;
            if (novi >= n) novi -= n;
            if (i == 0)
            {
                dp [0] [j] [novi] = 0;
                dp [1] [j] [novi] = 0;
            }
            else if (i == 1)
            {
                dp [0] [j] [novi] = dist(sve [j], sve [novi]);
                dp [1] [j] [novi] = dist(sve [j], sve [novi]);
            }
            else
            {
                sljed = j + 1;
                pred = novi - 1;
                if (pred < 0) pred += n;
                if (sljed >= n) sljed -= n;
                dp [0] [j] [novi] = max(dp [1] [sljed] [novi] + dist(sve [j], sve [novi]), dp [0] [sljed] [novi] + dist(sve [j], sve [sljed]));
                dp [1] [j] [novi] = max(dp [1] [j] [pred] + dist(sve [pred], sve [novi]), dp [0] [j] [pred] + dist(sve [j], sve [novi]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        rj = max(rj, max(dp [0] [i] [(i - 1) < 0 ? i - 1 + n : i - 1], dp [1] [i] [(i - 1) < n ? i - 1 + n : i - 1]));
    }
    cout << fixed << setprecision(12) << rj << endl;
    return 0;
}