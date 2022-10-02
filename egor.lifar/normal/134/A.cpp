#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;


long long a[200000];
vector<long long> v;
long long s = 0;


int main() {
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == (s - a[i]) / (n - 1) &&  (s - a[i]) % (n - 1) == 0) {
            v.push_back(i + 1);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < (long long)v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
	return 0;
}