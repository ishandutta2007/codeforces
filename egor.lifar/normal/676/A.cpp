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
#include <map>


using namespace std;


int n;
int a[101];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(a[i], a[j]);   
            int l = 0;
            int r = 0;
            for (int k = 0; k < n; k++) {
                if (a[k] == 1) {
                    l = k;
                }
                if (a[k] == n) {
                    r = k;
                }
            }
            s = max(s, abs(r - l));
            swap(a[i], a[j]);
        }
    }
    cout << s << endl;
    return 0;
}