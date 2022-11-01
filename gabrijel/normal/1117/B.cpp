#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 200100;

int n, m, k;
int k2;

int a[maxn];

int m1 = -1, m2 = -1;

long long int rj = 0;

int main()
{
    cin >> n >> m >> k;
    k2 = k + 1;
    REP(i, 0, n)
    {
        scanf("%d", &a[i]);
        if(a[i] > m1)
        {
            m2 = m1;
            m1 = a[i];
        }
        else if(a[i] > m2)
        {
            m2 = a[i];
        }
    }
    int kolko = m / k2;
    rj += (long long) kolko * ((long long) k * m1 + m2);
    int ost = m % k2;
    rj += (long long) ost * m1;
    cout << rj << endl;
    return 0;
}