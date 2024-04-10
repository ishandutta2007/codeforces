#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n, a, b;
int ans[100001];


int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++) {
        int r;
        cin >> r;
        ans[r] = 1;
    }
    for (int i = 0; i < b; i++) {
        int r;
        cin >> r;
        if (ans[r] == 0) {
            ans[r] = 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i + 1] << ' ';
    }
    cout << endl;
    return 0;
}