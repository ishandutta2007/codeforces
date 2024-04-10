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
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll n,k,d[99];

int main()
{
    d[0] = d[1] = 1;
    for (int i = 2; i < 99; ++i)
        d[i] = d[i-1] + d[i-2];

    cin >> n >> k; --k;
    for (int i = 1; i <= n; ++i) {
        if (k < d[n-i]) cout << i << " ";
        else {
            k -= d[n-i];
            cout << i+1 << " " << i << " ";
            ++i;
        }
    }

    return 0;
}