#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;

int n;

int a[maxn];

int maxi = -1;
int rj = 0;
int trbr = 0;

int main()
{
    cin >> n;
    REP(i, 0, n)
    {
        scanf("%d", &a[i]);
        maxi = max(maxi, a[i]);
    }
    REP(i, 0, n)
    {
        if(a[i] == maxi)
        {
            trbr++;
        }
        else
        {
            trbr = 0;
        }
        rj = max(rj, trbr);
    }
    cout << rj << endl;
    return 0;
}