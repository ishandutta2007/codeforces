#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;

int n;
int sn [maxn];
int t [maxn];
vector <long long int> sum;
vector <long long int>::iterator it;
int fen [maxn];
long long int pos [maxn];

void ubaci(int poz, int kolko)
{
    for (int feni = poz; feni < maxn; feni += feni&-feni)
    {
        fen [feni] += kolko;
    }
    return;
}

int get(int poz)
{
    int ret = 0;
    for (int feni = poz; feni > 0; feni -= feni&-feni)
    {
        ret += fen [feni];
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sn [i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t [i]);
    }
    sum.push_back((long long) t [0]);
    for (int i = 1; i < n; i++)
    {
        sum.push_back((long long) sum [i - 1] + t [i]);
    }
    for (int i = 0; i < n; i++)
    {
        long long int novi = (long long) sn [i] + ((i == 0) ? 0 : sum [i - 1]);
        it = upper_bound(sum.begin(), sum.end(), novi);
        if (it == sum.end())
        {
            ubaci(i + 1, 1);
            continue;
        }
        int ind = it - sum.begin();
        ubaci(i + 1, 1);
        ubaci(ind + 1, -1);
        pos [ind] += (long long) novi - ((ind == 0) ? 0 : sum [ind - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", (long long) ((long long) get(i + 1) * t [i]) + pos [i]);
    }
    return 0;
}