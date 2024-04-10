#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;

int n;

int main() {    
    cin >> n;
    map<long long, int> m;
    long long sum = 0;
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sum += a;
        m[sum]++;
        ans = min(ans, n - m[sum]);
    }
    cout << ans << endl;
    return 0;
}