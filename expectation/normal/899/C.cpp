#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

LL n;

int main()
{
    cin >> n;
    LL s = n*(n+1)/2;
    if (s%2 == 0)
        cout << "0\n";
    else
        cout << "1\n";
    s /= 2;
    vector<int> u;
    for (LL i = n; i >= 1; i--)
    {
        if (s >= i)
        {
            s -= i;
            u.push_back(i);
        }
    }
    cout << SZ(u)<<" ";
    FOR (i,0,u.size()) cout << u[i]<<" ";
}