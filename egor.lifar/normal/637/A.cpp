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

int n;
int a[1001];
int t[1000001], last[1000001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[a[i]]++;
        last[a[i]] = i;
    }
    int g = -1;
    for (int i = 1; i <= 1000000; i++) {
        if (g == -1) {
            g = i;
            continue;
        }
        if (t[g] < t[i]) {
            g = i;
            continue;
        }
        if (t[g] == t[i] && last[g] > last[i]) {
            g = i;
            continue;
        }
    }
    cout << g << endl;
    return 0;
}