#include <bits/stdc++.h>
using namespace std;

vector <int> du;
int n, l, x, y;
bool muski = 0, zenski = 0;

int main()
{
    int neki, maks;
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &neki);
        du.push_back(neki);
    }
    int ind1 = 0, ind2 = 0;
    while (ind2 < n)
    {
        if (du [ind2] - du [ind1] == x)
        {
            zenski = 1;
            break;
        }
        else if (du [ind2] - du [ind1] < x)
        {
            ind2++;
        }
        else
        {
            ind1++;
        }
    }
    ind1 = 0; ind2 = 0;
    while (ind2 < n)
    {
        if (du [ind2] - du [ind1] == y)
        {
            muski = 1;
            break;
        }
        else if (du [ind2] - du [ind1] < y)
        {
            ind2++;
        }
        else
        {
            ind1++;
        }
    }
    if (muski && zenski)
    {
        printf("0");
        return 0;
    }
    if (muski)
    {
        printf("1\n%d", x);
        return 0;
    }
    if (zenski)
    {
        printf("1\n%d", y);
        return 0;
    }
    maks = du [n - 1];
    for (int i = 0; i < n; i++)
    {
        int novi = du [i] + y;
        if (novi > maks) break;
        if (binary_search (du.begin(), du.end(), novi - x) || binary_search (du.begin(), du.end(), novi + x))
        {
            printf("1\n%d", novi);
            return 0;
        }
    }
    reverse(du.begin(), du.end());
    for (int i = 0; i < n; i++)
    {
        int novi = du [i] - y;
        if (novi < 0) break;
        if (binary_search (du.rbegin(), du.rend(), novi - x) || binary_search (du.rbegin(), du.rend(), novi + x))
        {
            printf("1\n%d", novi);
            return 0;
        }
    }
    printf("2\n%d %d", x, y);
    return 0;
}