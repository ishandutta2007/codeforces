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
#include <assert.h>


using namespace std;


int a[20000];
long long d[20000];


int main(){
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (n / i >= 3 && n % i == 0) {
            for (int j = 0; j < i; j++) {
                d[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                d[j % i] += a[j];
            }
            for (int j = 0; j < i; j++) {
                s = max(s, d[j]);
            }
        }
    }
    cout << s << endl;
    return 0;
}