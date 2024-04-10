#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int n, m, k;

vector <int> svi;

vector <int> najv;

int rj;

int main()
{
    cin >> n >> m >> k;
    int x;
    REP(i, 0, n)
    {
        scanf("%d", &x);
        svi.push_back(x);
    }
    rj = svi[svi.size() - 1] - svi[0] + 1;
    REP(i, 0, n - 1)
    {
        najv.push_back(svi[i + 1] - svi[i] - 1);
    }
    sort(najv.begin(), najv.end());
    reverse(najv.begin(), najv.end());
    REP(i, 0, k - 1)
    {
        if(najv.size() > i)
        {
            rj -= najv[i];
        }
        else break;
    }
    cout << rj << endl;
    return 0;
}