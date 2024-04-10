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
int a[1001];
int b[1001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        int t1 = 0;
        for (int j = i; j < n; j++) {
            t = t | a[j];
            t1 = t1 | b[j];
            sum = max(sum, t + t1);
        }
    }
    cout << sum << endl;
    return 0;
}