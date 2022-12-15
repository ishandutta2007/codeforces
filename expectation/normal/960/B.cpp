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

const LL mod = 1000000007;

string s;
int n;
LL a[100000];
LL b[100000];

int main()
{
    int k,k2;
    cin >> n >> k >> k2;
    k += k2;
    FOR (i,0,n) cin >> a[i];
    FOR (i,0,n) cin >> b[i];
    FOR (i,0,k)
    {
        int pos = 0;
        FOR (i,1,n)
        {
            if (abs(a[i]-b[i]) > abs(a[pos]-b[pos]))
                pos = i;
        }
        if (a[pos] > b[pos]) a[pos]--;
        else a[pos]++;
    }
    LL res = 0;
    FOR (i,0,n) res += (a[i]-b[i])*1LL*(a[i]-b[i]);
    cout << res;
}