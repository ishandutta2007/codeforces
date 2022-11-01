#include <bits/stdc++.h>
using namespace std;

double rj = -100;
bool z = 0;
int n, u, prvi, drugi;
vector <int> svi;
vector <int>::iterator it;

int main()
{
    int x;
    scanf("%d%d", &n, &u);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        svi.push_back(x);
    }
    prvi = svi [0];
    drugi = svi [1];
    for (int i = 2; i < svi.size(); i++)
    {
        if (svi [i] - prvi <= u) {z = 1; break;}
        prvi = drugi;
        drugi = svi [i];
    }
    if (!z)
    {
        printf("-1");
        return 0;
    }
    prvi = svi [0];
    drugi = svi [1];
    for (int i = 2; i < svi.size(); i++)
    {
        it = upper_bound(svi.begin(), svi.end(), u + prvi);
        it--;
        if (*it >= svi [i]) if ((double) ((double) *it - drugi) / ((double) *it - prvi) > rj) rj = (double) ((double) *it - drugi) / ((double) *it - prvi);
        prvi = drugi;
        drugi = svi [i];
    }
    cout << fixed << setprecision(10) << rj;
    return 0;
}