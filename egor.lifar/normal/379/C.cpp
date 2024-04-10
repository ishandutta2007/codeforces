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
pair <int, int> a[300000];
int c[300000];


int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int b;
        cin >> b;
        a[i] = make_pair(b, i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if(a[i].first > c[a[i - 1].second]) {
            c[a[i].second] = a[i].first;
        }else {
            c[a[i].second] = c[a[i - 1].second] + 1;
        }

    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}