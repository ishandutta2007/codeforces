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

unsigned long long n, m;

int main()
{
    int n, k;
    int ans = 200;
    cin >> n >> k;
    FOR (i,0,n)
    {
        int a;
        cin >> a;
        if (k%a == 0)
        {
            ans = min(ans,k/a);
        }
    }
    cout << ans;
}