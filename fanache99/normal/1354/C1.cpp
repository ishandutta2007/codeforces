#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const long double PI = acos(-1);

int main() {
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        long double angle = 2 * PI / (4 * n);
        long double r = 1 / (2 * tan(angle));
        cout << fixed << setprecision(12) << 2 * r << "\n";
    }
    return 0;
}