#include <bits/stdc++.h>
using namespace std;

int sati, minute, h, d, c, n, noveminute;
double nova, rj;

int main()
{
    scanf("%d %d", &sati, &minute);
    scanf("%d %d %d %d", &h, &d, &c, &n);
    nova = (double) 0.8 * c;
    if (h % n == 0) rj = h / n * c;
    else rj = h / n * c + c;
    noveminute = 20 * 60 - sati * 60 - minute;
    if (noveminute <= 0)
    {
        if (h % n == 0)
        {
            rj = h / n * nova;
        }
        else rj = h / n * nova + nova;
    }
    else
    {
        if ((h + noveminute * d) % n == 0)
        {
            rj = min(rj, (h + noveminute * d) / n * nova);
        }
        else
        {
            rj = min(rj, (h + noveminute * d) / n * nova + nova);
        }
    }
    cout << rj;
    return 0;
}