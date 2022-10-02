#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


int n, k;
int a[200001];


int main() {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        swap(a[2 * i - 1], a[2 * i]);
    }
    for (int i = 1; i <= 2 * n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}