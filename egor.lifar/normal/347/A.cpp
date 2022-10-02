#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;


int n;
int a[10000];
int b[10000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    swap(a[0], a[n - 1]);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}