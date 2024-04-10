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
int a, b;

int main()
{
    cin >> n;
    FOR (i,0,n)
    {
        int x;
        cin >> x;
        if (x == 1) a++;
        else b++;
    }
    int ans = min(a,b);
    cout << ans + (a-ans)/3;
}