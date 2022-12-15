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

int n, a;
int h[200000];
int num[200000];

int main()
{
    cin>> n;
    h[0] = 0;
    num[h[0]]++;
    FOR (i,1,n)
    {
        cin >> a;
        a--;
        h[i] = h[a]+1;
        num[h[i]]++;
    }
    int ans = 0;
    FOR (i,0,n)
        ans += num[i]%2;
    cout << ans;
    return 0;
}