#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int a;
int sum = 0;

int main() {
    cin >> a;
    for (int i = 2; i < a; ++i) {
        for (int b = a; b; b /= i) {
            sum += b % i;
        }
    }
    int denom = a - 2;
    int g = __gcd(sum, denom);
    sum /= g;
    denom /= g;
    cout << sum << '/' << denom << endl;
    return 0;
}