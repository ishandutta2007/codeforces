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
#include <unordered_map>
#include <vector>
#include <stdio.h>


using namespace std;


int n;


int main() {
    cin >> n;
    if (n % 2 == 1) {
        cout << n / 2 << endl;
        return 0;
    }
    int t = 1;
    while (t * 2 <= n) {
        t *= 2;
    }
    n -= t;
    cout << n / 2 << endl;
	return 0;
}