#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

ld xa,ya,xb,yb;
int n,ans;
ld A[999], B[999], C[999];

int main()
{
    cin >> xa >> ya >> xb >> yb;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i];
    }
    for (int i = 0; i < n; ++i) {
        if ((A[i] * xa + B[i] * ya + C[i] > 0 && A[i] * xb + B[i] * yb + C[i] < 0) ||
            (A[i] * xa + B[i] * ya + C[i] < 0 && A[i] * xb + B[i] * yb + C[i] > 0))
                ++ans;
    }
    cout << ans;

    return 0;
}