#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

int m, n;

int main()
{
    cin >> n >> m;
    if (n > 30)
    {
        cout << m;
        return 0;
    }
    LL g = 1;
    FOR (i,0,n) g *= 2;
    cout << m%g<<endl;
}