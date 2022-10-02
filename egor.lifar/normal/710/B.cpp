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
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
int a[300001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    if (n % 2 == 1) {
        cout << a[n / 2] << endl; 
    } else {
        cout << a[n / 2 - 1] << endl;
    }
    return 0;
}