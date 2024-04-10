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
#include <cstring>
#include <cmath>


using namespace std;


int n;
int x[200001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    sort(x, x + n);
    int a = 1000000000;
    for (int i = 0; i <= n - n / 2 - 1; i++) {
        a = min(a, x[i + n / 2] - x[i]);
    }
    cout << a << endl;
    return 0;
}