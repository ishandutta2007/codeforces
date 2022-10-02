#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int n, k;
int a[100001];


int main() {
    cin >> n >> k;
    k = min(k, n / 2);
    long long sum = 1LL * (n - k) * k + 1LL * k * (n - 2 * k) + 1LL * k * (k - 1LL);
    cout << sum << endl;
    return 0;
}