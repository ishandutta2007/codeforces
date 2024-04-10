#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;



int n;
int a[1001];


int main() {
    cin >> n;
    bool b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            b = 1;
        }
    }
    if (b) {
        cout << -1 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}