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

int n, num[200000];
int mx = -1, a;

int main()
{
    cin >> n;
    FOR (i,0,n)
    {
        cin >> a;
        num[a]++;
    }
    int ok = 0;
    FOR (i,0,100000+7)
    if (num[i]%2==1) ok = 1;
    if (ok) cout << "Conan";
    else cout << "Agasa";
}