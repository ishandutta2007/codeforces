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
int t[10001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (t[i] != t[j] && t[j] != t[k] && t[k] - t[i] <= 2) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;   
}