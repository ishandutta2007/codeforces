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

LL a, b;
LL x, y, z;

int main()
{
    cin >> a >> b;
    cin >> x >> y >> z;
    LL c = 2*x+y, d = y + 3*z;
    cout << max(0LL,c-a)+max(0LL,d-b);
}